.MODEL SMALL			

.STACK 100H			

.DATA
a1 DW ?
function_return_val DW ?
a2 DW ?
t0 DW ?
t1 DW ?
t2 DW ?
t3 DW ?
main_return_val DW ?
b4 DW ?
t6 DW ?
t7 DW ?
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

function PROC						
	PUSH AX						
	PUSH BX						
	PUSH CX						
	PUSH DX

	PUSH a2


	MOV AX, a2
	CMP AX, 1
	JE L0
	MOV t0, 0
	JMP L1
L0:
	MOV t0, 1
L1:

	MOV AX, t0
	CMP AX, 0
	JE L2
	MOV AX, 1
	MOV function_return_val, AX

	JMP LABEL_RETURN_function
L2:



	MOV AX, a2
	SUB AX, 1
	MOV t1, AX

	MOV AX, t1
	MOV a2, AX
	CALL function
	MOV AX, function_return_val
	MOV t2, AX

	MOV AX, a2
	MOV BX, t2
	MUL BX
	MOV t3, AX

	MOV AX, t3
	MOV function_return_val, AX

	JMP LABEL_RETURN_function
LABEL_RETURN_function:

	POP a2

	POP DX					
	POP CX					
	POP BX					
	POP AX					
	ret

function ENDP

MAIN PROC									
	MOV AX, @DATA									
	MOV DS ,AX
	MOV AX, 1
	MOV a1, AX

	MOV AX, 6
	MOV b4, AX


	MOV AX, b4
	MOV a2, AX
	CALL function
	MOV AX, function_return_val
	MOV t6, AX

	MOV AX, a1
	ADD AX, t6
	MOV t7, AX

	MOV AX, t7
	MOV a1, AX



	MOV AX, a1
	CALL PRINT_INT


LABEL_RETURN_main:

	MOV AH, 4CH									
	INT 21H									
END MAIN