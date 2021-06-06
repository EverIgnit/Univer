.486
    .model flat, stdcall
    option casemap :none

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
	mark dd 1  
.data?
	a dd ?
	b dd ?      
	result dd ?  
	numberOfChars dd ?  
	inputHandle dd ?
	outputHandle dd ? 

.code
entryPoint:     

	push STD_INPUT_HANDLE   
	call GetStdHandle         
	mov inputHandle, EAX     
	
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX	  

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
;=-=-=-=-=-=-=-=	
	CMP byte ptr a, '-'
	JE deleteminus
	JMP continue1

deleteminus:
	push offset a + 1
	call atodw
	NEG mark
        JMP continue2
continue1:
	push offset a
	call atodw 	       
continue2:	     
	mov a, EAX
;=-=-=-=-=-=-=-=         
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
	
;=-=-=-=-=-=-=-=	
	CMP byte ptr b, '-'
	JE deleteminus_2
	JMP continue1_2

deleteminus_2:
	push offset b + 1
	call atodw
	NEG mark
        JMP continue2_2
continue1_2:
	push offset b
	call atodw 	       
continue2_2:	     
	mov b, EAX
;=-=-=-=-=-=-=-=  	 

	mov result, 0				           	                                     
	mov ESI, 1
Cycle:
	cmp ESI, b
	ja ExitCmp
	   	mov EAX, a
		add result, EAX
		inc ESI
		jmp Cycle
ExitCmp:
	cmp mark, 0
	jg Exit
		neg result	        
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