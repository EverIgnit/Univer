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
    a dd 0
    b dd 0 
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
                                                                                              
   	mov a, EAX  
	
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
    
   	mov b, EAX           
   	
	cmp firstStr[0], '-' 
	je neg1 
		jmp comp2
neg1:
	neg a
	 
comp2:
	cmp secondStr[0], '-'
	je neg2
 		jmp endcmp
neg2:
	neg b

endcmp:	            
    	
   	cmp a, 0
   	je Res
   	
   	cmp b, 0
   	jne PreCicle

Res:
	mov res, 0	
	jmp Exit     
PreCicle:
	mov EAX, 0	
Cicle:	
	cmp b, 1
	je FormRes
		add EAX, a
		add a, EAX
		dec b
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