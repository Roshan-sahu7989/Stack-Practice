//input restricted DEQueue
#include<stdio.h>
#define SIZE 10
int front,rear,arr[SIZE];

void rear_enqueue(int data)
{
	if(isfull()==1)
		printf("\nQueue is full\n");
	else
		arr[++rear]=data;
}

int front_dequeue()
{
	if(isempty()==1)
		printf("\nQueuen is empty\n");
	else
		return arr[++front];	
}

int rear_dequeue()
{
	if(isempty()==1)
		printf("\nQueuen is empty\n");
	else
		return arr[rear--];
}
 int isfull()
 {
 	if(rear==SIZE-1)
 		return 1;
 		
 	return 0;	
 }
int isempty()
{
	if(front==rear)
		return 1;
	
	return 0;	
}

int main()
{
	front=rear =-1;
	rear_enqueue(1);
	rear_enqueue(2);
	rear_enqueue(3);
	rear_enqueue(4);
	rear_enqueue(5);
	rear_enqueue(6);
	printf("%d\n",rear_dequeue());
	printf("%d\n",front_dequeue());
	rear_dequeue();
	front_dequeue();
	rear_dequeue();
	front_dequeue();
	rear_dequeue();
	rear_dequeue();
	rear_dequeue();
	
	return 0;
}
