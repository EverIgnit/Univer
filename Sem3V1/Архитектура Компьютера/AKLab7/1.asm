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
	input1 db "Input a number of member of sequence: ", 0                                                           
        newLine db 0AH
.data?       
	n dd ?               
	result dd ?  
	numberOfChars dd ?  
	inputHandle dd ? 
	outputHandle dd ? 
	     
	;jbe если <=
.code   
fibonnachi:                                                              	
	push EBP
 	mov EBP, ESP
	mov eax, [ ebp + 8 ]    ; помещаем в eax - n
	cmp eax, 2              ; если n <= 2 то возвращаем 1
	jbe retBE2              ; иначе входим в рекурсивный блок
           
	mov     eax, [ ebp + 8 ]     ; помещаем в eax - n
	push    ebx                  ; сохраняем в стеке ebx          eax уменьшаем на 1 и заносим в ebx
        dec     eax                  ; уменьшаем на 1
        
        push    eax                  ; в eax записываем n-1
        call    fibonnachi           ; вычисляем (n-1)-ый член 
        
        mov     ebx, eax             ; сохраняем его в ebx
        mov     eax, [ ebp + 8 ]     
        sub     eax, 2 
        
        push    eax                  ; аналогично вычисляем (n-2)-ой член
        call    fibonnachi 
        
        add     eax, ebx             ; n-й член равен сумме двух предыдущих, записываем результат в eax
        pop     ebx                  ; восстанавливаем ebx
        
	jmp return	
retBE2:
	mov eax, 1
return:		     
	pop ebp	      
ret 4	
  
entryPoint:     

	push STD_INPUT_HANDLE 
	call GetStdHandle         
	mov inputHandle, EAX    	
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX
	      
	push NULL                      ;запись в консоль
	push offset numberOfChars
	push 38
	push offset input1
	push outputHandle
	call WriteConsole	
	
	
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset n
    	push inputHandle
     	call ReadConsole 
     	
     	mov edx, offset n
	mov eax, numberOfChars           
	mov byte ptr [ edx + eax - 2 ], 0  
	
	push offset n
	call atodw	    
;*******************************************	
       	push eax
       	call fibonnachi       	
;******************************************* 
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