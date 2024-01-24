#include <iostream>
using namespace std;

int TOH(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return 1;
    }

    int moves = TOH(n - 1, source, auxiliary, destination);

    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    moves++;

    moves += TOH(n - 1, auxiliary, destination, source);

    return moves;
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    int minimum_moves = TOH(n, 'A', 'C', 'B');

    cout << "Minimum number of moves: " << minimum_moves << endl;

    return 0;
}
