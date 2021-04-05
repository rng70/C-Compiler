%option noyywrap

%x STRINGSTATE
%x COMMENTMULTI
%X COMMENTSINGLE

%{
#include <bits/stdc++.h>
#include "SymbolTable.cpp"

using namespace std;

int number_of_lines = 1;
int number_of_errors = 0;
int linestart;
string s1 = "";
string s2 = "";

SymbolTable symbolTable(7);

void filePrint(int number_of_lines, char* a, char* b, FILE* tokens, FILE* logs, int fileNumber=0)
{
    if(!fileNumber){
        fprintf(tokens,"<%s> ",a);
    }else{
        if(!strcmp(a, "CONST_CHAR")){
            string mn(b);
            mn.erase(0,1);
            mn.erase(mn.size()-1,1);
            fprintf(tokens, "<CHAR_CONST, %s> ", mn.c_str());
        }else{
            fprintf(tokens,"<%s, %s> ",a,b);
        }
    }
    fprintf(logs,"Line no %d: Token <%s> Lexeme %s found",number_of_lines,a,b);
    if(!strcmp(a, "CONST_CHAR")){
        string str1(b);
        str1.erase(0, 1);
        str1.erase(str1.size()-1, 1);
        fprintf(logs, " --> <CHAR_CONST, %s> \n\n", str1.c_str());
    }else{
        fprintf(logs, "\n\n");
    }
}
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
{NEWLINE} {number_of_lines++;}

"if" {
    char c[] = "IF";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"else" {
    char c[] = "ELSE";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"for" {
    char c[] = "FOR";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"while" {
    char c[] = "WHILE";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"do" {
    char c[] = "DO";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"break" {
    char c[] = "BREAK";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"int" {
    char c[] = "INT";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"char" {
    char c[] = "CHAR";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"float" {
    char c[] = "FLOAT";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"double" {
    char c[] = "DOUBLE";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"void" {
    char c[] = "VOID";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"return" {
    char c[] = "RETURN";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"switch" {
    char c[] = "SWITCH";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"case" {
    char c[] = "CASE";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"default" {
    char c[] = "DEFAULT";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"continue" {
    char c[] = "CONTINUE";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}

{DIGIT}+ {
    char c[] = "CONST_INT";
    filePrint(number_of_lines,c,yytext,tokens,logs, 1);
    symbolTable.InsertWithoutReturn(yytext,"CONST_INT");
}

{FLOATINGPOINT} {
    char c[] = "CONST_FLOAT";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    symbolTable.InsertWithoutReturn(yytext,"CONST_FLOAT");
}

{CHARACTERLITERALS} {
    char c[] = "CONST_CHAR";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    symbolTable.InsertWithoutReturn(yytext,"CONST_CHAR");
}

'\\[nt\\\'afr"bv0]' {
    char char1;
        switch(yytext[2])
        {
            case 't':   char1 = '\t';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\t');
                        break;
            case 'n':   char1 = '\n';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\n');
                        break;
            case '\\':  char1 = '\\';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\\');
                        break;
            case '"' :  char1 = '"';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'"');
                        break;
            case 'a' :  char1 = '\a';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\a');
                        break;
            case 'f' :  char1 = '\f';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\f');
                        break;
            case 'r' :  char1 = '\r';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\r');
                        break;
            case 'b' :  char1 = '\b';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\b');
                        break;
            case 'v' :  char1 = '\v';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\v');
                        break;
            case '0' :  char1 = '\0';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\0');
                        break;
            case '\'':  char1 = '\'';
                        fprintf(tokens,"<CHAR_CONST, %c> ",'\'');
                        break;
        }     
                
    fprintf(logs,"Line no %d: Token <CONST_CHAR> Lexeme %sfound --> <CHAR_CONST, %c> \n\n",number_of_lines,yytext, char1);
    symbolTable.InsertWithoutReturn(yytext,"CONST_CHAR");
}

"+"|"-" {
    char c[] = "ADDOP";
    filePrint(number_of_lines,c,yytext,tokens,logs, 1);
}

"++"|"--" {       
    char c[] = "INCOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

{MULOP} {    
    char c[] = "MULOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

{RELOP} {    
    char c[] = "RELOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

{LOGICOP} {        
    char c[] = "LOGICOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

{BITOP} {
    char c[] = "BITOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

"=" {        
    char c[] = "ASSIGNOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

"!" {            
    char c[] = "NOT";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

"(" {          
    char c[] = "LPAREN";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

")" {
    char c[] = "RPAREN";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

"{" {            
    char c[] = "LCURL";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    symbolTable.EnterScope();
}

"}" {
    char c[] = "RCURL";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    symbolTable.ExitScope();
}

"[" {
    char c[] = "LTHIRD";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

"]" {          
    char c[] = "RTHIRD";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

"," {
    char c[] = "COMMA";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

";" {
    char c[] = "SEMICOLON";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
}

{IDENTIFIER}  {           
    char c[] = "ID";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    symbolTable.InsertWithoutReturn(yytext,"ID");
}

"//" {
    BEGIN COMMENTSINGLE;
    s1 = s1+yytext;
    linestart = number_of_lines;
}

<COMMENTSINGLE>\n {     
    fprintf(logs,"Line no %d: Token <COMMENT> Lexeme %s found\n\n",linestart,s1.c_str());
    number_of_lines++;
    s1 = "";
    s2 = "";
    BEGIN INITIAL;
}

<COMMENTSINGLE>[^\n] {   
    s1 = s1+yytext;
}

<COMMENTSINGLE>\\\n {
    number_of_lines++;
    s1 = s1+yytext;
}

"/*" {
    BEGIN COMMENTMULTI;
    s1 = s1+yytext;
    linestart = number_of_lines;
}

<COMMENTMULTI>"*/" {
    s1 = s1+yytext;
    fprintf(logs,"Line no %d: Token <COMMENT> Lexeme %s found\n\n",linestart,s1.c_str());
    s1 = "";
    linestart = 0;
    BEGIN INITIAL;
}

<COMMENTMULTI>\n {
    s1 = s1+yytext;
    number_of_lines++;
}

<COMMENTMULTI>.|[^*\n] {
    s1 = s1+yytext;
}

<COMMENTMULTI><<EOF>> { 
    fprintf(logs,"Error at line no %d: Unterminated Comment %s\n\n",linestart,s1.c_str());
    s1 = "";
    number_of_errors++;
    symbolTable.printAllTable();
    fprintf(logs,"Total lines: %d\n",number_of_lines);
    fprintf(logs,"Total errors: %d\n",number_of_errors); 
    return 0;
}

\" {
    BEGIN STRINGSTATE;
    s1 = s1+yytext;
    linestart = number_of_lines;  
}

<STRINGSTATE>\" {     
    s1 = s1+yytext;
    fprintf(logs,"Line no %d: Token <STRING> Lexeme %s found --> <STRING, \"%s\"> \n\n",linestart,s1.c_str(), s2.c_str());
    fprintf(tokens,"<STRING, \"%s\"> ", s2.c_str());
    s1 = "";
    s2 = "";
    BEGIN INITIAL;
}

<STRINGSTATE>\n {
    number_of_lines++;
    fprintf(logs,"Error at line no %d: Unterminated String %s\n\n",linestart,s1.c_str());
    s1 = "";
    s2 = "";
    number_of_errors++;    
    BEGIN INITIAL;
}

<STRINGSTATE>\\\n {
    number_of_lines++;
    s1 = s1+yytext;
}

<STRINGSTATE>\\[nt\\afr"bv0] {   
    switch(yytext[1])
    {
    case 'n':  s2 = s2+'\n';
                break;
    case 't':  s2 = s2+'\t';
                break;
    case '\\': s2 = s2+'\\';
                break;
    case 'a':  s2 = s2+'\a';
                break;
    case 'f':  s2 = s2+'\f';
                break;
    case 'r':  s2 = s2+'\r';
                break;
    case '"':  s2 = s2+'\"';
                break;
    case 'b':  s2 = s2+'\b';
                break; 
    case 'v':  s2 = s2+'\v';
                break;
    case '0':  s2 = s2+'\0';
                break;
    }
    s1 = s1+yytext;
}

<STRINGSTATE>[^\n"\\] {
    s1 = s1+yytext;
    s2 = s2+yytext;
}

<STRINGSTATE>\\ { s1 = s1+yytext;}

{TOOMANYDECIMAL} {
    number_of_errors++;
    fprintf(logs,"Error at line no %d: Too many decimal points %s\n\n",number_of_lines,yytext);
}

{ILLFORMEDERROR} {
    number_of_errors++;
    fprintf(logs,"Error at line no %d: Ill formed number %s\n\n",number_of_lines,yytext);
}

{INVALIDIDENTIFIER} {
    number_of_errors++;
    fprintf(logs,"Error at line no %d: Invalid prefix on ID or invalid suffix on Number %s\n\n",number_of_lines,yytext);
}

{UNRECOGNIZEDCHARACTER} {
    number_of_errors++;
    fprintf(logs,"Error at line no %d: Unrecognized character constant error %s\n\n",number_of_lines,yytext);
}

{MULTICHARACTERERROR} {
    number_of_errors++;
    fprintf(logs,"Error at line no %d: Multi character constant error %s\n\n",number_of_lines,yytext);
}

{EMPTYCHARERROR} {
    number_of_errors++;
    fprintf(logs,"Error at line no %d: Empty character constant error %s\n\n",number_of_lines,yytext);
}


{UNFINISHEDCHARACTER} {
    number_of_errors++;
    fprintf(logs,"Error at line no %d: Unterminated character %s\n\n",number_of_lines,yytext);
}

. {
    number_of_errors++;
    fprintf(logs,"Error at line no %d: Unrecognized character %s\n\n",number_of_lines,yytext);
}

<<EOF>> {
    symbolTable.printAllTable();  
    fprintf(logs,"Total lines: %d\n",number_of_lines);
    fprintf(logs,"Total errors: %d\n",number_of_errors); 
    return 0;
}
%%

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Input filenames missing, Provide correct command line arguments\n");
        return 0;
    }
    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL){
        printf("File not found\n");
        return 0;
    }

    logs = fopen("1705070_log.txt","w");
    tokens = fopen("1705070_token.txt","w");
    fprintf(logs, "\n");

    yyin= fin;
    yylex();
    fclose(logs);
    fclose(tokens);
    fclose(yyin);
    return 0;
}
