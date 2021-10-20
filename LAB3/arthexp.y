%{
   /* Definition section */
  #include<stdio.h>
  int flag=0;
%}
  
%token NUMBER
  
%left '+' '-'
  
%left '*' '/' '%'
  
%left '(' ')'
  
/* Rule Section */
%%
  
E: 
    T{
  
         printf("\nResult=%d\n", $$);   //to print result value
  
         return 0;
  
    };
 T: 
    T'+'T {$$=$1+$3;}
  
    |T'-'T {$$=$1-$3;}
    
    |T'*'T {$$=$1*$3;}
    
    |T'/'T {$$=$1/$3;}
    
    |T'%'T {$$=$1%$3;}
    
    |'('T')' {$$=$2;}
    
    | NUMBER {$$=$1;}
  
 ;
  
%%
  
//driver code
void main()
{
   printf("\nEnter Any Arithmetic Expression which 
                   can have operations Addition, 
                   Subtraction, Multiplication, Division, 
                          Modulus and Round brackets:\n");
  
   yyparse();
   if(flag==0)
   printf("\nEntered arithmetic expression is Valid\n\n");
}
  
void yyerror()
{
   printf("\nEntered arithmetic expression is Invalid\n\n");
   flag=1;
}