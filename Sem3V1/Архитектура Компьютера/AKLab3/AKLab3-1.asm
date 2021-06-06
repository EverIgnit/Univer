.486
.model flat, stdcall
option casemap :none 
include windows.inc
include kernel32.inc
includelib kernel32.lib 
include masm32.inc
includelib masm32.lib

.data
	inputA db "Input a: ", 0     
	inputB db "Input b: ", 0

.data?  
	firstNumber db ?
	secondNumber db ?
	sum db ?
	raz db ?
	pr db ?
	del db ? 
	ost db ?  
	n  db ?
	inputHandle dd ?
	outputHandle dd ?
	numberOfChars dd ?

.code
entryPoint:
	
	push STD_INPUT_HANDLE     
	call GetStdHandle         
	mov inputHandle, EAX      
	
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
	push 100
	push offset firstNumber 
	push inputHandle
	call ReadConsole       
	
       	mov EDX, offset firstNumber      ;сохранение адреса прочитанной строки
       	mov EAX, numberOfChars           ;сохранение длины прочитанной строки
       	mov byte ptr [ EDX + EAX - 2], 0 ;запись завершающего 0 в конец строки, при этом вычитание 2 из адреса необходимо для 
					 ;отбрасывания символов с кодами 13 и 10 в конце строки, помещаемых в буфер после нажатия Enter
       	push offset firstNumber
	call atodw
	mov EBX, EAX                
	
	;вывод сообщения о вводе числа B
	push NULL
	push offset numberOfChars
	push 9
	push offset inputB
	push outputHandle
	call WriteConsole
	
       	push NULL                 
	push offset numberOfChars 
	push 100                   
	push offset secondNumber
	push inputHandle         
	call ReadConsole   
       	
      	mov EDX, offset secondNumber     ;сохранение адреса прочитанной строки
       	mov EAX, numberOfChars           ;сохранение длины прочитанной строки
       	mov byte ptr [ EDX + EAX - 2], 0 ;запись завершающего 0 в конец строки, при этом вычитание 2 из адреса необходимо для 
					 ;отбрасывания символов с кодами 13 и 10 в конце строки, помещаемых в буфер после нажатия Enter	                   
	
	push offset secondNumber
	call atodw     	
	mov EDX, EAX     
	
;--------------------Сумма----------------------------------- 
	mov EAX, 0
 	mov EAX, EBX
  	add EAX, EDX
   	push offset sum
    	push EAX
     	call dwtoa

	push offset sum
 	call lstrlen

        push NULL
     	push offset numberOfChars
	push EAX
	push offset sum
  	push outputHandle
   	call WriteConsole       

;---------------------Разность-------------------------------- 
;	mov EAX, 0  
;	mov EAX, EBX
;	sub EAX, EDX
;	push offset raz
;	push EAX
;	call dwtoa
	
;	push offset raz
;	call lstrlen
	
;     	push NULL
;	push offset numberOfChars
;	push EAX
;	push offset raz
;	push outputHandle
;	call WriteConsole    
	 
;---------------------Произведение-------------------------------- 
;	mov EAX, 0  
;	mov EAX, EBX
;	imul EDX
;	push offset pr
;	push EAX
;	call dwtoa
;	
;	push offset pr
;	call lstrlen
;	
;      	push NULL
;	push offset numberOfChars
;	push EAX
;	push offset pr
;	push outputHandle
;	call WriteConsole        
;	
;---------------------Частное-------------------------------- 
;	mov EAX, 0  
;	mov EAX, EBX 
;	mov ECX, EDX
;	mov EDX, 0
;	div ECX
;	push offset del
;	push EAX
;	call dwtoa 
;	
;	push offset del
;	call lstrlen
;	
;      	push NULL
; 	push offset numberOfChars
;	push EAX
;	push offset del
;	push outputHandle
;   	call WriteConsole  
   	
;---------------------Завершение=----------------------------   	
        
	push 3000h
	call Sleep
	
	push 0
	call ExitProcess

end entryPoint