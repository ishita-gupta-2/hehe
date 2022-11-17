%{
    #include<stdio.h>
%}

ek      ^(([ab]*[cd]*)+)|[a][b]*[c]*[d]$
doo     ^([01]*|[0]*[1]*)$
teen    ^(([0][1]*[2])|([0]*[2]+[1]))+$

%%
{ek}        printf("%s --> first",yytext);
{doo}       printf("%s --> second",yytext);
{teen}      printf("%s --> third",yytext);
.*          printf("%s --> none",yytext);
%%

int yywrap(void){}

int main()
{
    yylex();
    return 0;
}

//  flex Lab5.l
//  gcc lex.yy.c
//  ./a.out