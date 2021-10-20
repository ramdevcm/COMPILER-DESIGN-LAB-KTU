%{
   /* Definition section */
  #include<stdio.h>
  #include "y.tab.h"
  extern int yylval;
%}
  
/* Rule Section */
%%
[0-9]+ {
          yylval=atoi(yytext);
          return NUMBER;
  
       }

[a-zA-Z]+ {
          return ID;
       }

[\t] ;              //skip whitespace
  
[\n] return 0;      //skip lines by returning 0
  
. return yytext[0]; //anything other than above things
  
%%
  
int yywrap()        //to return 1 when EOF is encountered
{
 return 1;
}