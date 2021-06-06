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

.data              
	inputA db "Input a: ", 0     
	inputB db "Input b: ", 0
	;newLine db 0AH        
.data?
	a dd ?
	b dd ?      
	result dd ?  
	numberOfChars dd ?  
	inputHandle dd ?
	outputHandle dd ? 

.code
entryPoint:     

	push STD_INPUT_HANDLE     ; передача параметра в функциі
	call GetStdHandle         ; вvзов системной функции
	mov inputHandle, EAX      ; сохранение результата функции
	
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX
	  
	;вывод сообщения о вводе числа А
	push NULL
	push offset numberOfChars
	push 9
	push offset inputA
	push outputHandle
	call WriteConsole
	
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset a
    	push inputHandle
     	call ReadConsole 
     	
     	mov EDX, offset a
	mov EAX, numberOfChars           
	mov byte ptr [ EDX + EAX - 2 ], 0  
	
	push offset a
	call atodw 	    
	mov a, EAX        
         
	;вывод сообщения о вводе числа B
	push NULL
	push offset numberOfChars
	push 9
	push offset inputB
	push outputHandle
	call WriteConsole
	
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset b
    	push inputHandle
     	call ReadConsole 
     	
     	mov EDX, offset b
	mov EAX, numberOfChars           
	mov byte ptr [ EDX + EAX - 2 ], 0   
	
	push offset b
	call atodw 
	
	mov b, EAX   	 
                
	mov result, 0
	                                      
	mov ESI, 1
Cycle:
	cmp ESI, b
	ja Exit
	   	mov EAX, a
		add result, EAX
		inc ESI
		jmp Cycle
Exit:
	
	push offset result
        push result
        call dwtoa   
        
        push offset result
 	call lstrlen 
	
	push NULL                 
	push offset numberOfChars
	push EAX
	push offset result
	push outputHandle         
	call WriteConsole  
	
 	push 30000h
	call Sleep
	push 0
	call ExitProcess

end entryPoint 	