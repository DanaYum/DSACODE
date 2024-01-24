#include<iostream>
using namespace std;
void Display(int arr[],int n)
{
    for(int i=0;i<=n;i++)
    {
        cout<<" "<<arr[i];
    }
}
void Deletion(int arr[],int size,int index)
{
    if(index>size)
    cout<<"not possible";
    for(int i=index;i<size;i++)
    {
        arr[i]=arr[i+1];
    }

}
int main()
{
    int arr[100]={2,6,7,3,1};
    int size=5;
    cout<<"\narray displaying: ";
    Display(arr,size);
    Deletion(arr,size,2);
    size--;
    cout<<"\narray after deletion displaying: ";
    Display(arr,size);
}
