#include<stdio.h>
int top=-1;
int i,j;
char stack[100];
int isoprand(char ch)
{
	if(ch=='+' || ch=='-' || ch=='/' || ch=='*'  || ch=='^' ||ch=='(' ||ch==')')
		return 0;
	else 
		return 1;
}
int outstack(char ch)
{
	switch(ch)
	{
		case '+':
		case '-': return 1;
		case '/':
		case '*': return 3;
		case '^': return 6;
		case '(': return 7;
		case ')': return 0;				
		
	}
}

int instack(char ch)
{
	switch(ch)
	{
		case '+':
		case '-': return 2;
		case '/':
		case '*': return 4;
		case '^': return 5;
		case '(': return 0;			
	}
}


void push(char c)
{
	stack[++top]=c;
}

char pop()
{
	char r=stack[top--];
	return r;
}

char peek()
{
	return stack[top];
}


int main()
{
	char exp[100], postfix[100];
	printf("Enter the expression : ");
	scanf("%s",exp);
	j=0;
	for(i=0;exp[i]!=0;i++)
	{	
		if(isoprand(exp[i]))
			postfix[j++]=exp[i];
		else
		{
			if(top==-1 || outstack(exp[i])>instack(peek()))
				push(exp[i]);
			else
			{
				if(exp[i]==')')
				{
					while(peek()!='(')
						postfix[j++]=pop();
					pop();	
				}
				else
				{
					postfix[j++]=pop();
					push(exp[i]);
				}
			}	
		}			
	}
	while(top!=-1)
		postfix[j++]=pop();
	postfix[j++]='\0';
	printf("\n\nExpression in postfix : %s",postfix);

	return 0;
}
