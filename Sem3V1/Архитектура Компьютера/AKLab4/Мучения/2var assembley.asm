.486
    .model flat, stdcall
    option casemap :none   
    
    include windows.inc
    include user32.inc
    include kernel32.inc
    include masm32.inc
    
    includelib masm32.lib
    includelib user32.lib
    includelib kernel32.lib     
    
.data
     
    message1 db "Enter an integer: ", 0  
    message2 db "Enter a non-negative exponent: ", 0
    err db "Error: Non-negative exponent", 0                   
    number1 dd 0
    number2 dd 0 
    ent db 10 
    
.data? 
 	n dd ? 
 	min2 dd ?
 	res dd ? 
 	firstStr db 100 dup (?)
    	secondStr db 100  dup (?)
    	inputBuffer db 1000 dup (?)       
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
	
	
	push offset message1
   	call lstrlen
                      
    	push NULL
  	push offset numberOfChars
   	push EAX
   	push offset message1
    	push outputHandle         
    	call WriteConsole
    
  	push NULL
	push offset numberOfChars
	push 100
	push offset firstStr
	push inputHandle   
	call ReadConsole 
			
	mov EDX, offset firstStr
	mov EAX, numberOfChars           
 	mov byte ptr [ EDX + EAX - 2 ], 0 
 	
 	mov EBX, offset firstStr

	push EBX
   	call atodw
                                                                                              
   	mov number1, EAX  

Negative:   	
   	push offset message2
   	call lstrlen
   	
   	push NULL
  	push offset numberOfChars
   	push EAX
   	push offset message2
    	push outputHandle         
    	call WriteConsole  
		
   	push NULL
	push offset numberOfChars
	push 100
	push offset secondStr
	push inputHandle   
	call ReadConsole  
		
	cmp firstStr[0], '-'
	je Error
		jmp M1 
		
Error:
	push offset err
   	call lstrlen
                      
    	push NULL
  	push offset numberOfChars
   	push EAX
   	push offset err
    	push outputHandle         
    	call WriteConsole
	
	jmp Negative
	 
M1:	    
        mov EDX, offset secondStr
	mov EAX, numberOfChars           
 	mov byte ptr [ EDX + EAX - 2 ], 0 
 	
 	mov EBX, offset secondStr

	push EBX
   	call atodw
    
   	mov number2, EAX  
   	
 	mov EBP, 1 
  	mov ESI, number1
   		
   	cmp number2, 0
   	je Res  
   		mov EBX, number2
   		jmp M2
Res:
	mov EBP, 1	
	jmp Exit

M2:   	
	mov EDI, 2 
       	cmp EBX, 0
       	je Exit 
       		mov EAX, EBX
       		div EDI
		cmp EDX, 1
		je N   
			jmp N1
			N1:
				mov EAX, ESI
				mul ESI
				mov ESI, EAX
				mov EAX, EBX
				div EDI
				mov EBX, EAX
		                jmp M2
	N:
		mov EAX, EBP
		mul ESI
		mov EBP, EAX 
		jmp N1		
    			      		
Exit:     	   
        push offset res
        push EBP
        call dwtoa
        
        push offset res
        call lstrlen
        
        push NULL
        push offset numberOfChars
        push EAX
        push offset res
        push outputHandle
        call WriteConsole
        
 	push NULL                 
	push offset numberOfChars 
	push 1
	push offset ent
	push outputHandle         
	call WriteConsole 
	
	JMP entryPoint        
		 		        
	push 3000h
	call Sleep
	
	push 0
	call ExitProcess

end entryPoint