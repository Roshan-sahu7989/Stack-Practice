#include<bits/stdc++.h>
using namespace std;

template<class T>
class stackk
{
 public:
    T *arr;
    int top;
    int size;

    stackk()
    {	
		size=0;
		top=-1;
		arr=nullptr;
	}
    stackk(int);
    void create(int);
    bool isempty();
    bool isfull();
    int peek();
    void push(T);
    void pop();
	void display(); 
};
//constructors
template<class T>
stackk<T>::stackk(int n)
{
	size=n;
	top=-1;
	arr=new T[size];
}

template<class T>
void stackk<T>::create(int n)
{
	size=n;
	arr=new T[size];
}
template<class T>
bool stackk<T>::isfull(){	return top==(size-1) ? true : false;}
template<class T>
bool stackk<T>::isempty(){return top==-1 ? true : false;}

template<class T>
void stackk<T>::display()
{
	int i=top;
	while(i>=0)
		cout<<"| "<<arr[i--]<<"  |"<<endl;
}
template<class T>
void stackk<T>::push(T n)
{
	if(!isfull())
		arr[++top]=n;
	else
		cout<<"stack is full!"<<endl;
}
template<class T>
void stackk<T>::pop()
{
	
	if(!isempty())
		top--;
	else
		cout<<"stack is empty!"<<endl;
}

int main() {
    // Write C++ code 
    stackk<string> s(5);
    for(int i=0;i<5;i++)
    	s.push("Hello");
    s.pop();
    cout<<"your stack : \n"<<s.size;       //edit
    s.display();
    cout<<" ----- "<<endl; /// edit
    return 0;
}
