%{
    #include "lab10.tab.h"
%}

%%
"a"         {return a;}
"b"         {return b;}
"c"         {return c;}
[ \t\n]     {return 0;}
.           {return yytext[0];}
%%

//  bison -d lab10.y
//  flex lab10.l
//  cc lex.yy.c lab10.tab.c -lfl
//  ./a.out