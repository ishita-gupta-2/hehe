%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token a b c

%%
S : c A | c c B;
A : c A | a;
B : c c B | b;
%%

int main()
{
    while(1)
    {
        yyparse();
        prinyf("success\n");
    }
    return 0;
}

int yyerror(char*s)
{
    printf("unsuccess\n");
    exit(0);
}