
#include<iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;
    
    int A[n];
    cout << "Enter elements of the first array:" << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    cout << "Enter the size of the second array: ";
    cin >> m;
    
    int B[m];
    cout << "Enter elements of the second array:" << endl;
    for (int i = 0; i < m; i++)
        cin >> B[i];
    
    int c;
    c=n>m?n:m;
    int C[c];
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        C[k++]=A[i++]+B[j++];
    }
    while(i<n)
    C[k++]=A[i++];
    while(j<m)
    C[k++]=B[j++];
    // for(int i=0;i<c;i++)
    // {
    //     if(i<n && i<m)
    //     {
    //         C[i]=A[i]+B[i];
    //     }
    //     else if(i<n)
    //     C[i]=A[i];
    //     else if(i<m)
    //     C[i]=B[i];
    // }
    cout << "Sum of elements of the arrays:" << endl;
    for (int i = 0; i < c; i++) {
        cout << C[i] << " ";
    }
    
    return 0;
}

//  You are using GCC
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n1,n2,m;
//     int arr1[500];
//     int arr2[500];
//     cin>>n1;
//     for(int i=0;i<n1;i++)
//     cin>>arr1[i];
//     cin>>n2;
//     for(int i=0;i<n2;i++)
//     cin>>arr2[i];
//     // cin>>n3;
//     // for(int i=0;i<n3;i++)
//     // cin>>arr3[i];
//     if(n1>=n2)
//     {
//         m=n1;
//     }
//     else
//     m=n2;
//     int arr3[m];
//     for(int i=0;i<m;i++)
//     arr3[i]=arr1[i]+arr2[i];
//     for(int i=0;i<m;i++)
//     cout<<arr3[i]<<" ";
// }
