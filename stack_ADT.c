#include<stdio.h>
#include<stdlib.h>

struct stack 
{
	int size;
	int top;
	int* p;
}; 

void create (struct stack* st)
{
	
	printf("Enter maximum size of the stack to be created : ");
	scanf("%d",&(st->size));
	st->p=(int*)malloc((st->size) *sizeof(int));
}


void push(struct stack *st)
{
	if(st->top>=(st->size-1))
	{
		printf("\nStack overflow.");
		return;
	}
	else
	{
		int num;
		printf("\nEnter value : ");
		scanf("%d",&num);
		st->p[++(st->top)]=num;
	}
}
int pop(struct stack *st)
{
	if(st->top<0)
	{
		printf("\nStack underflow(or can't insert number to the stack).");
		return;
	}
	else
	{
		int num=st->p[(st->top)--];
		return num;
	}
}

void display(struct stack st)
{
	int i;
	for(i=st.top;i>=0;i--)
	{
		printf("%d  ",st.p[i]);
	}
}

int peek(struct stack *st)
{
	if(st->top<0 && st->top>=st->size)
	{
		printf("\nthere are no element in the stack.");
		return -1;
	}
	else
	{
		int num;
		num=st->p[st->top];
		return num;
    }
}
int is_empty(struct stack *st)
{
	if(st->top<0)
		return 1;
	else
		return 0;
}
int is_full(struct stack *st)
{
	if(st->top>=st->size)
		return 1;
	else 
		return 0;
}
int main()
{
	struct stack stack1;
	stack1.top=-1;
	
	create(&stack1);
	int terms=5;
	while(terms!=0)
	{
	push(&stack1);
	terms--;
	}
	
	display(stack1);
	terms=3;
	while(terms!=0)
	{
	printf("\nNumber : %d",pop(&stack1));
	terms--;
    }
	printf("\nvalue at top of stack : %d",peek(&stack1));
	
	printf("\n empty : %d \n full : %d",is_empty(&stack1),is_full(&stack1));
	
	return 0;
}
