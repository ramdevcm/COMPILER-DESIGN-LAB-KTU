%{
	#include "y.tab.h"
%}
%%
"if" {return IF;}
"else" {return ELSE;}
"&&" {return AND;}
"||" {return OR;}
"<" {return LT;}
"<=" {return LE;}
">" {return GT;}
">=" {return GE;}
"==" {return EQ;}
"!=" {return NE;}
[a-z]+ {return ALPHA;}
[0-9]+ {return NUM;}
[\t] ;
[\n] {return 0;}
. {return yytext[0];}
%%
int yywrap()
{
	return 1;
}
