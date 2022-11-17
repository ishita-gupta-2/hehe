%{
    #include<stdio.h>
%}

keyword      ^(else|int|void|if|else|while|return)$
integer      [+-]?([0-9]+)
reals        [+-]?([0-9]+)([.]|[E][+-]?|[.]([0-9]*)[E][+-]?)([0-9]+)
frac         ({reals}|{integer})[/]({reals}|{integer})
realNum      ^{reals}|{frac}$
ptr_op       ^[-][>]$
and_op       ^[&][&]$
or_op        ^[|][|]$
dot_op       ^[.]$
op           ^[-+*/]$
sep          ^[;{},=()&~\[\]]$

%%
{keyword}       {
                        int i=0;
                        for(i=0; yytext[i]!='\0';i++)
                        printf("%c",toupper(yytext[i]));
                }
{integer}       printf("INTEGER");
{realNum}       printf("REAL");
{ptr_op}       printf("PTR_OP");
{and_op}       printf("AND_OP");
{or_op}       printf("OR_OP");
{dot_op}       printf("DOT_OP");
{op}       printf("%s",yytext);
{sep}       printf("%s",yytext);
.*          printf("UNRECOGNIZED TOKEN");
%%

int yywrap(void){}

int main()
{
    yylex();
    return 0;
}

//  flex Lab4.l
//  gcc lex.yy.c
//  ./a.out