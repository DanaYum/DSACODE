#include<iostream>
using namespace std;
void display(int arr[], int n)//code for traversal
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}
void DeleteAtFirst(int arr[],int &size)
{
    for(int i=0;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
}
void DeleteAtIndex(int arr[],int &size,int index)
{
    cout<<"\nenter index: ";
    cin>>index;
    for(int i=index;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    // return 1;
}
void DeleteAtEnd(int arr[],int &size)
{
    size--;
}
int main()
{
    int arr[100],n,index;
    cout<<"enter size: ";
    cin>>n;
    cout<<"enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"original array: "<<endl;
    display(arr,n);
    // cout<<"\n**************** delete at first ************************"<<endl;
    // DeleteAtFirst(arr,n);
    // display(arr,n);
    // cout<<"\n**************** delete at Index ************************"<<endl;
    // DeleteAtIndex(arr,n,index);
    // display(arr,n);
    cout<<"\n**************** delete at last ************************"<<endl;
    DeleteAtEnd(arr,n);
    display(arr,n);
    
}