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

; #########################################################################
.data 
	template db "| %5.5s | %5.5s |", 0 
	const1 dq 1.0 
	newLine db 0AH     
.data?
	a dq ?
	b dq ? 
	x1 dq ?
	x2 dq ?  
	deltaX dq ?
	result dq ? 
	arrayLength dd ?
	tmpInput db 1000 dup (?)
	x dq 1000 dup (?)
	y dq 1000 dup (?)  
	tmp dq ?         
	resultStr db 1000 dup (?)
	xStr db 1000 dup (?)  
	yStr db 1000 dup (?) 
	numberOfChars dd ?  
	inputHandle dd ?
	outputHandle dd ? 

.code
setArrays:  ; int setArrays()  //использет глобальные переменные
	; Стандартный пролог функции
        push EBP
        mov EBP, ESP    
        
	mov ecx, 0                ; счетчик (индекс)
	finit 
	fld x1
	startCycle: 
		fcom x2
		fstsw ax
		sahf
		ja endCycle ; если выше
		fst qword ptr [ x + ecx * 8 ] 
		
		fcom const1
		fstsw ax
		sahf
		jnb secondY ; если не ниже
		
		; y при x < 1 
		fld st(0)   
		fmul a
		fchs
		fadd a
		fsqrt
		fstp qword ptr [ y + ecx * 8 ]
		jmp continueCycle 
				
		secondY:  ;   y при x >= 1 
		       	fld const1
	       		fldln2   
			fld qword ptr [ x + ecx * 8 ]
			fyl2x 
			fmul b
			fstp qword ptr [ y + ecx * 8 ]
			fstp tmp
			
		continueCycle:
			inc ecx
			fadd deltaX
			jmp startCycle		
	endCycle: 
	mov arrayLength, ecx 
	pop EBP	
ret 0 

writeArrays:
	; Стандартный пролог функции
        push EBP
        mov EBP, ESP            
	mov esi, 0                ; счетчик (индекс)
	
	startWriteCycle:
		cmp esi, arrayLength
		je endWriteCycle
		
		push offset xStr
		push dword ptr [ x + esi * 8 + 4 ]
       		push dword ptr [ x + esi * 8 ]
		call FloatToStr  
		
		push offset yStr
		push dword ptr [ y + esi * 8 + 4]
       		push dword ptr [ y + esi * 8 ]
		call FloatToStr

       		push offset yStr
       		push offset xStr
       		push offset template
       		push offset resultStr
      		call wsprintf
       		add ESP, 16
	
       		push offset resultStr
       		call lstrlen  
       		
      		push NULL
      		push offset numberOfChars
      		push EAX
      		push offset resultStr
      		push outputHandle
       		call WriteConsole   
       		
      		; newLine
       		push NULL                 
       		push offset numberOfChars
      		push 1                  
      		push offset newLine
      		push outputHandle         
       		call WriteConsole  
       		
       		inc esi
       		jmp startWriteCycle
				
      	endWriteCycle:
	pop EBP			
ret 0
 
entryPoint:                     
	push STD_INPUT_HANDLE    
	call GetStdHandle    
	mov inputHandle, EAX    
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX
	        
	
;*******************************
;  	INPUT
;*******************************   
	;input x1
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset tmpInput
    	push inputHandle
     	call ReadConsole   
     	  	
     	mov edx, offset tmpInput
	mov eax, numberOfChars           
	mov byte ptr [ edx + eax - 2 ], 0  
		
	push offset x1
	push offset tmpInput
	call StrToFloat      

        ;input x2
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset tmpInput
    	push inputHandle
     	call ReadConsole     
     		
     	mov edx, offset tmpInput
	mov eax, numberOfChars           
	mov byte ptr [ edx + eax - 2 ], 0  
		
	push offset x2
	push offset tmpInput
	call StrToFloat   
	
	;input deltaX
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset tmpInput
    	push inputHandle
     	call ReadConsole     
     		
     	mov edx, offset tmpInput
	mov eax, numberOfChars           
	mov byte ptr [ edx + eax - 2 ], 0   
		
	push offset deltaX
	push offset tmpInput
	call StrToFloat         
		
	;input a
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset tmpInput
    	push inputHandle
     	call ReadConsole     	
     	
     	mov edx, offset tmpInput
	mov eax, numberOfChars           
	mov byte ptr [ edx + eax - 2 ], 0  
	
	push offset a
	push offset tmpInput
	call StrToFloat   
	
	;input b
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset tmpInput
    	push inputHandle
     	call ReadConsole  
     	   	
     	mov edx, offset tmpInput
	mov eax, numberOfChars           
	mov byte ptr [ edx + eax - 2 ], 0 
		
	push offset b
	push offset tmpInput
	call StrToFloat         
;*****************************************

	call setArrays  
	
	call writeArrays
	
;*****************************************	
 	push 30000h
	call Sleep
	push 0
	call ExitProcess
end entryPoint   