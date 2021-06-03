%x STRINGSTATE
%x COMMENTMULTI
%X COMMENTSINGLE

%{
#include <bits/stdc++.h>
#include "SymbolTable.cpp"
#include "y.tab.h"

extern YYSTYPE yylval;

using namespace std;

int numberOfLines = 1;
int numberOfErrors = 0;
int linestart;
%}

/* Declare Lex styled macros */
WHITESPACE [ \t\r\f\v]
LETTERS [a-zA-Z]
DIGIT [0-9]
EXP [Ee][+-]?[0-9]+
NEWLINE \n
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
MULOP "*"|"/"|"%"
RELOP "<"|"<="|">"|">="|"!="|"=="
LOGICOP "||"|"&&"
BITOP "|"|"&"|"<<"|">>"|"^"|"~"
FLOATINGPOINT (({DIGIT}+([\.]?{DIGIT}*))|({DIGIT}*([\.]?{DIGIT}+))){EXP}?
CHARACTERLITERALS '[^\n\\]'
TOOMANYDECIMAL     {DIGIT}*([\.]{DIGIT}*)+([\.]+{DIGIT}*)+{EXP}?
ILLFORMEDERROR     {DIGIT}*([\.]+{DIGIT}*)*?([Ee][+-]?([0-9]+)?([\.]*{DIGIT}*)+)+
INVALIDIDENTIFIER  {FLOATINGPOINT}{IDENTIFIER}{FLOATINGPOINT}*
MULTICHARACTERERROR   '[^\',][^\n\',]+'
UNFINISHEDCHARACTER   '[\\]'|'[^\n\']*|'\\[nt\\afr"bv0]|'\\
EMPTYCHARERROR        ''
UNRECOGNIZEDCHARACTER '(\\[^nt\\afr"bv0\n])+'

%%
{WHITESPACE}+ {}
{NEWLINE} {numberOfLines++;}

"if" {
    return IF;
}
"else" {
    return ELSE;
}
"for" {
    return FOR;
}
"while" {
    return WHILE;
}
"do" {
    return DO;
}
"int" {
    return INT;
}
"char" {
    return CHAR;
}
"float" {
    return FLOAT;
}
"double" {
    return DOUBLE;
}
"void" {
    return VOID;
}
"return" {
    return RETURN;
}
"continue" {
    return CONTINUE;
}

{DIGIT}+ {
    SymbolInfo *s = new SymbolInfo(yytext, "CONST_INT");
    yylval.symbolInfoPointer = s;
    return CONST_INT;
}

{FLOATINGPOINT} {
    SymbolInfo *s = new SymbolInfo(yytext, "CONST_FLOAT");
    yylval.symbolInfoPointer = s;
    return CONST_FLOAT;
}

{CHARACTERLITERALS} {
    SymbolInfo *s= new  SymbolInfo(yytext,"CONST_CHAR");
	yylval.symbolInfoPointer = s;
	return CONST_CHAR;
}

'\\[nt\\\'afr"bv0]' {
        switch(yytext[2])
        {
            case 't':   yytext[0] = '\t';
                        break;
            case 'n':   yytext[0] = '\n';
                        break;
            case '\\':  yytext[0] = '\\';
                        break;
            case '"' :  yytext[0] = '"';
                        break;
            case 'a' :  yytext[0] = '\a';
                        break;
            case 'f' :  yytext[0] = '\f';
                        break;
            case 'r' :  yytext[0] = '\r';
                        break;
            case 'b' :  yytext[0] = '\b';
                        break;
            case 'v' :  yytext[0] = '\v';
                        break;
            case '0' :  yytext[0] = '\0';
                        break;
            case '\'':  yytext[0] = '\'';
                        break;
            default:    break;
        }                 
        yytext[1] = '\0';
        SymbolInfo *s= new  SymbolInfo(yytext,"CONST_CHAR");
        yylval.symbolInfoPointer = s;
        return CONST_CHAR;
}

"+"|"-" {
    SymbolInfo *s= new  SymbolInfo(yytext,"ADDOP");
	yylval.symbolInfoPointer = s;
	return ADDOP;
}

"++" {       
    SymbolInfo *s= new  SymbolInfo(yytext,"INCOP");
	yylval.symbolInfoPointer = s;
	return INCOP;
}
"--" {       
    SymbolInfo *s= new  SymbolInfo(yytext,"DECOP");
	yylval.symbolInfoPointer = s;
	return DECOP;
}

{MULOP} {    
    SymbolInfo *s= new  SymbolInfo(yytext,"MULOP");
	yylval.symbolInfoPointer = s;
	return MULOP;
}

{RELOP} {    
    SymbolInfo *s= new  SymbolInfo(yytext,"RELOP");
	yylval.symbolInfoPointer = s;
	return RELOP;
}

{LOGICOP} {        
    SymbolInfo *s= new  SymbolInfo(yytext,"LOGICOP");
	yylval.symbolInfoPointer = s;
	return LOGICOP;
}

{BITOP} {
    SymbolInfo *s= new  SymbolInfo(yytext,"BITOP");
	yylval.symbolInfoPointer = s;
	return BITOP;
    
}

"=" {        
    return ASSIGNOP;
}

"!" {            
    SymbolInfo *s= new  SymbolInfo(yytext,"BITOP");
	yylval.symbolInfoPointer = s;
    return NOT;
}

"(" {          
    return LPAREN;
}

")" {
    return RPAREN;
}

"{" {            
    return LCURL;
}

"}" {
    return RCURL;
}

"[" {
    return LTHIRD;
}

"]" {          
    return RTHIRD;
}

"," {
    return COMMA;
}

";" {
    return SEMICOLON;
}

{IDENTIFIER}  {           
    SymbolInfo *s= new  SymbolInfo(yytext,"ID");
    yylval.symbolInfoPointer = s;
    return ID;
}

"//" {
    BEGIN COMMENTSINGLE;
}

<COMMENTSINGLE>\n {     
    numberOfLines++;
    BEGIN INITIAL;
}

<COMMENTSINGLE>[^\n] {
}

<COMMENTSINGLE>\\\n {
    numberOfLines++;
}

"/*" {
    BEGIN COMMENTMULTI;
}

<COMMENTMULTI>"*/" {
    BEGIN INITIAL;
}

<COMMENTMULTI>\n {
    numberOfLines++;
}

<COMMENTMULTI>.|[^*\n] {
}

<COMMENTMULTI><<EOF>> { 
    numberOfErrors++;
    return 0;
}

\" {
    BEGIN STRINGSTATE;
}

<STRINGSTATE>\" {     
    BEGIN INITIAL;
}

<STRINGSTATE>\n {
    numberOfLines++;
    numberOfErrors++;    
    BEGIN INITIAL;
}

<STRINGSTATE>\\\n {
    numberOfLines++;
}

<STRINGSTATE>\\[nt\\afr"bv0] {
}

<STRINGSTATE>[^\n"\\] {
}

<STRINGSTATE>\\ {
}

{TOOMANYDECIMAL} {
    numberOfErrors++;
}

{ILLFORMEDERROR} {
    numberOfErrors++;
}

{INVALIDIDENTIFIER} {
    numberOfErrors++;
}

{UNRECOGNIZEDCHARACTER} {
    numberOfErrors++;
}

{MULTICHARACTERERROR} {
    numberOfErrors++;
}

{EMPTYCHARERROR} {
    numberOfErrors++;
}


{UNFINISHEDCHARACTER} {
    numberOfErrors++;
}

. {
    numberOfErrors++;
}

<<EOF>> { 
    return 0;
}
%%

int yywrap(void){
    return 1;
}