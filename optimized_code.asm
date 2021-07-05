.MODEL SMALL			
.STACK 100H			
.DATA
a1 DW ?
function_return_val DW ?
a2 DW ?
t0 DW ?
main_return_val DW ?
b3 DW ?
c3 DW ?
t4 DW ?
t5 DW ?
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
	XOR DX, DX
	MOV AX, a2
	MOV BX, 2
	DIV BX
	MOV t0, DX
	MOV AX, t0
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
	MOV b3, AX
	MOV AX, 2
	MOV c3, AX
	MOV AX, b3
	MOV a2, AX
	CALL function
	MOV AX, function_return_val
	MOV t4, AX
	MOV AX, t4
	CMP AX, 1
	JE L0
	MOV t5, 0
	JMP L1
L0:
	MOV t5, 1
L1:
	MOV AX, t5
	CMP AX, 0
	JE L2
	MOV AX, a1
	CALL PRINT_INT
	JMP L3
	JMP L3
L2:
	MOV AX, c3
	CALL PRINT_INT
L3:
	MOV AX, b3
	CALL PRINT_INT
LABEL_RETURN_main:
	MOV AH, 4CH									
	INT 21H									
END MAIN
