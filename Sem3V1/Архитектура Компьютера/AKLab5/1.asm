.486
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include windows.inc
    include user32.inc
    include kernel32.inc

    includelib user32.lib
    includelib kernel32.lib

; #########################################################################
.data      
	mass dd 20 dup (2)  
	sizeArray dd 20     
	result db 200 dup (0)
        template db "%d ", 0    ; ќбразец строки дл€ одного целого числа 
.data?
       ;	result db ?     
	numberOfChars dd ?  
	outputHandle dd ? 
	
.code    
;       buffer ( [EBP + 8] )  - указатель на строку, в которой будет
;                               формироватьс€ представление массива
;       array  ( [EBP + 12] ) - указатель на массив
;       size   ( [EBP + 16] ) - количество элементов в массиве
; ограничение размера передаваемых данных размерами регистра. ≈сли размер данных больше 8,16 и 32 бит, то передачу произвести нельз€
;+8,+12,+16 - смещение
arrayToStr:
        ; —тандартный пролог функции
        push EBP   ; загружаем в стек
        mov EBP, ESP ; esp - начало стека
        ; начало цикла - пока есть необработанные элементы
        cycle:
                cmp dword ptr [ EBP + 16 ], 0
                je endFunction
                ; ‘ормирование текстового представлени€ целого числа
                mov EAX, [ EBP + 12 ]         ; указатель на очередное число
                push [ EAX ]                  ; целое число (элемент массива),
                                              ; преобразуемое в строку
                push offset template          ; шаблон строки, в который
                                              ; подставл€ютс€ значени€
                push [ EBP + 8 ]              ; адрес буфера дл€ размещени€
                                              ; итоговой строки
                call wsprintf                 ; в EAX записываетс€ число символов,
                                              ; записанных в буфер
                add ESP, 12                   ; выровн€ем стек
                ; ѕодготовка к следующему числу
                add [ EBP + 8 ], EAX          ; рассчитаем адрес строки дл€
                                              ; следующего числа
                add dword ptr [ EBP + 12 ], 4 ; перемещаем указатель на следующий
                                              ; элемент массива
                dec dword ptr [ EBP + 16 ]    ; уменьшаем счетчик
        ; конец цикла
        jmp cycle
        endFunction:
        ; —тандартный эпилог функции
        pop EBP
; ¬ыйти и выровн€ть стек
ret 12   ;выход из функции, 12-количество байт, удал€емых из стека

entryPoint:  
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX        
        
	push sizeArray
        push offset mass 
        push offset result
        call arrayToStr
            
        push offset result
 	call lstrlen 
	
	push NULL                 
	push offset numberOfChars
	push eax
	push offset result
	push outputHandle         
	call WriteConsole  

   
 	push 30000h
	call Sleep
	push 0
	call ExitProcess

end entryPoint 	