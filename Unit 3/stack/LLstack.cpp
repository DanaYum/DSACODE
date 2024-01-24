#include <iostream>
using namespace std;
class Node {
	public:
   int data;
   Node *next;
};
class LinkedList_Stack
{
  public:
    Node* top = NULL;
void push(int val) {
   Node* newnode = new Node;
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}
int pop() {
	int t=-1;
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      t=top->data;
      top = top->next;
   }
   return t;
}
void display() {
   Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}
};
int main() {
   LinkedList_Stack ls;
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            ls.push(val);
            break;
         }
         case 2: {
            cout<<ls.pop()<<endl;
            break;
         }
         case 3: {
            ls.display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}