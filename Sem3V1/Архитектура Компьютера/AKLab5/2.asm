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
	result db 200 dup (0)
        template db "%d ", 0    ; ������� ������ ��� ������ ������ �����   
        newLine dd 0AH
.data?
      	mass dd 10 dup (?)   
	numberOfChars dd ?  
	outputHandle dd ? 
	
.code

arrayToStr:
        ; ����������� ������ �������
        push EBP
        mov EBP, ESP
        ; ������ ����� - ���� ���� �������������� ��������
        cycle:
                cmp dword ptr [ EBP + 16 ], 0
                je endFunction
                ; ������������ ���������� ������������� ������ �����
                mov EAX, [ EBP + 12 ]         ; ��������� �� ��������� �����
                push [ EAX ]                  ; ����� ����� (������� �������),
                                              ; ������������� � ������
                push offset template          ; ������ ������, � �������
                                              ; ������������� ��������
                push [ EBP + 8 ]              ; ����� ������ ��� ����������
                                              ; �������� ������
                call wsprintf                 ; � EAX ������������ ����� ��������,
                                              ; ���������� � �����
                add ESP, 12                   ; ��������� ����
                ; ���������� � ���������� �����
                add [ EBP + 8 ], EAX          ; ���������� ����� ������ ���
                                              ; ���������� �����
                add dword ptr [ EBP + 12 ], 4 ; ���������� ��������� �� ���������
                                              ; ������� �������
                dec dword ptr [ EBP + 16 ]    ; ��������� �������
        ; ����� �����
        jmp cycle
        endFunction:
        ; ����������� ������ �������
        pop EBP
; ����� � ��������� ����
ret 12 

inArray:  ; void inArray(int* mass, int a0, int d, int count)  
	; ����������� ������ �������
        push EBP           
        mov EBP, ESP        
        
	mov ecx, 0                ; ������� (������)
	mov ebx, [ ebp + 12 ]       ; 0-�� ������� ����������      
	mov esi, [ ebp + 16 ]       ; � esi �������� ����������
	startCycle:
		cmp ecx, [ ebp + 20 ]      ; ��������� �������
		je endCycle                
		mov eax, [ ebp + 8 ]       ;  � eax ��������� �� ������
		mov [ eax + ecx * 4 ], ebx    ; ��������� i-�� ������� �������
		add ebx, esi  
		inc ecx
		jmp startCycle		
	endCycle: 
	pop EBP	
ret 16  

sumArray:  ; int sumArray(int* mass, int count)     ��������� � EAX
	push EBP
        mov EBP, ESP
        mov ecx, 0                ; ������� (������)
        mov eax, 0                ; ����� ���������� = 0
	startCycle2:
		cmp ecx, [ ebp + 12 ]      ; ��������� �������
		je endCycle2                
		mov ebx, [ ebp + 8 ]       ;  � ebx ��������� �� ������
		add eax, [ ebx + ecx * 4 ]    ; �������� i-�� ������� ������� 
		inc ecx
		jmp startCycle2		
	endCycle2: 
	pop EBP	
ret 8    

handleArray:  ; void handleArray(int* mass, int count)   
	push EBP
        mov EBP, ESP
        mov ecx, 0                ; ������� (������)
	startCycle3:
		cmp ecx, [ ebp + 12 ]      ; ��������� �������
		je endCycle3                
		mov ebx, [ ebp + 8 ]       ;  � ebx ��������� �� ������ 
		mov edx, 0
		mov eax, [ ebx + ecx * 4 ]    ; � eax i-�� ������� ������� 
		mov esi, 4 
		div esi
		cmp edx, 0              ; ���� ������� �� ������� �� 4 �� ����� 0, �� ���������� ����, ���� ����� 0, �� ��������� � 4
		jne continueCycle
		mov [ ebx + ecx * 4 ], eax
	continueCycle:	
		inc ecx
		jmp startCycle3		
	endCycle3: 
	pop EBP	
ret 8      
        

entryPoint:  
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX   
	      
	push 10        ;ebp+20
	push 43        ;ebp+16
	push 18        ;ebp+12
	push offset mass ;ebp+8
	call inArray   
	;ebp+4
	push 10          ;ebp+16
        push offset mass ;ebp+12
        push offset result ;ebp+8
        call arrayToStr
            
        push offset result
 	call lstrlen 
	
	push NULL                 
	push offset numberOfChars
	push eax
	push offset result
	push outputHandle         
	call WriteConsole   
;********************************
	push NULL                 
	push offset numberOfChars
	push 1                   
	push offset newLine
	push outputHandle         
	call WriteConsole
;********************************	
	
	push 10             ;ebp+12
	push offset mass    ;ebp+8
	call sumArray
	
	push offset result
	push eax
	call dwtoa
	         
	push offset result
 	call lstrlen
	           
	push NULL                 
	push offset numberOfChars
	push eax
	push offset result
	push outputHandle         
	call WriteConsole 
	
;********************************
	push NULL                 
	push offset numberOfChars
	push 1                   
	push offset newLine
	push outputHandle         
	call WriteConsole
;********************************  

       	push 10              ;ebp+12
	push offset mass       ;ebp+8
	call handleArray
	  
   	push 10
        push offset mass 
        push offset result
        call arrayToStr
            
        push offset result
 	call lstrlen 
	
	push NULL                 
	push offset numberOfChars
	push eax
	push offset result
	push outputHandle         
	call WriteConsole  
	 
;********************************
	push NULL                 
	push offset numberOfChars
	push 1                   
	push offset newLine
	push outputHandle         
	call WriteConsole
;********************************	
	
	push 10
	push offset mass
	call sumArray
	
	push offset result
	push eax
	call dwtoa
	         
	push offset result
 	call lstrlen
	           
	push NULL                 
	push offset numberOfChars
	push eax
	push offset result
	push outputHandle         
	call WriteConsole 
	
	push 30000h
	call Sleep
	push 0
	call ExitProcess

end entryPoint 	     