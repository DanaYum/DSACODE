#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, A[100], B[100];
    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter size of second array: ";
    cin >> m;
    cout << "Enter elements: ";
    for (int i = 0; i < m; i++)
        cin >> B[i];

    for (int i = 0; i < m; i++)
        A[n + i] = B[i];

    int l = n + m; 

    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {
            if (A[i] == A[j]) {
                for (int k = j; k < l ; k++) {
                    A[k] = A[k + 1];
                }
                l--;
                j--;
            }
        }
    }

    cout << "Merged array after removing duplicate elements: ";
    for (int i = 0; i < l; i++)
        cout << A[i] << " ";
    cout<<"sorted array: ";
    sort(A,A+l);
    for (int i = 0; i <l; i++)
        cout << A[i] << " ";
    return 0;
}
