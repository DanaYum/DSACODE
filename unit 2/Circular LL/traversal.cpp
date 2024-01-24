#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node*head)
{
    struct Node *ptr=head;
    // cout<<"Element: "<<ptr->data<<endl;
    // ptr=ptr->next;
    // while(ptr!=head)
    // {
    //     cout<<"Element: "<<ptr->data<<endl;
    //     ptr=ptr->next;
    // }
    do{
        cout<<"Element: "<<ptr->data<<endl;
        ptr=ptr->next;
    }while(ptr!=head);
}
void insertAtFirst(struct Node* &head,int data)
{
    struct Node*ptr=new Node;
    ptr->data=data;
    struct Node*p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
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
    head->data=4;
    head->next=second;
     //link second and third node
    second->data=3;
    second->next=third;
     //link first and second node
    third->data=6;
    third->next=fourth;
    fourth->data=1;
    fourth->next=head;
    LinkedListTraversal(head);
    cout<<"************************* insert at first ********************************"<<endl;
    insertAtFirst(head,99);
    LinkedListTraversal(head);
    return 0;

}