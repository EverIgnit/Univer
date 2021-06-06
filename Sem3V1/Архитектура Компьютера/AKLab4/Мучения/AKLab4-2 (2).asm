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
	
	cmp EDX + 4, '-'
       	je Exit    
		jg compB
		neg a
		mov mark,-1	 
	
	push offset a
	call atodw 	    
	mov a, EAX        
         
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
compB:			
	cmp b, 0
	je Exit
		jg StartCicle
		neg b	
		neg mark                  
			
		push NULL                 
		push offset numberOfChars
		push 9
		push offset b
		push outputHandle         
		call WriteConsole  
StartCicle:	                                     
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

      







	          
;	cmp inputA[0], '-'
;	neg result
;	cmp inputB[0], '-'
;	neg result
               
;	cmp inputA[0], '-' 
;	je neg1 
;		jmp comp2
;neg1:
;	neg a
;	 
;comp2:
;	cmp inputB[0], '-'
;	je neg2
; 		jmp endcmp
;neg2:
;	neg b
;	
;endcmp:	

	