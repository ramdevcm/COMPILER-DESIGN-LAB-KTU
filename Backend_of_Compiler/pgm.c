#include<string.h>
#include<stdio.h>

void main()
{
	char str[20],operator[10],icode[10][10];
	int n,i=0;

	printf("Input the number of lines of code : ");
	scanf("%d",&n);

	printf("Input the intermediate code sets : \n");
	do
 	{
		scanf("%s",&icode[i]);
		i++;
	}while(i!=n);
	
	printf("\nCORRESPONDING TARGET CODE : \n");
	i=0;
	do
	{
	  	strcpy(str,icode[i]);	
		switch(str[3])
	  	{
			case '+': 
                 strcpy(operator,"ADD");
				 break;
			
			case '-':
                 strcpy(operator,"SUB");
				 break;

			case '*':
                 strcpy(operator,"MUL");
				 break;

        	case '/':
                 strcpy(operator,"DIV");
				 break;
  
			default :
                 printf("Invalid");
				 break;
        }			
		printf("\nMOV %c,R%d",str[2],i);
		printf("\n%s %c,R%d",operator,str[4],i);
		printf("\nMOV R%d,%c",i,str[0]);
		i++;
	 }while(i!=n);
	 printf("\n");
}