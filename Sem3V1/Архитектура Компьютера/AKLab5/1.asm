.486
    .model flat, stdcall
    option casemap :none   ; case sensitive

    include windows.inc
    include user32.inc
    include kernel32.inc

    includelib user32.lib
    includelib kernel32.lib

; #########################################################################
.data      
	mass dd 20 dup (2)  
	sizeArray dd 20     
	result db 200 dup (0)
        template db "%d ", 0    ; ������� ������ ��� ������ ������ ����� 
.data?
       ;	result db ?     
	numberOfChars dd ?  
	outputHandle dd ? 
	
.code    
;       buffer ( [EBP + 8] )  - ��������� �� ������, � ������� �����
;                               ������������� ������������� �������
;       array  ( [EBP + 12] ) - ��������� �� ������
;       size   ( [EBP + 16] ) - ���������� ��������� � �������
; ����������� ������� ������������ ������ ��������� ��������. ���� ������ ������ ������ 8,16 � 32 ���, �� �������� ���������� ������
;+8,+12,+16 - ��������
arrayToStr:
        ; ����������� ������ �������
        push EBP   ; ��������� � ����
        mov EBP, ESP ; esp - ������ �����
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
ret 12   ;����� �� �������, 12-���������� ����, ��������� �� �����

entryPoint:  
	push STD_OUTPUT_HANDLE
	call GetStdHandle
	mov outputHandle, EAX        
        
	push sizeArray
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

   
 	push 30000h
	call Sleep
	push 0
	call ExitProcess

end entryPoint 	