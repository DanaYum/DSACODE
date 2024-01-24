#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
void insertAtFirst(struct Node *&head,int data)
{
    struct Node*ptr=new Node;
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    
}
void insertAtIndex(struct Node* &head,int data,int index)
{
    struct Node*ptr=new Node;
    struct Node*p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    
}
void insertAtEnd(struct Node *&head,int data)
{
    struct Node *ptr=new Node;
    ptr->data=data;
    struct Node*p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
   
    ptr->next=NULL;
    p->next=ptr;
    
}
int main()
{
    struct Node*head=new Node;
    struct Node*second=new Node;
    struct Node*third=new Node;
    struct Node*fourth=new Node;
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=NULL;
    cout<<"************************** Displaying ****************************"<<endl;
    LinkedListTraversal(head);
    // cout<<"************************ Insert at first *************************"<<endl;
    // insertAtFirst(head,11);
    // LinkedListTraversal(head);
    // cout<<"************************ Insert at index *************************"<<endl;
    // insertAtIndex(&head,55,3);
    // LinkedListTraversal(head);
    cout<<"************************ Insert at End *************************"<<endl;
    insertAtEnd(head,99);
    LinkedListTraversal(head);
    return 0;
}