#include <iostream>
using namespace std;

// Merge two sorted arrays A and B into C
void merge(int A[], int n, int B[], int m, int C[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < n)
        C[k++] = A[i++];
    while (j < m)
        C[k++] = B[j++];
}

// Merge sort algorithm
void BubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n; // Size of array A
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> m; // Size of array B
    int B[m];
    for (int j = 0; j < m; j++)
        cin >> B[j];

    // Sort arrays A and B using merge sort
    BubbleSort(A, n);
    BubbleSort(B, m);
    int C[n + m]; // Merged array

    // Merge sorted arrays A and B into C
    merge(A, n, B, m, C);

    for (int i = 0; i < n + m; i++)
        cout << C[i] << " ";

    return 0;
}
