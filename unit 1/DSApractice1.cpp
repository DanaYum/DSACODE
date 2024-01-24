#include<iostream>
#define MAXSIZE 100
using namespace std;
int a[MAXSIZE];
int size=0;
void create_array();
void Trav_forward();
void Trav_backword();
void Search_Element(int x);
void insert(int pos,int el);
void Delete(int);
void create_array()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    if(n>MAXSIZE && n<0)
    {
        cout<<"size are more than 100"<<endl;
        return;
    }
    else
    {
        cout<<"Array created"<<endl;
        cout<<"Enter "<<n<<"number of element"<<endl;
        for(int i=0;i<n;i++)
        cin>>a[i];
        size=n;
    }
}
void Trav_forward()
{
    cout<<"Lists in forward:"<<endl;
    for(int i=0;i<size;i++)
    cout<<a[i]<<"\t";
}
void Trav_backword()
{
    cout<<"\nLists in backward:"<<endl;
    for(int i=size-1;i>=0;i--)
    cout<<a[i]<<"\t";
}
void Search_Element(int x)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==x)
        {
            cout<<"Element found at position: "<<i+1<<endl;
            break;
        }
        if(i>size)
        {
            cout<<"Element not found";
        }
    }
}
void insert(int pos,int el)
{
    int i;
    if(size>=MAXSIZE)
    {
        cout<<"Array is full"<<endl;
        return;
    }
    for(i=size-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=el;
    size++;
}
void Delete(int pos)
{
    if(pos>=size)
    {
        cout<<"Deletion is not possible\n";
        return;
    }
    else{
        int i;
        for(i=pos;i<size;i++)
        a[i-1]=a[i];
        a[size-1]=0;
        size--;
    }
}
int main()
{
    int t,n,m,z;
    create_array();
    Trav_forward();
    Trav_backword();
    cout<<"\nEnter element to search:";
    cin>>t;
    Search_Element(t);
    cout<<"enter the position:";
    cin>>n;
    cout<<"enter the element:";
    cin>>m;
    insert(n,m);
    Trav_forward();
    cout<<"\nEnter the position to delete:";
    cin>>z;
    Delete(z);
    Trav_forward();

    return 0;
}