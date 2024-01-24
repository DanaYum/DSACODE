#include<iostream>
#define MAXSIZE 50
using namespace std;
class Stack
{
	char s[MAXSIZE];
	int top;
	public:
		Stack()
		{
			top=-1;
		}
	void push(char);
	char pop();
	bool isFull();
	bool isEmpty();
	char getTop();   //return topmost element from stack
	int ISP(char);
	int ICP(char);
	void Infix_to_postFix(char in[50]);
};

void Stack::Infix_to_postFix(char infix[50])
{
    Stack s;
    int i=0;
    char ch;
    char x;
    
    s.push('#');
    
    while(infix[i]!='\0')
    {
        ch=infix[i];
        i++;
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        {
            cout<<ch;
        }
        else if(ch==')')
        {
            while(s.getTop()!='(')
            {
                x=s.pop();
                cout<<x;
            }
            s.pop();
        }
        else
        {
            while( ISP(s.getTop()) >= ICP(ch) )
            {
                x=s.pop();
                cout<<x;
            }
            s.push(ch);
        }
    }
    while(!s.isEmpty())
    {
        x=s.pop();
        if(x!='#')
            cout<<x;
    }
}

int Stack::ISP(char ch)
{
    switch(ch)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 4;
        case '#':
            return -2;
    }
}

int Stack::ICP(char ch)
{
    switch(ch)
    {
        case '(':
            return 4;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}


char Stack::getTop()
{
	char t='\0';
	if(top==-1)
		cout<<"Stack is underflow...!"<<endl;
	else
		t=s[top];
	return t;
}

bool Stack::isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}

bool Stack::isFull()
{
	if(top==MAXSIZE-1)
		return true;
	else
		return false;
}

void Stack::push(char x)
{
	if(top==MAXSIZE-1)
		cout<<"Stack is overflow..!"<<endl;
	else
	{
		top++;
		s[top]=x;
	}
}
char Stack::pop()
{
	char t='\0';
	if(top==-1)
		cout<<"Stack is underflow...!"<<endl;
	else
	{
		t=s[top];
		top--;
	}
	return t;
}
int main()
{
	Stack s;
    char in[50];
    cin>>in;
    s.Infix_to_postFix(in);
	return 0;
}
