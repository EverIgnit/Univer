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
	template db "3*%s - (%s + %s)/2 = %s", 0     
	tmp3 dd 3.0
	tmp2 dd 2.0   
.data?
	a dq ?
	b dq ?  
	result dq ?
	numA db 1000 dup (?)
	numB db 1000 dup (?)
	resultStr db 1000 dup (?) 
	answer db 1000 dup (?)      
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
  	push 1000
   	push offset numA
    	push inputHandle
     	call ReadConsole     	
     	mov edx, offset numA
	mov eax, numberOfChars           
	mov byte ptr [ edx + eax - 2 ], 0  
	
	push offset a
	push offset numA
	call StrToFloat        

	
	push NULL
	push offset numberOfChars
  	push 1000
   	push offset numB
    	push inputHandle
     	call ReadConsole      	
     	mov edx, offset numB
	mov eax, numberOfChars           
	mov byte ptr [ edx + eax - 2 ], 0   
	
	push offset b
	push offset numB
	call StrToFloat       	   
;*******************************************		
        finit
        fld a
        fmul tmp3
        fld a
        fadd b
        fdiv tmp2
        fsubr st (0), st (1)
        fstp result
        
        push offset resultStr
	push dword ptr result + 4
	push dword ptr result
	call FloatToStr
 
        push offset resultStr
	push offset numB
	push offset numA 
	push offset numA
	push offset template
	push offset answer
	call wsprintf
	add ESP, 24
	
	push offset answer
	call lstrlen
	push NULL
	push offset numberOfChars
	push EAX
	push offset answer
	push outputHandle
	call WriteConsole
 
;*******************************************	
 	push 30000h
	call Sleep
	push 0
	call ExitProcess

end entryPoint 	