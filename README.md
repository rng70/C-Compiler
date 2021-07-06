# C Compiler

---

In this project, a C programming language compiler was made which can produce “Assembly Code” & “Optimized Assembly Code” for 8066 micro-processor.

## Description

---

This compiler can only handle a subset of ***C*** language as ***structure, unions, pointers, recursive function as function parameter*** haven’t been handled. 

Bison and Flex was used to parse and tokenize the input file and to detect any error.

For simplicity, for printing purpose ***printf(arg) or println(arg)*** was implemented.



***[Note]***: `As, recursion was not handled so recursive function won’t work properly and parser is smart enough to catch any semantic and lexical error present in provided C code.`

A sample ***C*** code:

```c
int main(){
    int a, b;
    a = 5;
    b = a + 10;
    
    /* ****************************************************** */
    /*    Both println() and printf() is for showing output   */
    /* ****************************************************** */
    printf(a);
    println(b);
}
```

From this input an unoptimized assembly code was generated which was optimized later

* ***Unoptimized Assembly Code***:

```assembly
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
	MOV AX,  @DATA									
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
```

From this unoptimized code segment an optimized code segment was generated

* ***Optimized Assembly Code***:

```assembly
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
	ADD AX, 10
	MOV t1, AX
	MOV b2, AX
	MOV AX, a2
	CALL PRINT_INT
	MOV AX, b2
	CALL PRINT_INT
	
LABEL_RETURN_main:
	MOV AH, 4CH									
	INT 21H									
END MAIN
```

## Environment

---

* This project was done in ***Linux*** operating system but it can be done in any operating system

## Tools

---

Tools used for the project,

* ***FLEX*** 
  * Flex is a free and open-source software alternative to lex. It is a computer program that generates lexical analyzers.
* ***BISON***:
  * Bison, is a parser generator that is part of the GNU Project. Bison reads a specification of a context-free language, warns about any parsing ambiguities, and generates a parser that reads sequences of tokens and decides whether the sequence conforms to the syntax specified by the grammar. 
  * The grammar that was implemented can be found [here](./Backup%20Files/Offline%20-%203/BisonAssignmentGrammar.PDF)

## Languages

---

* C++
* Assembly [x86 8066]

## Files

---

Here is a small details of the file-system:

* ***SymbolInfo.h***: This file contains information of any valid token. For an example,

```c++
int a;
```

will be stored as <ID, a> or <ID, location of a in Symbol Table> in symbol table. The information name and type was stored. This file provide a ***Class*** named ***SymbolInfo*** to store informations.

* ***ExtraSymbolInfo.h***: This file contains additional information of the tokens and most importantly, for ***Intermediate Code Generation*** this file was used to store assembly code
* ***ScopeTable.h***: Provide an interface to store each symbol’s scope like *global or local*.
* ***SymbolTable.h***: Actual file that handles and stores all information and processing related to any valid token.
* ***StringHandler.h***: A simple file used for generating label and variable and also for optimization purpose.
* ***SymbolTable.cpp***: Simply combines ***SymbolInfo.h, ExtraSymbolInfo.h ScopeTable.h SymbolTable.h.***
* ***Lexer.l***: The lexed file that has rule to tokenize a valid *C* code and handle any lexical errors.
* ***Parser.y***: The parser file that has the parsing rule with specific grammar that can be found [here](./Backup%20Files/Offline%20-%203/BisonAssignmentGrammar.PDF)
* ***Script.sh***: The shell-script with all necessary command to parse and execute the code.
* ***Input.c***: Input file to test validity of the program.
* ***log.txt***: File to show outputs.
* ***error.txt***: File to show errors(if any).
* ***code.asm***: File with unoptimized assembly code.
* ***optimized_code.asm***: File with optimized assembly code.

***[Note]***: `code.asm and optimized_code.asm will only generate when there is no error in the provided input file.`

# How to Run

---

* Clone the repository into your local machine

  ```bash
  git clone https://github.com/rng70/C-Compiler
  ```

* Give proper permission to Script.sh file

  ```bash
  chmod +x Script.sh
  ```

* Run the Script file

  ```bash
  ./Script.sh
  ```

* Then run code.asm in emu8066 simulator.



---

---
