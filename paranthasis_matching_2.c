#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node 
{
	char data;
	node* next;
};

void push(char c,node** top)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=c;
	temp->next=*(top);
	*top=temp;
	
}
int pop(node** top)
{

	node* temp=*(top);
	if(*(top)!=NULL)
	{
		*(top)=(*top)->next;
		return 1;
	}
	else
		return -1;
}

int main()
{

	
	node* top=NULL;
	char exp[100];
	printf("Enter expression : ");
	scanf("%s",exp);
	int i=0;
	int check;
	while(exp[i]!=0)
	{
		if((exp[i]=='(')  || (exp[i]=='[') || (exp[i]=='{'))
			push(exp[i],&top);
		else if((exp[i]==')')  || (exp[i]==']') || (exp[i]=='}'))
		{
			
			if(exp[i]==top->data)
			{
				printf("\nExpression is not paranthesized properly.");
				return 0;
			}	
			check=pop(&top);
			if(check==-1)
			{
				printf("\nExpression is not paranthesized properly.");
				return 0;
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
