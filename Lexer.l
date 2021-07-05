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
extern FILE* errors;
int linestart;
string s2 = "";
string s1 = "";
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
UNFINISHEDCHARACTER   '[\\]'|'[^\n\']|'\\[nt\\afr"bv0]|'\\
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

"printf" {
    return PRINTLN;
}

"println" {
    return PRINTLN;
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
    s1 = s1+yytext;
    linestart = numberOfLines;
    BEGIN COMMENTMULTI;
}

<COMMENTMULTI>"*/" {
    s1 = "";
    BEGIN INITIAL;
}

<COMMENTMULTI>\n {
    s1 = s1+yytext;
    numberOfLines++;
}

<COMMENTMULTI>.|[^*\n] {
    s1 = s1+yytext;
}

<COMMENTMULTI><<EOF>> { 
    fprintf(errors,"Error observed at Line No:%d: Unterminated Comment:\n\n",linestart);
    s1 = "";
    numberOfErrors++;
    fprintf(errors,"Total Line No:%d\n",--numberOfLines);
    fprintf(errors,"Total Errors:%d\n\n",numberOfErrors);
    return 0;
}

\" {
    s1 = s1+yytext;
    linestart = numberOfLines;
    BEGIN STRINGSTATE;
}

<STRINGSTATE>\" {
    s1 = s1+yytext;
    s1 = "";
    s2 = "";     
    BEGIN INITIAL;
}

<STRINGSTATE>\n {
    numberOfLines++;
    fprintf(errors,"Error observed at Line No:%d: Unterminated string: %s\n\n",linestart,s1.c_str());
    s1 = "";
    numberOfErrors++;    
    BEGIN INITIAL;
}

<STRINGSTATE>\\\n {
    numberOfLines++;
    s1 = s1+yytext;
}

<STRINGSTATE>\\[nt\\afr"bv0] {
}

<STRINGSTATE>[^\n"\\] {
}

<STRINGSTATE>\\ {
}

{TOOMANYDECIMAL} {
    numberOfErrors++;
    fprintf(errors,"Error at line %d: Too many decimal point: %s\n\n",numberOfLines,yytext);
}

{ILLFORMEDERROR} {
    numberOfErrors++;
    fprintf(errors,"Error at line %d: Ill formed Number: %s\n\n",numberOfLines,yytext);
}

{INVALIDIDENTIFIER} {
    numberOfErrors++;
    fprintf(errors,"Error at line %d: Invalid prefix on ID or invalid suffix on Number: %s\n\n",numberOfLines,yytext);
}

{UNRECOGNIZEDCHARACTER} {
    numberOfErrors++;
    fprintf(errors,"Error at line %d: Unrecognized character constant error: %s\n\n",numberOfLines,yytext);
}

{MULTICHARACTERERROR} {
    numberOfErrors++;
    fprintf(errors,"Error at line %d: Multi character constant error: %s\n\n",numberOfLines,yytext);
}

{EMPTYCHARERROR} {
    numberOfErrors++;
    fprintf(errors,"Error at line %d: Empty character constant error: %s\n\n",numberOfLines,yytext);
}


{UNFINISHEDCHARACTER} {
    numberOfErrors++;
    fprintf(errors,"Error at line %d: Unterminated character: %s\n\n",numberOfLines,yytext);
}

. {
    numberOfErrors++;
    fprintf(errors,"Error at line %d: Unrecognized character constant error: %s\n\n",numberOfLines,yytext);
}

<<EOF>> { 
    return 0;
}
%%

int yywrap(void){
    return 1;
}