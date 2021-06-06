.486
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include windows.inc
    include user32.inc
    include kernel32.inc  
    include masm32.inc  

    includelib user32.lib
    includelib kernel32.lib  
    includelib masm32.lib

; #########################################################################
.data                                                                   
	result db 200 dup (0)
        template db "%d ", 0    ; Образец строки для одного целого числа   
        newLine dd 0AH
.data?
      	mass dd 10 dup (?)   
	numberOfChars dd ?  
	outputHandle dd ? 
	
.code

arrayToStr:
        ; Стандартный пролог функции
        push EBP
        mov EBP, ESP
        ; начало цикла - пока есть необработанные элементы
        cycle:
                cmp dword ptr [ EBP + 16 ], 0
                je endFunction
                ; Формирование текстового представления целого числа
                mov EAX, [ EBP + 12 ]         ; указатель на очередное число
                push [ EAX ]                  ; целое число (элемент массива),
                                              ; преобразуемое в строку
                push offset template          ; шаблон строки, в который
                                              ; подставляются значения
                push [ EBP + 8 ]              ; адрес буфера для размещения
                                              ; итоговой строки
                call wsprintf                 ; в EAX записывается число символов,
                                              ; записанных в буфер
                add ESP, 12                   ; выровняем стек
                ; Подготовка к следующему числу
                add [ EBP + 8 ], EAX          ; рассчитаем адрес строки для
                                              ; следующего числа
                add dword ptr [ EBP + 12 ], 4 ; перемещаем указатель на следующий
                                              ; элемент массива
                dec dword ptr [ EBP + 16 ]    ; уменьшаем счетчик
        ; конец цикла
        jmp cycle
        endFunction:
        ; Стандартный эпилог функции
        pop EBP
; Выйти и выровнять стек
ret 12 

inArray:  ; void inArray(int* mass, int a0, int d, int count)  
	; Стандартный пролог функции
        push EBP           
        mov EBP, ESP        
        
	mov ecx, 0                ; счетчик (индекс)
	mov ebx, [ ebp + 12 ]       ; 0-ой элемент прогрессии      
	mov esi, [ ebp + 16 ]       ; в esi разность прогрессии
	startCycle:
		cmp ecx, [ ebp + 20 ]      ; проверяем счетчик
		je endCycle                
		mov eax, [ ebp + 8 ]       ;  в eax указатель на массив
		mov [ eax + ecx * 4 ], ebx    ; записываю i-ый элемент массива
		add ebx, esi  
		inc ecx
		jmp startCycle		
	endCycle: 
	pop EBP	
ret 16  

sumArray:  ; int sumArray(int* mass, int count)     результат в EAX
	push EBP
        mov EBP, ESP
        mov ecx, 0                ; счетчик (индекс)
        mov eax, 0                ; сумма изначально = 0
	startCycle2:
		cmp ecx, [ ebp + 12 ]      ; проверяем счетчик
		je endCycle2                
		mov ebx, [ ebp + 8 ]       ;  в ebx указатель на массив
		add eax, [ ebx + ecx * 4 ]    ; добавляю i-ый элемент массива 
		inc ecx
		jmp startCycle2		
	endCycle2: 
	pop EBP	
ret 8    

handleArray:  ; void handleArray(int* mass, int count)   
	push EBP
        mov EBP, ESP
        mov ecx, 0                ; счетчик (индекс)
	startCycle3:
		cmp ecx, [ ebp + 12 ]      ; проверяем счетчик
		je endCycle3                
		mov ebx, [ ebp + 8 ]       ;  в ebx указатель на массив 
		mov edx, 0
		mov eax, [ ebx + ecx * 4 ]    ; в eax i-ый элемент массива 
		mov esi, 4 
		div esi
		cmp edx, 0              ; если остаток от деления на 4 не равен 0, то продолжаем цикл, если равен 0, то уменьшаем в 4
		jne continueCycle
		mov [ ebx + ecx * 4 ], eax
	continueCycle:	
		inc ecx
		jmp startCycle3		
	endCycle3: 
	pop EBP	
ret 8      
        

entryPoint:  
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX   
	      
	push 10        ;ebp+20
	push 43        ;ebp+16
	push 18        ;ebp+12
	push offset mass ;ebp+8
	call inArray   
	;ebp+4
	push 10          ;ebp+16
        push offset mass ;ebp+12
        push offset result ;ebp+8
        call arrayToStr
            
        push offset result
 	call lstrlen 
	
	push NULL                 
	push offset numberOfChars
	push eax
	push offset result
	push outputHandle         
	call WriteConsole   
;********************************
	push NULL                 
	push offset numberOfChars
	push 1                   
	push offset newLine
	push outputHandle         
	call WriteConsole
;********************************	
	
	push 10             ;ebp+12
	push offset mass    ;ebp+8
	call sumArray
	
	push offset result
	push eax
	call dwtoa
	         
	push offset result
 	call lstrlen
	           
	push NULL                 
	push offset numberOfChars
	push eax
	push offset result
	push outputHandle         
	call WriteConsole 
	
;********************************
	push NULL                 
	push offset numberOfChars
	push 1                   
	push offset newLine
	push outputHandle         
	call WriteConsole
;********************************  

       	push 10              ;ebp+12
	push offset mass       ;ebp+8
	call handleArray
	  
   	push 10
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
	 
;********************************
	push NULL                 
	push offset numberOfChars
	push 1                   
	push offset newLine
	push outputHandle         
	call WriteConsole
;********************************	
	
	push 10
	push offset mass
	call sumArray
	
	push offset result
	push eax
	call dwtoa
	         
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