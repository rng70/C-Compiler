/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_1705070_BACKUP_TAB_H_INCLUDED
# define YY_YY_1705070_BACKUP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FOR = 258,                     /* FOR  */
    IF = 259,                      /* IF  */
    DO = 260,                      /* DO  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    VOID = 263,                    /* VOID  */
    COMMA = 264,                   /* COMMA  */
    SEMICOLON = 265,               /* SEMICOLON  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    DOUBLE = 268,                  /* DOUBLE  */
    CHAR = 269,                    /* CHAR  */
    RETURN = 270,                  /* RETURN  */
    CONTINUE = 271,                /* CONTINUE  */
    PRINTLN = 272,                 /* PRINTLN  */
    ASSIGNOP = 273,                /* ASSIGNOP  */
    LPAREN = 274,                  /* LPAREN  */
    RPAREN = 275,                  /* RPAREN  */
    LCURL = 276,                   /* LCURL  */
    RCURL = 277,                   /* RCURL  */
    LTHIRD = 278,                  /* LTHIRD  */
    RTHIRD = 279,                  /* RTHIRD  */
    CONST_INT = 280,               /* CONST_INT  */
    CONST_FLOAT = 281,             /* CONST_FLOAT  */
    CONST_CHAR = 282,              /* CONST_CHAR  */
    ADDOP = 283,                   /* ADDOP  */
    MULOP = 284,                   /* MULOP  */
    LOGICOP = 285,                 /* LOGICOP  */
    BITOP = 286,                   /* BITOP  */
    RELOP = 287,                   /* RELOP  */
    INCOP = 288,                   /* INCOP  */
    DECOP = 289,                   /* DECOP  */
    ID = 290,                      /* ID  */
    NOT = 291,                     /* NOT  */
    LOWER_PREC_THAN_ELSE = 292     /* LOWER_PREC_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 77 "1705070_backup.y"

    SymbolInfo* symbolInfoPointer;

#line 105 "1705070_backup.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_1705070_BACKUP_TAB_H_INCLUDED  */
