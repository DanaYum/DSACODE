#include<iostream>
using namespace std;
void display(int arr[], int n)//code for traversal
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}
void InsertAtFirst(int arr[],int &size,int element)
{
    for(int i=size-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=element;
    size++;
}
void InsertAtIndex(int arr[],int &size,int element,int index)//code for inserting element at given index
{
    cout<<"\nenter index: ";
    cin>>index;
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    size++;
    // return 1;
}
void InsertAtEnd(int arr[],int &size,int element)
{
    arr[size]=element;
    size++;
}
int main()
{
    int arr[100],n,element,index;
    cout<<"enter size: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter element to insert: ";
    cin>>element;
    cout<<"original array: "<<endl;
    display(arr,n);
    cout<<"\n..............inserted array displaying...................."<<endl;
    // InsertAtFirst(arr,n,element);
    // display(arr,n);
    // InsertAtIndex(arr,n,element,index);
    // cout<<"\n..............inserted array displaying...................."<<endl;
    // display(arr,n);
    // cout<<"\n..............inserted array displaying...................."<<endl;
    InsertAtEnd(arr,n,element);
    display(arr,n);
}