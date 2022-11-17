%{
    #include "sample.tab.h"
    int yyval;
%}

%%
"+"     {return ADD;}
"-"     {return SUB;}
"*"     {return MUL;}
"/"     {return DIV;}
"^"     {return POW;}
"("     {return OP;}
")"     {return CP;}
[0-9]+  {yylval = atoi(yytext); return ID;}
\n      {return EOL;}
[ \t]   {}
.       {printf("Invalid String\n"); exit(0);}
%%

//  yacc -d sample.y
//  lex sample.l
//  cc lex.yy.c sample.tab.c -lfl
//  ./a.out