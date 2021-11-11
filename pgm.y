%{
	#include<stdio.h>
	#include "lex.yy.c"
	#include<ctype.h>
	
	char i[2]="0";
	char T[2]="t";
	char stack[100];
	int top=-1;
%}

%token ID NUM;
%left '+''-'
%left '*''/'
%right '='
%%
S: ID{push();} '=' {push();} E{pop();}
;
E:E'+'{push();} T{pop3();}
   |T
   ;
T:T'*'{push();}F{pop3();}
   |F
   ;
F:ID{push();}
   | NUM{push();}
   | '('E')'
   ;
  /* | '-'{push();} F{pop2();} */
%%

main()
{
	printf("\nEnter the expression: ");
	yyparse();
	
}
pop3()
{
	strcpy(T,"t");
	strcat(T,i);
	printf("%s = %s%s%s",T,stack[top-2],stack[top-1],stack[top]);
	top = top-2;
	strcpy(stack[top],T);
	i[0]++;
}

pop()
{
	printf("%s = %s\n",stack[top-1],stack[top]);
	top = top-1;
}

push()
{
	strcpy(stack[++top],yytext);
}





