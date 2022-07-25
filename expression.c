#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node
{
	char data;
	node* next;
};

node* top=NULL;
void push(char ch)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=ch;
	temp->next=top;
	top=temp;
}

char pop()
{
	
	node* t=top;
	char c=top->data;
	top=top->next;
	free(t);
	return c;
}

int isempty()
{
	if(top==NULL)
		return 1;
	return 0;	
}

int main()
{
	node* head=NULL;
	char exp[100];
	printf("Enter expression : ");
	scanf("%s",exp);
	
	
	return 0;
}

