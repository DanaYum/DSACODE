#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void DeleteAtFirst(struct Node* &head)
{
    struct Node*ptr=head;
    head=head->next;
    delete ptr;
}
void DeleteAtIndex(struct Node*&head,int index)
{
    struct Node*ptr=head;
    struct Node*p=head->next;
    int i=0;
    while(i!=index-1)
    {
        ptr=ptr->next;
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    delete p;
}
void DeleteAtLast(struct Node* &head)
{
    struct Node*ptr=head;
    struct Node*p=head->next;
    while(p->next!=NULL)
    {
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=NULL;
    delete p;
}
void LinkedListTraversal(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
int main()
{
    struct Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth=new Node;
    //allocate memeory for nodes in the linked list in heap
    head=new Node;
    second=new Node;
    third=new Node;
    //link first and second node
    head->data=1;
    head->next=second;
     //link second and third node
    second->data=2;
    second->next=third;
     //link first and second node
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=nullptr;
    cout<<"*********************** before deletion *************************"<<endl;
    LinkedListTraversal(head);
    // DeleteAtFirst(head);
    // cout<<"*********************** after deletion *************************"<<endl;
    // LinkedListTraversal(head);
    // cout<<"*********************** after deletion *************************"<<endl;
    // DeleteAtIndex(head,2);
    // LinkedListTraversal(head);
    cout<<"*********************** after deletion *************************"<<endl;
    DeleteAtLast(head);
    LinkedListTraversal(head);
    return 0;

}