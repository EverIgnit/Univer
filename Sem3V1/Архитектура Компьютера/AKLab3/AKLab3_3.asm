.486
.model flat, stdcall

option casemap : none

include windows.inc
include kernel32.inc   
include masm32.inc

includelib masm32.lib
includelib kernel32.lib

.data   
      enterA db "enter a: "
      enterB db "enter b: "
      enterC db "enter c: "
      
      buferA db 100 dup (" ")
      buferB db 100 dup (" ")
      buferC db 100 dup (" ")
      myNumber dq 0 
      inputBufer db 0
      perehod db 0ah
.data?
      numberOfChars dd ?
      inputHandle dd ?
      outputHandle dd ? 
      myNumberA dd ?
      myNumberB dd ?
      myNumberC dd ?
      
      resultA dq ?
      resultFirstAdd dq ?
      res dq ?
      result dd ?
.code
main:
      	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX
	   
	
	push STD_INPUT_HANDLE
	call GetStdHandle
	mov inputHandle, EAX  
	
	;---------------------------------
	;вывод сообщения
	push NULL
	push offset numberOfChars
	push 9
	push offset enterA
	push outputHandle
	call WriteConsole 
		
	;ввод числа
	push NULL
	push offset numberOfChars
	push 100
	push offset buferA
	push inputHandle
	call ReadConsole   
	
	;Добавление в конец 0
	mov EDX, offset buferA
	mov EAX, numberOfChars
	mov byte ptr [ EDX + EAX -2 ], 0  
	
	;Преобразование строки в число
       	push offset buferA
	call atodw
	mov myNumberA, EAX
	
	;вывод сообщения
	push NULL
	push offset numberOfChars
	push 9
	push offset enterB
	push outputHandle
	call WriteConsole 
		
	;ввод числа
	push NULL
	push offset numberOfChars
	push 100
	push offset buferB
	push inputHandle
	call ReadConsole      
	
	;Добавление в конец 0
	mov EDX, offset buferB
	mov EAX, numberOfChars
	mov byte ptr [ EDX + EAX -2 ], 0
	
	;Преобразование строки в число
       	push offset buferB
	call atodw
	mov myNumberB, EAX 
	
	;вывод сообщения
	push NULL
	push offset numberOfChars
	push 9
	push offset enterC
	push outputHandle
	call WriteConsole 
		
	;ввод числа
	push NULL
	push offset numberOfChars
	push 100
	push offset buferC
	push inputHandle
	call ReadConsole    
	
	;Добавление в конец 0
	mov EDX, offset buferC
	mov EAX, numberOfChars
	mov byte ptr [ EDX + EAX -2 ], 0
	
	;Преобразование строки в число
       	push offset buferC
	call atodw
	mov myNumberC, EAX
	
	;b делим на 32
	mov EAX, myNumberB
	mov EBX, 32
	div EBX       
        mov myNumberB, EAX  
			
	;Возведение a в 7 степень
	mov EAX, myNumberA
	cdq         
	
	;a2
	mov dword ptr myNumber, EAX 					; myNumber = EDX:EAX
	mov dword ptr myNumber[4], EDX 
	  
	mul EAX 							; EAX = EAX * EAX  
	   				
	mov dword ptr resultA, EAX 					; resultA = EDX:EAX                  
	mov dword ptr resultA[4], EDX
	
	;a3
	mov dword ptr myNumber, EAX 					; myNumber = EDX:EAX
	mov dword ptr myNumber[4], EDX   
	
	mul myNumberA							; EAX = EAX * myNumberA
	
	mov dword ptr resultA, EAX 					; resultA = EDX:EAX                  
	mov dword ptr resultA[4], EDX 
	
	;a6
	mov dword ptr myNumber, EAX 					;myNumber = EDX:EAX
	mov dword ptr myNumber[4], EDX  
	 
	mul EAX; EAX = EAX * EAX    
	
	mov dword ptr resultA, EAX 					; resultA = EDX:EAX                  
	mov dword ptr resultA[4], EDX 
	
	;a7
        mov dword ptr myNumber, EAX 		       			;myNumber = EDX:EAX
	mov dword ptr myNumber[4], EDX  
	
	mul myNumberA	     
					 		;EAX = EAX*myNumberA
	mov dword ptr resultA, EAX 					; resultA = EDX:EAX                  
	mov dword ptr resultA[4], EDX 
	
       	;a7+b/32
       	mov EBX, dword ptr myNumberB 	       	
        add EAX, EBX
        jnc notLabel
        adc EDX, 0 
        
notLabel:       
        
        ;(a7+b/32)/c and (a7+b/32)%c	
	div myNumberC
	add EAX, EDX  	 
	push offset result
	push EAX
	call dwtoa
	
	push offset result
	call lstrlen
	
	push NULL
	push offset numberOfChars
	push EAX
	push offset result
	push outputHandle
	call WriteConsole 
	  	
	push NULL
	push offset numberOfChars
	push 1
	push offset inputBufer
	push inputHandle
	call ReadConsole
end main
