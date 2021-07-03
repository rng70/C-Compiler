.MODEL SMALL			
.STACK 100H			
.DATA
max2_return_val DW ?
a2 DW ?
b2 DW ?
t0 DW ?
max3_return_val DW ?
a3 DW ?
b3 DW ?
c3 DW ?
maxab2 DW ?
t1 DW ?
t3 DW ?
max4_return_val DW ?
a3 DW ?
b3 DW ?
c3 DW ?
d3 DW ?
maxabc3 DW ?
t4 DW ?
t6 DW ?
main_return_val DW ?
a4 DW ?
b4 DW ?
c4 DW ?
d4 DW ?
max4 DW ?
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
max2PROC						
	PUSH AX						
	PUSH BX						
	PUSH CX						
	PUSH DX
	PUSH a2
	PUSH b2
	MOV AX, a1
	CMP AX, b1
	JGE L0
	MOV t0, 0
	JMP L1
L0:
	MOV t0, 1
L1:
	MOV AX, t0
	CMP AX, 0
	JE L2
	MOV AX, a1
	MOV max2_return_val, AX
	JMP LABEL_RETURN_max2
	JMP L3
	JMP L3
L2:
	MOV AX, b1
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
max3PROC						
	PUSH AX						
	PUSH BX						
	PUSH CX						
	PUSH DX
	PUSH a3
	PUSH b3
	PUSH c3
	PUSH maxab2
	MOV AX, a2
	MOV a2, AX
	MOV AX, b2
	MOV b2, AX
	CALL max2
	MOV AX, max2_return_val
	MOV t1, AX
	MOV AX, t1
	MOV maxab2, AX
	MOV AX, c2
	MOV a2, AX
	MOV AX, maxab2
	MOV b2, AX
	CALL max2
	MOV AX, max2_return_val
	MOV t3, AX
	MOV AX, t3
	MOV max3_return_val, AX
	JMP LABEL_RETURN_max3
LABEL_RETURN_max3:
	POP maxab2
	POP c3
	POP b3
	POP a3
	POP DX					
	POP CX					
	POP BX					
	POP AX					
	ret
max3 ENDP
max4PROC						
	PUSH AX						
	PUSH BX						
	PUSH CX						
	PUSH DX
	PUSH a3
	PUSH b3
	PUSH c3
	PUSH d3
	PUSH maxabc3
	MOV AX, a3
	MOV a3, AX
	MOV AX, b3
	MOV b3, AX
	MOV AX, c3
	MOV c3, AX
	CALL max3
	MOV AX, max3_return_val
	MOV t4, AX
	MOV AX, t4
	MOV maxabc3, AX
	MOV AX, maxabc3
	MOV a2, AX
	MOV AX, d3
	MOV b2, AX
	CALL max2
	MOV AX, max2_return_val
	MOV t6, AX
	MOV AX, t6
	MOV max4_return_val, AX
	JMP LABEL_RETURN_max4
LABEL_RETURN_max4:
	POP maxabc3
	POP d3
	POP c3
	POP b3
	POP a3
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
	MOV a4, AX
	MOV AX, 69
	ADD AX, 0
	MOV t9, AX
	MOV AX, t9
	MOV b4, AX
	MOV AX, 1
	MOV c4, AX
	MOV AX, 35
	MOV d4, AX
	MOV AX, a4
	MOV a3, AX
	MOV AX, b4
	MOV b3, AX
	MOV AX, c4
	MOV c3, AX
	MOV AX, d4
	MOV d3, AX
	CALL max4
	MOV AX, max4_return_val
	MOV t13, AX
	MOV AX, t13
	MOV max4, AX
	MOV AX, max4
	CALL PRINT_INT
LABEL_RETURN_main:
	MOV AH, 4CH									
	INT 21H									
END MAIN
