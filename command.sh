flex -o lex.c LexicalAnalyzer.l
g++ lex.c -lfl -o lex.out
./lex.out input.txt
