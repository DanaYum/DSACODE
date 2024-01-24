/*
#include <iostream>
using namespace std;

int main()
{
    int A[100] = {2, 4, 1, 5}, B[100] = {34, 25, 21};
    int n = 4, m = 3;

    for (int i = 0; i < m; i++)
    {
        A[n+i] = B[i];
    }

    for (int i = 0; i < n + m; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
*/
#include <iostream>
using namespace std;

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

    int C[n + m]; // Merged array

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (A[i] < B[j])
            {C[k] = A[i];
            k++;
            i++;}
        else
            C[k++] = B[j++];
    }

    while (i < n)//copying all remaining elements from A to C
        C[k++] = A[i++];
    while (j < m)
        C[k++] = B[j++];

    for (int i = 0; i < n + m; i++)
        cout << C[i] << " ";

    return 0;
}
