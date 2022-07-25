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
	node* t=(node*)malloc(sizeof(node));
	t->data=c;
	t->next=(*top);
	(*top)=t;
}

char pop(node** top)
{
	char ch=(*top)->data;
	node* temp=(*top);
	(*top)=(*top)->next;
	free(temp);
	return ch;
}

int isEmpty(node* top)   //for checking whether the stack is empty or not
{
	if(top==0)
		return 1;
	else
		return 0;	
}
int check(char c)       // 
{
	if(c=='(' || c==')')
		return 1;
	else if(c=='[' || c==']')
		return 2;
	else if(c=='{' || c=='}')
		return 3;
	else 
		return 0;		
}

int isPara(node** top,char* exp)
{
	int i=0,j=0;
	
	while(exp[i]!=0)
	{
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')   
			push(top,exp[i]);
		else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
		{
			if(isEmpty(*top)) 
				return 0;
			else if(check((*top)->data) == check(exp[i]))
				pop(top);
			else
				return 0;	
		}	
		i++;
	}
	if(isEmpty(*top))
		return 1;
	else
		return 0;			
}

int main()
{
	char ex[100];
	int i;
	node* top=NULL;
	
	printf("Enter the expresion to check whether the expression is paranthesized or not :");
	scanf("%s",ex);
	
	if(isPara(&top,ex))
		printf("\n expression is paraenthesized properly.");
	else
		printf("\n expression is not paraenthesized properly.");
			
	return 0;
}
