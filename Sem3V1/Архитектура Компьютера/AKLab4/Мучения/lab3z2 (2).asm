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
    message2 db "Enter another one: ", 0                  
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
		  
        mov EDX, offset secondStr
	mov EAX, numberOfChars           
 	mov byte ptr [ EDX + EAX - 2 ], 0 
 	
 	mov EBX, offset secondStr

	push EBX
   	call atodw
    
   	mov number2, EAX        
   	
   	
   	

	cmp firstStr[0], '-' 
	je neg1 
		jmp comp2
neg1:
	neg number1
	 
comp2:
	cmp secondStr[0], '-'
	je neg2
 		jmp endcmp
neg2:
	neg number2 

endcmp:	            
    	
   	cmp number1, 0
   	je Res
   	
   	cmp number2, 0
   	jne CicleBeg

Res:
	mov res, 0	
	jmp Exit  
CicleBeg:  
	mov EAX, number2
	mov ECX, number1
	dec ECX
Cicle:	
	cmp ECX, 1
	je FormRes
		add EAX, number2
		dec ECX
		jmp Cicle
FormRes:
	mov res, EAX
Exit:     	   
        push offset res
        push EBP
        call dwtoa
                 
        cmp firstStr[0], '-'
	neg res
	cmp secondStr[0], '-'
	neg res
        
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