#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    queue<int> originalQ = q; // Create a copy of the original queue for printing.
    while (!originalQ.empty()) {
        cout << originalQ.front() << " ";
        originalQ.pop();
    }

    reverseQueue(q);

    cout << "\nReversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
