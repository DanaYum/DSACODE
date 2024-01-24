#include <iostream>
using namespace std;

class node {
	public:
		int data;
		node *link;
};


class LinkedList {
	public:
		node *head;
		LinkedList() {
			head = NULL;
		}
		void create();
		void display();
		//insertion functions
		void insert_Last();
		void insert_Begin();
		void insert_at_given_position();
		//deletion function
		void delete_begin();
		void delete_last();
		void delete_at_given_position();
		//search function
		void search();
};

void LinkedList::search()
{
	int key,counter=1;
	cout<<"Enter the data to search: ";
	cin>>key;
	bool f=false;
	node *temp=head;
	while(temp->link!=NULL)
	{
		if(temp->data==key)
		{
			cout<<"Element found at position: "<<counter<<endl;
			
			f=true;
			break;
		}
		temp=temp->link;
		counter++;
	}
	if(!f)
	cout<<"Element is not found..!"<<endl;
}
void LinkedList::delete_at_given_position()
{
	int pos,counter =1;
	cout<<"Enter the position to delete :";
	cin>>pos;
		node *pre, *cur=head;
	while(cur->link!=NULL && counter<pos)
	{
		pre=cur;
		cur=cur->link;
		counter++;
	}
	pre->link=cur->link;
		cout<<"Deleted element data:"<<cur->data<<endl;
		delete cur;
}

void LinkedList::delete_last()
{
	node *pre, *cur=head;
	while(cur->link!=NULL)
	{
		pre=cur;
		cur=cur->link;
		
	}
	pre->link=NULL;
		cout<<"Deleted element data:"<<cur->data<<endl;
		delete cur;
}
void LinkedList::delete_begin()
{
	node *temp=head;
	if(head==NULL)
	{
		cout<<"\nDeletion not possible..."<<endl;
	}
	else
	{
		head=head->link;
		cout<<"\nDeleted node data: "<<temp->data<<endl;
		delete temp;
	}
}
void LinkedList::insert_Begin() {

	int n, x;
	node *temp = new node;
	cout<<"Enter the data to insert into beginning : ";
	cin>> x;

	temp->data = x;
	temp->link = NULL;

	temp->link = head;
	head = temp;
}

void LinkedList::insert_at_given_position(){
	int pos, counter;
	node *t = new node;
	cout<<"Enter the position...!";
	cin>>pos;
	
	cout<<"Enter the data to insert at given postion: ";
	cin>>t->data;
	t->link = NULL;
	
	node *pre = NULL, *cur = head;
	while(cur->link != NULL && counter < pos){
		pre = cur;
		cur = cur->link;
		counter++;
	}
	if(counter ==pos)
	{
		pre->link = t;
		t->link = cur;
	}
	else
	{
		cout<<"Invalid position..";
	}
	
}

void LinkedList::insert_Last() {
	int n;
	node *temp = new node;
	cout<<"Enter the data to insert into last: ";
	cin>> temp->data;

	temp->link = NULL;

	if(head == NULL)
		head = temp;
	else {
		node *t = head;
		while (t->link != NULL) {
			t = t->link;
		}
		t->link = temp;
	}
}

void LinkedList::create() {
	int n;
	node *temp = new node;
	cout<<"Enter the data to insert into node: ";
	cin>>n;
	temp->data = n;
	temp->link = NULL;
	if(head == NULL)
		head = temp;
	else {
		node *t = head;
		while (t->link != NULL) {
			t = t->link;
		}
		t->link = temp;
	}
}

void LinkedList::display() {
	node *t = head;
	cout<<"\n\n ******** My Linked List:  ********\n\n ";
	while(t != NULL) {
		cout<<t->data << " ==> ";
		t = t->link;
	}
	cout<<"NULL\n\n";

}


int main() {
	int n;
	LinkedList l;
	cout<<"Enter number of nodes to insert: ";
	cin>>n;
	for(int i = 0; i < n; i++) {
		l.create();
	}
	l.display();
//	l.insert_Last();
//	l.display();
//	l.insert_Begin();
//	l.display();
//	l.insert_at_given_position();
//	l.display();
//	l.delete_begin();
//	l.display();
//	l.delete_last();
//	l.display();
//	l.delete_at_given_position();
//	l.display();
	l.search();
	l.display();
	return 0;
}