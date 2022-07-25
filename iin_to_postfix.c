#include<stdio.h>


int top=-1;
char expp[100];
char Stack[100];



void push(char c)
{
	Stack[++top]=c;	
}


char pop()
{
	return Stack[top--];
}


char peek()
{
	return Stack[top];
}


int isoprand(char c)
{
	if(c=='+' || c=='-' || c=='/' ||c=='*' ||c=='(' || c==')' || c=='^')
		return 0;
	else 
		return 1;
}


int outstack(char ch)
{
	switch(ch)
	{
		case '+':
			return 1;
		case '-':
			return 1;
		
		case '/':
			return 3;
		
		case '*':
			return 3;
		
		case '^':
			return 6;
		
		case '(':
			return 7;
		
		case ')':
			return -5;	
	}
}

int instack(char ch)
{
	if (top==-1)
		return -1;
		switch(ch)
	{
		case '+':
			return 2;
		case '-':
			return 2;
		
		case '/':
			return 4;
		
		case '*':
			return 4;
		
		case '^':
			return 5;
		
		case '(':
			return 0;	
	}
}


int main()
{
	
	char postfix[100]={'\0'};
printf("Enter expression :  ");
scanf("%s",expp);
int i;
int j=0;
for(i=0;expp[i]!=0;i++)
{
	if(isoprand(expp[i]))
		postfix[j++]=expp[i];
	else
	{
		if(outstack(expp[i]) > instack(peek()))
		{
			push(expp[i]);
		}
		else if(outstack(expp[i])==-5)
		{
			while(peek()!='(')
			{
				postfix[j++]=pop();
			}
			pop();
		}
		else
		{
			while(outstack(expp[i]) <= instack(peek()))
				postfix[j++]=pop();
			push(expp[i]);	
		}
	}	
}
while(top!=-1)
	postfix[j++]=pop();
	

printf("\n\npostfix : %s ",postfix);


	return 0;
}



