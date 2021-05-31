// %option noyywrap

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
// string s1 = "";
// string s2 = "";

// SymbolTable symbolTable(7);

// void filePrint(int numberOfLines, char* a, char* b, FILE* tokens, FILE* logs, int fileNumber=0)
// {
//     if(!fileNumber){
//         fprintf(tokens,"<%s> ",a);
//     }else{
//         if(!strcmp(a, "CONST_CHAR")){
//             string mn(b);
//             mn.erase(0,1);
//             mn.erase(mn.size()-1,1);
//             fprintf(tokens, "<CHAR_CONST, %s> ", mn.c_str());
//         }else{
//             fprintf(tokens,"<%s, %s> ",a,b);
//         }
//     }
//     fprintf(logs,"Line no %d: Token <%s> Lexeme %s found",numberOfLines,a,b);
//     if(!strcmp(a, "CONST_CHAR")){
//         string str1(b);
//         str1.erase(0, 1);
//         str1.erase(str1.size()-1, 1);
//         fprintf(logs, " --> <CHAR_CONST, %s> \n\n", str1.c_str());
//     }else{
//         fprintf(logs, "\n\n");
//     }
// }
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
"break" {
    return BREAK;
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
"switch" {
    return SWITCH;
}
"case" {
    return CASE;
}
"default" {
    return DEFAULT;
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
    // s1 = s1+yytext;
}

<COMMENTSINGLE>\\\n {
    numberOfLines++;
    //s1 = s1+yytext;
}

"/*" {
    BEGIN COMMENTMULTI;
    //s1 = s1+yytext;
    //linestart = numberOfLines;
}

<COMMENTMULTI>"*/" {
    // s1 = s1+yytext;
    // fprintf(logs,"Line no %d: Token <COMMENT> Lexeme %s found\n\n",linestart,s1.c_str());
    // s1 = "";
    // linestart = 0;
    BEGIN INITIAL;
}

<COMMENTMULTI>\n {
    //s1 = s1+yytext;
    numberOfLines++;
}

<COMMENTMULTI>.|[^*\n] {
    //s1 = s1+yytext;
}

<COMMENTMULTI><<EOF>> { 
    // fprintf(logs,"Error at line no %d: Unterminated Comment %s\n\n",linestart,s1.c_str());
    // s1 = "";
    numberOfErrors++;
    // symbolTable.printAllTable();
    // fprintf(logs,"Total lines: %d\n",numberOfLines);
    // fprintf(logs,"Total errors: %d\n",numberOfErrors); 
    return 0;
}

\" {
    BEGIN STRINGSTATE;
    // s1 = s1+yytext;
    // linestart = numberOfLines;  
}

<STRINGSTATE>\" {     
    // s1 = s1+yytext;
    // fprintf(logs,"Line no %d: Token <STRING> Lexeme %s found --> <STRING, \"%s\"> \n\n",linestart,s1.c_str(), s2.c_str());
    // fprintf(tokens,"<STRING, \"%s\"> ", s2.c_str());
    // s1 = "";
    // s2 = "";
    BEGIN INITIAL;
}

<STRINGSTATE>\n {
    numberOfLines++;
    // fprintf(logs,"Error at line no %d: Unterminated String %s\n\n",linestart,s1.c_str());
    // s1 = "";
    // s2 = "";
    numberOfErrors++;    
    BEGIN INITIAL;
}

<STRINGSTATE>\\\n {
    numberOfLines++;
    //s1 = s1+yytext;
}

<STRINGSTATE>\\[nt\\afr"bv0] {   
    // switch(yytext[1])
    // {
    // case 'n':  s2 = s2+'\n';
    //             break;
    // case 't':  s2 = s2+'\t';
    //             break;
    // case '\\': s2 = s2+'\\';
    //             break;
    // case 'a':  s2 = s2+'\a';
    //             break;
    // case 'f':  s2 = s2+'\f';
    //             break;
    // case 'r':  s2 = s2+'\r';
    //             break;
    // case '"':  s2 = s2+'\"';
    //             break;
    // case 'b':  s2 = s2+'\b';
    //             break; 
    // case 'v':  s2 = s2+'\v';
    //             break;
    // case '0':  s2 = s2+'\0';
    //             break;
    // }
    // s1 = s1+yytext;
}

<STRINGSTATE>[^\n"\\] {
    // s1 = s1+yytext;
    // s2 = s2+yytext;
}

<STRINGSTATE>\\ { 
    //s1 = s1+yytext;
}

{TOOMANYDECIMAL} {
    numberOfErrors++;
    // fprintf(logs,"Error at line no %d: Too many decimal points %s\n\n",numberOfLines,yytext);
}

{ILLFORMEDERROR} {
    numberOfErrors++;
    // fprintf(logs,"Error at line no %d: Ill formed number %s\n\n",numberOfLines,yytext);
}

{INVALIDIDENTIFIER} {
    numberOfErrors++;
    // fprintf(logs,"Error at line no %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",numberOfLines,yytext);
}

{UNRECOGNIZEDCHARACTER} {
    numberOfErrors++;
    // fprintf(logs,"Error at line no %d: Unrecognized character constant error %s\n\n",numberOfLines,yytext);
}

{MULTICHARACTERERROR} {
    numberOfErrors++;
    // fprintf(logs,"Error at line no %d: Multi character constant error %s\n\n",numberOfLines,yytext);
}

{EMPTYCHARERROR} {
    numberOfErrors++;
    // fprintf(logs,"Error at line no %d: Empty character constant error %s\n\n",numberOfLines,yytext);
}


{UNFINISHEDCHARACTER} {
    numberOfErrors++;
    // fprintf(logs,"Error at line no %d: Unterminated character %s\n\n",numberOfLines,yytext);
}

. {
    numberOfErrors++;
    // fprintf(logs,"Error at line no %d: Unrecognized character %s\n\n",numberOfLines,yytext);
}

<<EOF>> {
    // symbolTable.printAllTable();  
    // fprintf(logs,"Total lines: %d\n",numberOfLines);
    // fprintf(logs,"Total errors: %d\n",numberOfErrors); 
    return 0;
}
%%

int yywrap(void){
    return 1;
}

// int main(int argc, char* argv[]){
//     if(argc != 2){
//         printf("Input filenames missing, Provide correct command line arguments\n");
//         return 0;
//     }
//     FILE *fin = fopen(argv[1], "r");
//     if(fin == NULL){
//         printf("File not found\n");
//         return 0;
//     }

//     logs = fopen("1705070_log.txt","w");
//     tokens = fopen("1705070_token.txt","w");
//     fprintf(logs, "\n");

//     yyin= fin;
//     yylex();
//     fclose(logs);
//     fclose(tokens);
//     fclose(yyin);
//     return 0;
// }
