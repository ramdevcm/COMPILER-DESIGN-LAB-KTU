%{
	#include<stdio.h>
%}
%token 	NUM ALPHA IF ELSE AND OR GT GE LT  LE EQ NE
%left  '+' '-'
%left  '*' '/'
%right '^'
%right '='
%nonassoc UNIMUS 
%nonassoc IF
%nonassoc ELSE
%left GT GE LT LE EQ NE
%left AND OR 
%%
S:ST {printf("\nAccepted\n");}
ST:IF'('F')''{'ST'}'
   | IF'('F')''{'ST'}'ELSE'{'ST'}'
   | E';'
F: C LO C
   |C
LO: AND
   | OR
C: E RELOP E
E: ALPHA'='E
   | E'+'E
   | E'-'E
   | E'*'E
   | E'/'E
   | E'^'E
   |'-'E
   |ALPHA
   |NUM
RELOP: GT
      |GE	
      |LT 
      |LE 
      |EQ 
      |NE
ST: E';'ST
   |E';'
%%
int main()
{ 
	printf("Enter the expression:\n");
	yyparse();
}
int yyerror(char* s)
{
 	printf("\n Expression is invalid. \n");
}

      	



