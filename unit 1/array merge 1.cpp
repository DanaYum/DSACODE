#include<iostream>
using namespace std;
int main()
{
    int n,m;
    string arr1[100],arr2[100];
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    getline(cin,arr1[i]);
    cin>>m;
    cin.ignore();
    for(int i=0;i<m;i++)
    getline(cin,arr2[i]);
    for(int i=0;i<m;i++)
    arr1[n+i]=arr2[i];
    cout<<"Catalog:"<<endl;
    for(int i=0;i<n+m;i++)
    cout<<arr1[i]<<endl;
}