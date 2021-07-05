.MODEL SMALL			

.STACK 100H			

.DATA
main_return_val DW ?
a2 DW ?
b2 DW ?
c2 DW ?
i2 DW ?
t3 DW ?
t4 DW ?
t6 DW ?
t7 DW ?
t8 DW ?
t10 DW ?

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
	MOV AX, 0
	MOV b2, AX

	MOV AX, 1
	MOV c2, AX

	MOV AX, 0
	MOV i2, AX

L4:
	MOV AX, i2
	CMP AX, 4
	JL L0
	MOV t3, 0
	JMP L1
L0:
	MOV t3, 1
L1:

	MOV AX, t3
	CMP AX, 0
	JE L5
	MOV AX, 3
	MOV a2, AX

L2:
	MOV AX,a2
	MOV t6,AX
	DEC AX
	MOV a2,AX

	MOV AX, t6
	CMP AX, 0
	JE L3
	MOV AX,b2
	MOV t7,AX
	INC AX
	MOV b2,AX

	JMP L2
L3:

	MOV AX,i2
	MOV t4,AX
	INC AX
	MOV i2,AX

	JMP L4
L5:



	MOV AX, b2
	SUB AX, a2
	MOV t8, AX

	MOV AX, t8
	MOV a2, AX



	MOV AX, a2
	CALL PRINT_INT



	MOV AX, b2
	CALL PRINT_INT



	MOV AX, c2
	ADD AX, 10
	MOV t10, AX

	MOV AX, t10
	MOV c2, AX



	MOV AX, c2
	CALL PRINT_INT


LABEL_RETURN_main:

	MOV AH, 4CH									
	INT 21H									
END MAIN