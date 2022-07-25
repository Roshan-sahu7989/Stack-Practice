#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node node;

struct stack 
{
	int size;
	node *top;
};
typedef struct stack stack;

void push(stack* s)    //insertin 1 node and value in the stack
{
	node* temp=NULL;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("\ncan not add more values.");
		return;
	}
	printf("\nEnter the value : ");
	scanf("%d",&temp->data);
	
	temp->next = s->top;
	s->top=temp;
}

int pop(stack *s)      //deleting one value of stasck and returning that value
{
	int num=-1;
	node* temp=s->top;
	if(temp==NULL)
	{
		printf("\nstack is empty so can't delete item.");
		return num;
	}
	else
	{
		num=temp->data;
		s->top=temp->next;
		free(temp);
		return num;
	}	
}

void display(stack s)     //print all element that are stored in stack in LIFO
{
	node* temp =s.top;
	while(temp!=0)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}

void peek(stack s)   //print topmost element
{
	node* temp=s.top;
	printf("\n%d is in the top most position in the stack.\n",temp->data);
}
int length_stack(stack s)   //length of stack
{
	int i=0;
	node* temp=s.top;
	while(temp!=0)
	{
		i++;
		temp=temp->next;
	}
	return i;
}
int is_empty(stack s)      //return 1 for empty stack and 0 for not empty stack
{
	if(s.top==0)
	{
		printf("\nStack is empty.");
		return 1;
	}
	else
		return 0;	
}


int main()
{
	int poped_num;
	
	stack s;
	s.top=NULL;
	
	printf("\nis_empty = %d\n",is_empty(s));
	
	push(&s);         //can be used in for loop for inserting more elements.
	push(&s);
	push(&s);
	
	printf("\n Length  of stack : %d  \n",length_stack(s));
	push(&s);
	
	
	poped_num = pop(&s);
	printf("\ndeleted number = %d \n",poped_num);
	
	printf("\nDisplay function : ");
	display(s);
	
	peek(s);
	printf("\nis_empty = %d\n",is_empty(s));
	

	return 0;
}
