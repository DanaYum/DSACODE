// You are using GCC
#include<iostream>
using namespace std;
void heapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i+1;//left child index
    int right=2*i+2;//right child index
    if(left<n && a[left]>a[largest]) 
    {
        largest=left;
    }    
     if(right<n && a[right]>a[largest])
    {
        largest=right;
    }
   if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}                                                              
void heapSort(int a[],int n)                                
{                                                               
    for(int i=n/2-1;i>=0;i--)//to visit all the non leaf nodes before going to root
    {                        //range of internal nodes is (0 to n/2-1)
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--)//extracting max element and keeping it at the end of sorted portion
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