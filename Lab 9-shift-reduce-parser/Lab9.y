%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token ID
%token ADD SUB MUL DIV POW OP CP
%token EOL

%%
calclist:
| calclist E EOL    {printf("RESULT: %d\n",$2);}
;
E : T
| E ADD T       {$$ = $1 + $3;}
| E SUB T       {$$ = $1 - $3;}
;
T : F
| T MUL F       {$$ = $1 * $3;}
| T DIV F       {$$ = $1 / $3;}
;
F : P
| P POW F       {$$ = $1; int i; for(i=1;i<$3;i++) $$ *= $1;}
;
P : X
| SUB P         {$$ = -$2;}
;
X : ID          {$$ = $1;}
| OP E CP       {$$ = $2;}
;
%%

int yyerror(char *msg)
{
    printf("\nInvalid Expression\n");
    exit(0);
}

main()
{
    yyparse();
}