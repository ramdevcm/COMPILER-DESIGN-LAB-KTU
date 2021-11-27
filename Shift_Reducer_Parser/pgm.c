//shift reducive parser
#include<stdio.h>
#include<string.h>
int z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];

void parser()
{
     strcpy(ac,"REDUCE TO S");
     for(z=0; z<c; z++)
       if(stk[z]=='i' && stk[z+1]=='d')
       {
           printf("\n$%s\t%s$\t%s\n",stk,a,ac);
           stk[z]='S';
           stk[z+1]='\0';         
           j++;
       }
       
     for(z=0; z<c; z++)
       if(stk[z]=='S' && stk[z+1]=='+' && stk[z+2]=='S')
       {
           printf("\n$%s\t%s$\t%s\n",stk,a,ac);
           stk[z]='S';
           stk[z+1]='\0';
           stk[z+2]='\0';           
           i=i-2;
       }
     for(z=0; z<c; z++)
       if(stk[z]=='S' && stk[z+1]=='*' && stk[z+2]=='S')
       {
           printf("\n$%s\t%s$\t%s\n",stk,a,ac);
           stk[z]='S';
           stk[z+1]='\0';
           stk[z+1]='\0';          
           i=i-2;
       }          
}

void main()
{

      printf("The entered GRAMMAR should be in the form \n S->S+S \n S->S*S \n S->id");
      printf("\nEnter input string:\t");
      scanf("%s",a);
      c=strlen(a);
      strcpy(act,"SHIFT->");
      printf("STACK \t INPUT \t ACTION");
           
      for(i=0; j<c;i++,j++)
      {
      	 	
         if(a[j]=='i' && a[j+1]=='d')
         {
         	  printf("\n$%s\t%s$\t%sid\n",stk,a,act); 
              stk[i]=a[j];
              stk[i+1]=a[j+1];
              stk[i+2]='\0';
              a[j]=' ';
              a[j+1]=' ';                     
              parser();
         }	
         else 
         {     	
         	  printf("\n$%s\t%s$\t%ssymbols\n",stk,a,act); 
              stk[i]=a[j];
              stk[i+1]='\0';
              a[j]=' ';               
              parser();
         }
       }
       if(a[0]==' ' && stk[0]=='S' && stk[1] == NULL)
       {
         	strcpy(act,"ACCEPTED");
         	printf("\n$%s\t%s$\t%s\n",stk,a,act); 
       }
       else
       {
      		strcpy(act,"REJECTED");
         	printf("\n$%s\t%s$\t%s\n",stk,a,act); 
       }
       
}