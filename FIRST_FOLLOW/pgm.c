#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int n,m=0,p,i=0,j=0;
char a[10][10],f[10],fr[10];
void first(char c);
void follow(char c);
void followfirst(char c);
void main()
{
    int i,z;
    char c,ch;
    printf("\nEnter the no of productions:\n");
    scanf("%d",&n);
    printf("\n   Enter the productions:\n");
    for(i=0;i<n;i++)
        scanf("%s%c",a[i],&ch);
    do
    {
        m=0;
        printf("\nEnter the elemets whose first & follow is to be found:");
        scanf("%c",&c);
        first(c);
        printf("First(%c)={",c);
        for(i=0;i<m;i++)
            printf(" %c ",fr[i]);
        printf("}\n");
        strcpy(f," ");
        m=0;
        follow(c);
        printf("Follow(%c)={",c);
        for(i=0;i<m;i++)
            printf(" %c ",f[i]);
        printf("}\n");
        printf("Continue(0/1)?");
        scanf("%d%c",&z,&ch);
        printf("\n");
    }while(z==1);
   
}


void first(char c)
{
    int j;
    if(!(isupper(c)))
        fr[m++]=c;
    for(j=0;j<n;j++)
    {
        if(a[j][0]==c)
        {
            if(a[j][2]=='$')
                fr[m++]='$';
            else if(islower(a[j][2]))
                fr[m++]=a[j][2];
            else
            {
                first(a[j][2]);
                fr[m--]-='$';
                first(a[j][3]);
            }
        }
    }
}


void followfirst(char c)
{
    int k;
    if(!isupper(c))
        f[m++]=c;
    for(k=0;k<n;k++)
    {
        if(a[k][0]==c)
        {
            if(a[k][2]=='$')
                follow(a[k][0]);
            else if(islower(a[k][2]))
                f[m++]=a[k][2];
            else 
                followfirst(a[k][2]);
        }
    }
}


void follow(char c)
{
    if(a[0][0]==c)
    f[m++]='$';
    for(i=0;i<n;i++)
    {
        for(j=2;j<strlen(a[i]);j++)
        {
            if(a[i][j]==c)
            {
                if(a[i][j+1]!='\0')
                    followfirst(a[i][j+1]);
                if(a[i][j+1]=='\0' && c!=a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}