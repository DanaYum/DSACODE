#include <iostream>
using namespace std;

class Student
{
public:
    int n;
    int arr[100];
    
    void display(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Student " << i + 1 << " Marks: ";
            for (int j = 0; j < 5; j++) // Corrected the loop condition
            {
                cout << arr[i * 5 + j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Student s;
    cout<<"total no of std: ";
    cin >> s.n;

    for (int i = 0; i < s.n; i++)
    {
        cout << "Enter marks for Student " << i + 1 << " (5 marks): ";
        for (int j = 0; j < 5; j++)
        {
            cin >> s.arr[i * 5 + j];
        }
    }

    cout << "___________________answer here______________________________" << endl;
    s.display(s.arr, s.n);

    return 0;
}
