#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n, a;
    stack<int> s1, s2;
    cin >> n;
    if (n == 0)
        cout << "Stack is empty." << endl;
    else if (n > 10)
    {
        cout << "Stack is full.";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            s1.push(a);
        }

        cout << "Original stack: ";
        stack<int> temp;  // Temporary stack to reverse the original stack
        while (!s1.empty())
        {
            int element = s1.top();
            temp.push(element);
            s1.pop();
        }

        while (!temp.empty())
        {
            int element = temp.top();
            cout << element << " ";
            s1.push(element);  // Restore the original stack
            temp.pop();
        }
    //sorting
        while (!s1.empty())
        {
            int k = s1.top();
            s1.pop();
            while (!s2.empty() && s2.top() < k)
            {
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(k);
        }

        cout << "\nSorted stack: ";
        while (!s2.empty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
        cout << "\n";
    }
    return 0;
}
