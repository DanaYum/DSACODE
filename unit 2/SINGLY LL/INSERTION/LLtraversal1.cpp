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
int main()
{
    struct Node*head;
    struct Node*second;
    struct Node*third;
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
    third->next=NULL;
    LinkedListTraversal(head);
    return 0;

}