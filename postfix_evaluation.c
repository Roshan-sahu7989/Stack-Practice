#include<stdio.h>
#include<stdlib.h>
#include "ItoP"
typedef struct stack stack;
struct stack
{
	int top;
	int* ptr;
};
int isoprand(char c)
{
	if(c=='+' ||c=='-' ||c=='/' ||c=='*' ||c=='^' )
		return 0;
	else
		return 1;	
}

void push(stack* a,int ch)
{
	a->ptr[++a->top]=ch;
}

int pop(stack* a)
{
	return a->ptr[a->top--];
}

int operation(int a,int b,char ch)
{
	
	switch(ch)
	{
		case '+': return b+a;
		case '-': return b-a;
		case '*': return b*a;
		case '/': return b/a;
	}
}
int main()
{
	int x,y,r;
	stack a;
	a.top=-1;
	a.ptr=(int*)malloc(100*sizeof(int));
	char s[100];
	printf("Enter postfix expression : ");
	scanf("%s",s);

	for (int i=0;s[i]!=0;i++)
	{
		if(isoprand(s[i])==1)
		{
			int t=s[i]-'0';
			push(&a,t);
		}	
		else	
		{
			x=pop(&a);
			y=pop(&a);
			r=operation(x,y,s[i]);
			push(&a,r);
		}
		
	}
	printf("\n\n result = %d",pop(&a));
	return 0;
}
