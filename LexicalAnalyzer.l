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

SymbolTable symbolTable(10);

void filePrint(int number_of_lines, char* a, char* b, FILE* tokens, FILE* logs, int fileNumber=0)
{
    if(!fileNumber){
    fprintf(tokens,"%s",a);}
    else{fprintf(tokens,"<%s,%s>",a,b);}
    fprintf(logs,"Line no. %d: TOKEN %s Lexeme %s found\n\n",number_of_lines,a,b);
}

void print_to_files_32(int number_of_lines, char* a, char* b, FILE* tokens, FILE* logs)
{
    fprintf(tokens,"<%s,%s>",a,b);
    fprintf(logs,"Line no. %d: TOKEN <%s> Lexeme %s found\n\n",number_of_lines,a,b);
}
%}

/* Declare Lex styled macros */
WHITESPACE [ \t\r\f\v]
LETTERS [a-zA-Z]
DIGIT [0-9]
EXP [Ee][+-]?[0-9]+
NEWLINE \n
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*fin
MULOP "*"|"/"|"%"
RELOP "<"|"<="|">"|">="|"!="|"=="
LOGICOP "||"|"&&"
BITOP "|"|"&"|"<<"|">>"|"^"
FLOATINGPOINT (({DIGIT}*([\.]?{DIGIT}+))|({DIGIT}+[\.]?{DIGIT}+)){EXP}?
CHARACTERLITERALS '[^\n\\]'
TOOMANYDECIMAL     {DIGIT}*([\.]{DIGIT}*)+([\.]+{DIGIT}*)+{EXP}?
ILLFORMEDERROR     {DIGIT}*([\.]+{DIGIT}*)*?([Ee][+-]?([0-9]+)?([\.]*{DIGIT}*)+)+
INVALIDIDENTIFIER  {FLOATINGPOINT}{IDENTIFIER}
MULTICHARACTERERROR   '[^\n][^\n]+'
UNFINISHEDCHARACTER   '[\\]'|'[^\n\']*|'\\[nt\\afr"bv0]|'\\
EMPTYCHARERROR        ''
UNRECOGNIZEDCHARACTER '(\\[^nt\\afr"bv0\n])+'

%%
{WHITESPACE}+ {}
{NEWLINE} {number_of_lines++;}

"if" {
    char c[] = "<IF>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"else" {
    char c[] = "<ELSE>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"for" {
    char c[] = "<FOR>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"while" {
    char c[] = "<WHILE>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"do" {
    char c[] = "<DO>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"break" {
    char c[] = "<BREAK>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"int" {
    char c[] = "<INT>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"char" {
    char c[] = "<CHAR>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"float" {
    char c[] = "<FLOAT>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"double" {
    char c[] = "<DOUBLE>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"void" {
    char c[] = "<VOID>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"return" {
    char c[] = "<RETURN>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"swithc" {
    char c[] = "<SWITCH>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"case" {
    char c[] = "<CASE>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"default" {
    char c[] = "<DEFAULT>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}
"continue" {
    char c[] = "<CONTINUE>";
    filePrint(number_of_lines, c, yytext, tokens, logs);
}

{DIGIT}+ {
    char c[] = "CONST_INT";
    filePrint(number_of_lines,c,yytext,tokens,logs, 1);
                s.InsertMod(yytext,"CONST_INT");
}

{DIGIT}+ {
    char c[] = "CONST_INT";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
                s.InsertMod(yytext,"CONST_INT");
}

{FLOATINGPOINT}+ {
    char c[] = "CONST_FLOAT";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
                s.InsertMod(yytext,"CONST_FLOAT");
}

{CHARACTERLITERALS} {
    char c[] = "CONST_CHAR";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
                s.InsertMod(yytext,"CONST_CHAR");
}

'\\[nt\\afr"bv0]' {
        switch(yytext[2])
    {
        case 't':   fprintf(tokens,"<CONST_CHAR,%c>",'\t');
                    break;
        case 'n':   fprintf(tokens,"<CONST_CHAR,%c>",'\n');
                    break;
        case '\\':  fprintf(tokens,"<CONST_CHAR,%c>",'\\');
                    break;
        case '"' :  fprintf(tokens,"<CONST_CHAR,%c>",'"');
                    break;
        case 'a' :  fprintf(tokens,"<CONST_CHAR,%c>",'\a');
                    break;
        case 'f' :  fprintf(tokens,"<CONST_CHAR,%c>",'\f');
                    break;
        case 'r' :  fprintf(tokens,"<CONST_CHAR,%c>",'\r');
                    break;
        case 'b' :  fprintf(tokens,"<CONST_CHAR,%c>",'\b');
                    break;
        case 'v' :  fprintf(tokens,"<CONST_CHAR,%c>",'\v');
                    break;
        case '0' :  fprintf(tokens,"<CONST_CHAR,%c>",'\0');
                    break;
    }     
                
    fprintf(logs,"Line no. %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",number_of_lines,yytext);
    s.InsertMod(yytext,"CONST_CHAR");
}

"+"|"-" {
    char c[] = "ADDOP";
    filePrint(number_of_lines,c,yytext,tokens,logs, 1);
    s.InsertMod(yytext,"ADDOP");
}

"++"|"--" {       
    char c[] = "INCOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"INCOP");
}

{MULOP} {    
    char c[] = "MULOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"MULOP");
}
{RELOP} {    
    char c[] = "RELOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"RELOP");
}

{LOGICOP} {        
    char c[] = "LOGICOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"LOGICOP");
}

{BITOP} {
    char c[] = "BITOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"BITOP");
}
"=" {        
    char c[] = "ASSIGNOP";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"ASSIGNOP");
}

"!" {            
    char c[] = "NOT";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"NOT");
}

"(" {          
    char c[] = "LPAREN";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"LPAREN");
}

")" {
    char c[] = "RPAREN";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"RPAREN");
}

"{" {            
    char c[] = "LCURl";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"LCURL");
}

"}" {
    char c[] = "RCURL";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"RCURL");
}

"[" {
    char c[] = "LTHIRD";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"LTHIRD");
}

"]" {          
    char c[] = "RTHIRD";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"RTHIRD");
}

"," {
    char c[] = "COMMA";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"COMMA");
}

";" {
    char c[] = "SEMICOLON";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"SEMICOLON");
}

{IDENTIFIER}  {           
    char c[] = "ID";
    filePrint(number_of_lines,c,yytext,tokens,logs,1);
    s.InsertMod(yytext,"ID");
}

"//" {
    BEGIN COMMENTSINGLE;
    s1 = s1+yytext;
    linestart = number_of_lines;
}

<COMMENTSINGLE>\n {     
    fprintf(logs,"Line no. %d: TOKEN <COMMENT> Lexeme %s found\n\n",linestart,s1.c_str());
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
    fprintf(logs,"Line no. %d: TOKEN <COMMENT> Lexeme %s found\n\n",linestart,s1.c_str());
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
    fprintf(logs,"Error observed at Line No:%d: Unterminated Comment: %s\n\n",linestart,s1.c_str());
    s1 = "";
    number_of_errors++;
    
    fprintf(logs,"Total Line No:%d\n",--number_of_lines);
    fprintf(logs,"Total Errors:%d\n\n",number_of_errors); 
    return 0;
}

\" {
    BEGIN STRINGSTATE;
    s1 = s1+yytext;
    linestart = number_of_lines;  
}

<STRINGSTATE>\" {     
    s1 = s1+yytext;
    fprintf(logs,"Line no. %d: TOKEN <STRING> Lexeme %s found\n\n",linestart,s1.c_str());
    fprintf(tokens,"<STRING ,%s>",s2.c_str());
    s1 = "";
    s2 = "";
    BEGIN INITIAL;
    
}

<STRINGSTATE>\n {
    number_of_lines++;
    fprintf(logs,"Error observed at Line No:%d: Unterminated string: %s\n\n",linestart,s1.c_str());
    s1 = "";
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
    fprintf(logs,"Error at line %d: Too many decimal point: %s\n\n",number_of_lines,yytext);
}

{ILLFORMEDERROR} {
    number_of_errors++;
    
    fprintf(logs,"Error at line %d: Ill formed Number: %s\n\n",number_of_lines,yytext);
}

{INVALIDIDENTIFIER} {
    number_of_errors++;
    
    fprintf(logs,"Error at line %d: Invalid prefix on ID or invalid suffix on Number: %s\n\n",number_of_lines,yytext);

}

{UNRECOGNIZEDCHARACTER} {
    number_of_errors++;
    
    fprintf(logs,"Error at line %d: Unrecognized character constant error: %s\n\n",number_of_lines,yytext);

}

{MULTICHARACTERERROR} {
    number_of_errors++;
    
    fprintf(logs,"Error at line %d: Multi character constant error: %s\n\n",number_of_lines,yytext);

}

{EMPTYCHARERROR} {
    number_of_errors++;
    
    fprintf(logs,"Error at line %d: Empty character constant error: %s\n\n",number_of_lines,yytext);
}


{UNFINISHEDCHARACTER} {
    number_of_errors++;
    
    fprintf(logs,"Error at line %d: Unterminated character: %s\n\n",number_of_lines,yytext);
}

<<EOF>> {  
    fprintf(logs,"Total Line No:%d\n",--number_of_lines);
    fprintf(logs,"Total Errors:%d\n\n",number_of_errors); 
    return 0;
}
%%

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Input filename\(s\) missing. Provide correct command line arguments\n");
        return 0;
    }
    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL){
        printf("File not found\n");
        return 0;
    }

    logs = fopen("1705070_log.txt","w");
    tokens = fopen("1705070_token.txt","w");

    yyin= fin;
    yylex();
    fclose(logs);
    fclose(tokens);
    fclose(yyin);
	return 0;
}
