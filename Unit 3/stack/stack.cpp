#include<iostream>
#define MAXSIZE 5
using namespace std;
struct Stack
{
	int arr[MAXSIZE];
	int top;
	 
	Stack()
	{
		top=-1;
	}
	void push(int);
	int pop();
	bool isFull();//true when full otherwise false
	bool isEmpty();
	int getTop();//return top most element from stack
};
int Stack::getTop()
{
	int t=-1;
	if(top==-1)
		cout<<"Stack is underflow...!"<<endl;
	else
	{
		t=arr[top];	
	}	
	return t;
}
bool Stack::isFull()
{
	return (top==MAXSIZE-1);
}
bool Stack::isEmpty()
{
	return (top==-1);
}
void Stack::push(int x)
{
	if(top==MAXSIZE-1)
	   cout<<"Stack is overflow..!"<<endl;
	else
	 {
	 	top++;
	 	arr[top]=x; 
	  } 
}
int Stack::pop()
{
	int t;
	if(top==-1)
		cout<<"Stack is underflow...!"<<endl;
	else
	{
		t=arr[top];
		top--;	
	}	
	return t;
}
int main()
{
	struct Stack arr;
	//cout<<s.pop()<<endl;
	//cout<<s.isEmpty()<<endl;
	//cout<<s.isFull()<<endl;
	// for(int i=0;i<7;i++)
	//   s.push(i*i);
	// s.push(1);
	// s.push(2);
	// s.push(9);
	// s.push(3);
	// s.push(2);
	arr.push(6);
	arr.push(3);
	arr.push(7);
	cout<<arr.pop()<<endl;
	cout<<arr.getTop();
	//cout<<s.pop();
	//cout<<s.pop();
	// cout<<s.getTop()<<endl;
	// cout<<s.getTop()<<endl;
	// cout<<s.pop()<<endl;
	// cout<<s.getTop()<<endl;
	// cout<<s.getTop()<<endl;

	return 0;
}