%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token a b c

%%
S : a S a | b S b | a c a | b c b;
%%

int main()
{
    while(1)
    {
        yyparse();
        printf("Palindrome\n");
    }
    exit(0);
}

int yyerror(char *msg)
{
    printf("Not Palindrome\n");
    exit(0);
}