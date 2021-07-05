.MODEL SMALL			
.STACK 100H			
.DATA
main_return_val DW ?
a2 DW ?
b2 DW ?
t1 DW ?
.CODE
PRINT_INT PROC						
	PUSH AX						
	PUSH BX						
	PUSH CX						
	PUSH DX						
	OR AX, AX						
	JGE END_IF1						
	PUSH AX						
	MOV DL,'-'						
	MOV AH, 2						
	INT 21H						
	POP AX						
	NEG AX						
END_IF1:						
	XOR CX, CX						
	MOV BX, 10D						
REPEAT1:						
	XOR DX, DX						
	DIV BX						
	PUSH DX						
	INC CX						
	OR AX, AX						
	JNE REPEAT1						
	MOV AH, 2						
PRINT_LOOP:						
	POP DX						
	OR DL, 30H						
	INT 21H						
	LOOP PRINT_LOOP						
	MOV AH, 2						
	MOV DL, 10						
	INT 21H						
	MOV DL, 13						
	INT 21H						
	POP DX						
	POP CX						
	POP BX						
	POP AX						
	RET						
PRINT_INT ENDP
MAIN PROC									
	MOV AX, @DATA									
	MOV DS ,AX
	MOV AX, 5
	MOV a2, AX
	MOV AX, a2
	ADD AX, 10
	MOV t1, AX
	MOV AX, t1
	MOV b2, AX
	MOV AX, a2
	CALL PRINT_INT
	MOV AX, b2
	CALL PRINT_INT
LABEL_RETURN_main:
	MOV AH, 4CH									
	INT 21H									
END MAIN
