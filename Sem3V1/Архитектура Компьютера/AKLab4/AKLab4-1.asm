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
     
    message1 db "Enter x: ", 0  
    message2 db "Enter y: ", 0
    error db "Error: Division by zero!", 0 
    firstStr db 100 dup (" ")
    secondStr db 100  dup (" ")                       
    number1 dd 0
    number2 dd 0
    inputBuffer db 1000 dup (' ')  
    ent db 10
    
.data? 
 	min dd ?
 	max1 dd ? 
 	max dd ?
 	x2 dd ?
 	res dd ?
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
   	             
; max(x2,max(y,10)) / min(x, y)
   	 	 
   	 
;max(10,y)
	mov EAX, 10
	mov EBX, number2 
	
	cmp EAX, EBX 
	JGE Metka1        
		mov max1, EBX         
		JMP Metka2
Metka1:
	mov max1, EAX	   

Metka2: 	
;min(x,y)	
	mov EAX, number1
	mov EBX, number2
	
	cmp EAX, EBX
	JLE Metka3
		mov min, EBX
		JMP Metka4
Metka3:
	mov min, EAX       
Metka4:
;x^2
	mov EAX, number1
	mov EBX, number1
	mul EBX
	mov x2, EAX
				      
;max(x2, max1)
       mov EAX, x2
       mov EBX, max1
       
       cmp EAX, EBX  
       JGE Metka5
       		mov max, EBX
       		JMP Metka6
Metka5:
	mov  max, EAX
       		

Metka6:	
    	cmp max, 0
 	JE err
	
	mov EAX, max
       	cdq
	mov EBX, min
	idiv EBX
	mov res, EAX     		
       
        push offset res
	push EAX
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
	  
 		JMP Metka
	
err:    
	push offset error
	call lstrlen
	
 	push NULL
     	push offset numberOfChars
        push EAX
        push offset error 
        push outputHandle         
        call WriteConsole 		 
	
Metka:	        
	push 3000h
	call Sleep
	
	push 0
	call ExitProcess

end entryPoint