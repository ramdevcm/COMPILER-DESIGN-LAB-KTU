%token ID NUM
%right '='
%left '+' '-'
%left '*' '/'
%left UMINUS

%%
S :	ID{push();} '='{push();} E{pop();};

E :	E '+'{push();} T{pop3();}
| E '-'{push();} T{pop3();}
| T;

T :	T '*'{push();} F{pop3();}
| T '/'{push();} F{pop3();}
| F;

F :	'(' E ')'
| '-'{push();} F{pop2();}
| ID{push();}
| NUM{push();};
%%
#include "lex.yy.c"
#include<ctype.h>

char st[100][10]; int top=0;
char i[2]="0";
char temp[2]="t";
main()
{
printf("Enter expression: ");
yyparse();
}
push()
{
strcpy(st[++top],yytext);
}
pop3()
{
strcpy(temp,"t");
strcat(temp,i);
printf("%s=%s%s%s\n",temp,st[top-2],st[top-1],st[top]);
top-=2;
strcpy(st[top],temp);
i[0]++;
}
pop2()
{
strcpy(temp,"t");
strcat(temp,i);
printf("%s=-%s\n",temp,st[top]);
top--;
strcpy(st[top],temp);
i[0]++;
}
pop()
{
printf("%s=%s\n",st[top-2],st[top]);
top-=2;
}