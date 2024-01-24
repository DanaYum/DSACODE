#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAXSIZE 50
using namespace std;

class Stack
{
    char s[MAXSIZE];
    int top;
    int n;
    public:
        Stack()
        {
            top = -1;
        }
    void push(char);
    char pop();
    bool isFull();
    bool isEmpty();
    char getTop();   //return topmost element from stack
    void calculate(char *str);
};

void Stack::calculate(char* str)
{
    char n1, n2, n3; // Use char for n
    while(*str)
    {
        if(*str == ' ' || *str == '\t')
        {
            str++; // Increment the pointer here
            continue;
        }
        if(isdigit(*str))
        {
            n = *str - '0';
            push(n);
        }
        else
        {
            n2 = pop();
            n1 = pop();
            switch(*str)
            {
                case '+':
                    n3 = n1 + n2;
                    break;
                case '-':
                    n3 = n1 - n2;
                    break;
                case '*':
                    n3 = n1 * n2;
                    break;
                case '/':
                    n3 = n1 / n2;
                    break;
                case '^':
                    n3 = pow(n1, n2);
                    break;
                default:
                    cout << "Invalid operator";
                    exit(1);
            }
            push(n3);
        }
        str++; // Increment the pointer here
    }
    cout << int(pop()) << endl; // Convert the result back to int
}

char Stack::getTop()
{
    char t = '\0';
    if(top == -1)
        cout << "Stack is underflow...!" << endl;
    else
        t = s[top];
    return t;
}

bool Stack::isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

bool Stack::isFull()
{
    if(top == MAXSIZE - 1)
        return true;
    else
        return false;
}

void Stack::push(char x)
{
    if(top == MAXSIZE - 1)
        cout << "Stack is overflow..!" << endl;
    else
    {
        top++;
        s[top] = x;
    }
}

char Stack::pop()
{
    char t = '\0';
    if(top == -1)
        cout << "Stack is underflow...!" << endl;
    else
    {
        t = s[top];
        top--;
    }
    return t;
}

int main()
{
    Stack s;
    char expr[50];
    cin.getline(expr, MAXSIZE);
    s.calculate(expr);
    return 0;
}
