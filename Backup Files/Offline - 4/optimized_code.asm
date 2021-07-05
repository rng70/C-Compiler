.MODEL SMALL			
.STACK 100H			
.DATA
max2_return_val DW ?
a2 DW ?
b2 DW ?
t0 DW ?
max3_return_val DW ?
a5 DW ?
b5 DW ?
c5 DW ?
maxab5 DW ?
t1 DW ?
t3 DW ?
max4_return_val DW ?
a6 DW ?
b6 DW ?
c6 DW ?
d6 DW ?
maxabc6 DW ?
t4 DW ?
t6 DW ?
main_return_val DW ?
a7 DW ?
b7 DW ?
c7 DW ?
d7 DW ?
max7 DW ?
t7 DW ?
t9 DW ?
t13 DW ?
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
max2 PROC						
	PUSH AX						
	PUSH BX						
	PUSH CX						
	PUSH DX
	PUSH a2
	PUSH b2
	MOV AX, a2
	CMP AX, b2
	JGE L0
	MOV t0, 0
	JMP L1
L0:
	MOV t0, 1
L1:
	MOV AX, t0
	CMP AX, 0
	JE L2
	MOV AX, a2
	MOV max2_return_val, AX
	JMP LABEL_RETURN_max2
	JMP L3
	JMP L3
L2:
	MOV AX, b2
	MOV max2_return_val, AX
	JMP LABEL_RETURN_max2
L3:
LABEL_RETURN_max2:
	POP b2
	POP a2
	POP DX					
	POP CX					
	POP BX					
	POP AX					
	ret
max2 ENDP
max3 PROC						
	PUSH AX						
	PUSH BX						
	PUSH CX						
	PUSH DX
	PUSH a5
	PUSH b5
	PUSH c5
	PUSH maxab5
	MOV AX, a5
	MOV a2, AX
	MOV AX, b5
	MOV b2, AX
	CALL max2
	MOV AX, max2_return_val
	MOV t1, AX
	MOV AX, t1
	MOV maxab5, AX
	MOV AX, c5
	MOV a2, AX
	MOV AX, maxab5
	MOV b2, AX
	CALL max2
	MOV AX, max2_return_val
	MOV t3, AX
	MOV AX, t3
	MOV max3_return_val, AX
	JMP LABEL_RETURN_max3
LABEL_RETURN_max3:
	POP maxab5
	POP c5
	POP b5
	POP a5
	POP DX					
	POP CX					
	POP BX					
	POP AX					
	ret
max3 ENDP
max4 PROC						
	PUSH AX						
	PUSH BX						
	PUSH CX						
	PUSH DX
	PUSH a6
	PUSH b6
	PUSH c6
	PUSH d6
	PUSH maxabc6
	MOV AX, a6
	MOV a5, AX
	MOV AX, b6
	MOV b5, AX
	MOV AX, c6
	MOV c5, AX
	CALL max3
	MOV AX, max3_return_val
	MOV t4, AX
	MOV AX, t4
	MOV maxabc6, AX
	MOV AX, maxabc6
	MOV a2, AX
	MOV AX, d6
	MOV b2, AX
	CALL max2
	MOV AX, max2_return_val
	MOV t6, AX
	MOV AX, t6
	MOV max4_return_val, AX
	JMP LABEL_RETURN_max4
LABEL_RETURN_max4:
	POP maxabc6
	POP d6
	POP c6
	POP b6
	POP a6
	POP DX					
	POP CX					
	POP BX					
	POP AX					
	ret
max4 ENDP
MAIN PROC									
	MOV AX, @DATA									
	MOV DS ,AX
	MOV AX, 20
	MOV BX, 1
	MUL BX
	MOV t7, AX
	MOV AX, t7
	MOV a7, AX
	MOV AX, 70
	ADD AX, 0
	MOV t9, AX
	MOV AX, t9
	MOV b7, AX
	MOV AX, 1
	MOV c7, AX
	MOV AX, 35
	MOV d7, AX
	MOV AX, a7
	MOV a6, AX
	MOV AX, b7
	MOV b6, AX
	MOV AX, c7
	MOV c6, AX
	MOV AX, d7
	MOV d6, AX
	CALL max4
	MOV AX, max4_return_val
	MOV t13, AX
	MOV AX, t13
	MOV max7, AX
	MOV AX, max7
	CALL PRINT_INT
LABEL_RETURN_main:
	MOV AH, 4CH									
	INT 21H									
END MAIN
