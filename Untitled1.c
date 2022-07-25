#include<stdio.h>
int top=-1;
int stack[100];

int isoprand(char ch)
{
	if(ch=='+' || ch=='-'  || ch=='*' || ch=='/' || ch=='^')
		return 0;
	else
	 	return 1;	
}

int main()
{
	char exp[100];
	
	int i,a,b,r;
	
	printf("Enter expression : ");
	scanf("%s",exp);
	for (i=0;exp[i]!=0;i++)
	{
		
	}
	
	return 0;
}
