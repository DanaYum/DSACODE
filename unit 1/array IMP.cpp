// merging of two array after removing duplicate element
#include<iostream>
using namespace std;
int main()
{
    int n,m,A[100],B[100];
    cout<<"enter size of first array: ";
    cin>>n;
    cout<<"enter ele: ";
    for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"array size of second array: ";
    cin>>m;
    cout<<"enter ele: ";
    for(int i=0;i<m;i++)
    cin>>B[i];
    int C[200];
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(A[i]<B[j])
        C[k++]=A[i++];
        else
        C[k++]=B[j++];
    }
    while(i<n)
    C[k++]=A[i++];
    while(j<m)
    C[k++]=B[j++];
    int l=n+m;
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            if(C[i]==C[j])
            {
                for(k=j;k<l-1;k++)
                {
                    C[k]=C[k+1];
                }
                l--;
                j--;
            }
        }
    }
    cout<<"merged array after removing duplicates: ";
    for(i=0;i<l;i++)
    cout<<C[i]<<" ";
    
}