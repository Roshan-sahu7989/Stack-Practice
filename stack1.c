#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int size;
	int top;
	int* arr;
};

 int* create_stack(int size)
 {
 	int* p=(int *)malloc(size * sizeof(int));
 	return p;
 }
 
 int push(int *p,int size)
 {
 	int i;
 	
 	for(i=size-1;i>=0;i--)
 	{
 		printf("%d element : ",i);
 		scanf("%d",&p[i]);
 		
	}
	 return i+1;
 }
 
 int pop(int* p,int size,int top)
 {
 	for(top=top;top<size;top++)
 		printf("  %d  : %d\n",top,p[top]);
 	
 	return top;
 }
int main()
{
	struct stack stack1;
	stack1.top=-1;
	printf("Enter the required size of stack : ");
	scanf("%d",&stack1.size);
	 
	stack1.arr=create_stack(stack1.size);
	stack1.top=push(stack1.arr,stack1.size)	;
	
	printf("\n\n Enter elements  in reverse : \n");
	pop(stack1.arr,stack1.size,stack1.top);
	
	return 0;
}
