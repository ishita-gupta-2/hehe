%{
    #include<stdio.h>
%}

keyword      ^(begin|end|if|then|else|for|do|while|switch|case|default|berak|continue|goto)$
identifier   ^[a-zA-Z_][a-zA-Z0-9_]*
signInt      ^[+-]?([0-9]+)$
spl          ^[!@#$&*]([a-zA-Z0-9]*)$
start_end    ^[a-zA-Z]([!@#$&*_0-9]*)[a-zA-Z]$
dig_splorlet ^[0-9]([!@#$&*_a-zA-Z]*)$

%%
{keyword}       printf("%s --> KEYWORD",yytext);
{identifier}    printf("%s --> IDENTIFIER",yytext);
{signInt}       printf("%s --> SIGN_INT",yytext);
{spl}           printf("%s --> SPL",yytext);
{start_end}     printf("%s --> START_END",yytext);
{dig_splorlet}  printf("%s --> DIG_SPLORLET",yytext);
.*              printf("%s --> NO MATCH FOUND",yytext);
%%

int yywrap(void){}

int main()
{
    yylex();
    return 0;
}

//  flex Lab2.l
//  gcc lex.yy.c
//  ./a.out