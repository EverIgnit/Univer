.486
.model flat, stdcall
option casemap :none ; чувствительность к регистру букв в идентификаторах
include windows.inc
include kernel32.inc
includelib kernel32.lib

.data
	arrA db 255 dup(" ")	 	;хранение переменной a
	arrB db 255 dup(" ")	 	;хранение переменной b
	arrC db 255 dup(" ")	 	;хранение переменной c   
	
	line1_1 db 4 dup (" ") 	                             
	line1_2 db 10,13
	line2 db 0DAH, 12 dup(0C4H), 0BFH, 10, 13
	line3 db 0B3H, 12 dup(0B0H), 0B3H, 10, 13
	line4_1 db 0B3H, 0B0H
	line4_2 db 0B0H, 0B3H, 10, 13       
	line5 db 0B3H, 3 dup(0B0H), 0C9H, 8 dup(0CDH), 0CAH, 3 dup(0CDH), 0BBH, 10, 13
	line6 db 0C0H, 3 dup (0C4H), 0B9H, 12 dup(0B2H), 0BAH, 10, 13
	line7_1 db 4 dup(" "), 0BAH, 0B2H
	line7_2 db 0B2H, 0BAH, 10, 13
	line8 db 4 dup(" "), 0BAH, 12 dup(0B2H), 0BAH, 10, 13
	line9 db 4 dup(" "), 0C8H, 12 dup(0CDH), 0BCH, 10, 13
        
	inputBuffer db 0
	 
.data?
	inputHandle dd ?
	outputHandle dd ?
	
	numberOfChars dd ?

.code
entryPoint:
	
	push STD_INPUT_HANDLE    	 ; передача параметра в функцию
	call GetStdHandle        	 ; вызов системной функции
	mov inputHandle, EAX      	 ; сохранение результата функции
	
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX                   
	
	
         		  ;ввод с консоли символа a
	push offset  numberOfChars
	push 255
	push offset arrA
	push inputHandle
	call ReadConsole
           
	mov EBX, offset arrA
        mov EAX, numberOfChars
        mov byte ptr [ EBX + EAX - 1 ], " " 
        mov byte ptr [ EBX + EAX - 2 ], " "
	                          		;ввод с консоли символа b
	push offset numberOfChars
	push 255
	push offset arrB
	push inputHandle
	call ReadConsole
         
        mov EBX, offset arrB
        mov EAX, numberOfChars
	mov byte ptr [ EBX + EAX - 1 ], " " 
        mov byte ptr [ EBX + EAX - 2 ], " "
           		
	push offset numberOfChars              ;ввод с консоли символа c
	push 255
	push offset arrC
	push inputHandle
	call ReadConsole
	           
	push offset numberOfChars
	push 4
	push offset line1_1
	push outputHandle
	call WriteConsole   
	            
	push offset numberOfChars
	push 10
	push offset arrC
	push outputHandle
	call WriteConsole 
	           
	push offset numberOfChars
	push 2
	push offset line1_2
	push outputHandle
	call WriteConsole
	           
	push offset numberOfChars
	push 16
	push offset line2
	push outputHandle
	call WriteConsole
            
	push offset numberOfChars
	push 16
	push offset line3
	push outputHandle
	call WriteConsole
	      
	push offset numberOfChars
	push 2
	push offset line4_1
	push outputHandle
	call WriteConsole  
	                  
	push offset numberOfChars  
	push 10                 
        push offset arrA
	push outputHandle          
	call WriteConsole
	           
	push offset numberOfChars
	push 4
	push offset line4_2
	push outputHandle
	call WriteConsole 
	           
	push offset numberOfChars
	push 20
	push offset line5
	push outputHandle
	call WriteConsole 
	          
	push offset numberOfChars
	push 20
	push offset line6
	push outputHandle
	call WriteConsole 
	           
	push offset numberOfChars
	push 6
	push offset line7_1
	push outputHandle
	call WriteConsole 
	                            
	push offset numberOfChars  
	push 10                 
        push offset arrB  
	push outputHandle          
	call WriteConsole
	           
	push offset numberOfChars
	push 4
	push offset line7_2
	push outputHandle
	call WriteConsole 
	           
	push offset numberOfChars
	push 20
	push offset line8
	push outputHandle
	call WriteConsole 
	           
	push offset numberOfChars
	push 20
	push offset line9
	push outputHandle
	call WriteConsole
	 
	push 50000
	call Sleep
	
	push 0
	call ExitProcess

end entryPoint