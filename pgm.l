%{
	#include "y.tab.h"
%}

%%
[a-zA-Z]+ { return ID; }
[0-9]+ { 
	yylval=atoi(yytext);
	return NUM; 
}
. { return yytext[0]; }
%%
int yywrap()
{
	return 1;
}

