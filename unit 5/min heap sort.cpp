// You are using GCC
#include<iostream>
using namespace std;
void heapify(int a[],int n,int i)
{
    int smallest=i;
    int left=2*i+1;//left child index
    int right=2*i+2;//right child index
    if(left<n && a[left]<a[smallest]) 
    {
        smallest=left;
    }    
    else if(right<n && a[right]<a[smallest])
    {
        smallest=right;
    }
    else if(smallest!=i)
    {
        swap(a[i],a[smallest]);
        heapify(a,n,smallest);
    }
}                                                               //        30
void heapSort(int a[],int n)                                
{                                                               //   40        15
    for(int i=n/2-1;i>=0;i--)
    {                                                       //    10    15  25      30
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapSort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}