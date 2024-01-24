#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int arr[100];
    cin>>n;
    for(int i=0;i<n;i++)
        {cin>>arr[i];}
    cout<<"displaying array: ";
    sort(arr,arr+n);
    reverse(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"second largest:";
    cout<<arr[1];
}