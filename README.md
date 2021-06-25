# C Compiler

---

In this project, a C programming language compiler was made which can produce “Assembly Code” & “Optimized Assembly Code” for 8066 micro-processor.

## Description

---

This compiler can only handle a subset of ***C*** language as ***structure, unions, pointers, recursive function as function parameter*** haven’t been handled. 

A sample ***C*** code:

```c
int main(){
    int a;
    a = 3+2;
    println(a);
}
```

From this input the assembly code is generated which may or may not be optimized which was optimized later

```assembly
.MODEL SMALL
.STACK 100H

.DATA
value DW ?
var DW ?
tempVar DW ?

.CODE
PRINT_INT PROC
	PUSH AX 
	PUSH BX 
	PUSH CX 
	PUSH DX

	OR AX, AX 
	JGE END_IF1 
	PUSH AX 
	MOV DL, '-' 
	MOV AH, 2 
	INT 21H 
	POP AX 
	NEG AX

END_IF1: 
	XOR CX, CX 
	MOV BX, 10D 

REPEAT1: 
	XOR DX,DX 
	DIV BX 
	PUSH DX 
	INC CX 

	OR AX,AX 
	JNE REPEAT1 

	MOV AH,2 

PRINT_LOOP: 
	POP DX 
	OR DL,30H 
	INT 21H 
	LOOP PRINT_LOOP
	MOV AH,2 
	MOV DL,10 
	INT 21H 

	MOV DL,13 
	INT 21H

	POP DX 
	POP CX 
	POP BX 
	POP AX 
	RET
PRINT_INT ENDP

MAIN PROC
	MOV AX, @DATA
	MOV DS, AX

	MOV AX, 3
	ADD AX, 2
	MOV tempVar, AX

	MOV AX, tempVar
	MOV var, AX

	MOV AX, var
	CALL printINT

returnMain:
	MOV AH,4CH
	INT 21H
END MAIN
```

