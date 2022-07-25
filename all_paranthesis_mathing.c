#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node
{
	char data;
	node* next;
};

void push(node** top,char c)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=c;
	temp->next=(*top);
	*top=temp;
}

void pop(node** top)
{
	
	node* temp=(*top);
	if(*top==NULL)
		return;
	else
	{
		(*top)=(*top)->next;
		free(temp);
	}	
}
int symbol_check(char a,char b)
{
	
	if(a=='(' && b==')')
		return 1;
	else if(a=='[' && b==']')
		return 1;
	else if(a=='{' && b=='}')
		return 1;
	else
		return 0;	
}

int main()
{
	char exp[100];
	node* top=NULL;
	printf("Enter expresion : ");
	scanf("%s",exp);

	int i=0;
	while(exp[i]!=0)
	{
		if(exp[i]=='('  || exp[i]=='[' || exp[i]=='{')
			push(&top,exp[i]);
		else if(exp[i]==')'  || exp[i]==']' || exp[i]=='}')
		{	
			if(top==NULL)
			{
				printf("\nExpression is not paranthesized properly.");
				return;
			}	
			else if(symbol_check(top->data,exp[i]))
			{
				pop(&top);
			}
			else
			{
				printf("\nExpression is not paranthesized properly.");
				return;
			}
	
		}
		i++;
	}
	if(top==NULL)
		printf("\nExpression is paranthesized properly.");
	else
		printf("\nExpression is not paranthesized properly.");
			
	return 0;
}
