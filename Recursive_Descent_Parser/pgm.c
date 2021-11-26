#include<stdio.h>
#include<ctype.h>
char expr[20];

int i=0;
int T()
{

	if(F()==1)
	{
		if(TD()==1)
			return 1;
		else
			return 0;
	}
	else
		return 0;

}

int F()
{
     
	if(expr[i] == '(')
	{	 
		i++;
		if(E())
		{
			if(expr[i]==')')
			{
				i++;
				return 1;

			}
			else
				return 0;
		}
		else
			return 0;
	}

	else if(expr[i]>='a'&&expr[i]<='z'||expr[i]>='A'&&expr[i]<='Z')
	{
		i++;
		return 1;
	}
	else
		return 0;
}

int TD()
{
	
	if(expr[i] == '*' || expr[i] == '/')
	{
		i++;
		if(F()==1)
		{
			if(TD()==1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
			return 0;
	}
	else
	{
		
			return 1;
	}

}


int ED()
{
	
	if(expr[i] == '+' || expr[i] == '-')
	{
		i++;
		if(T()==1)
		{
			if(ED()==1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
			return 0;
	}
	else
	{
			return 1;
		
	}


}


int E()
{

	if(T()==1)
	{
		
		if(ED()==1)
			return 1;
		else
			return 0;
	}
	else
		return 0;

}


void main() 
{
	int E();
	int F();
	int T();
	int TD();
	int ED();

	printf("\nEnter the expression: ");
	scanf("%s",expr);
	printf("%s",expr);

	if(E()==1)
		printf("\nEntered expression is valid\n");
	else
		printf("\nEntered expression is invalid\n");

}
