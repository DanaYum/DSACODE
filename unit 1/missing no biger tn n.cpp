#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int input;
    cout << "Enter a number to find the smallest missing number greater than it: ";
    cin >> input;

    set<int> nums; // Using a set to store unique values
    for (int i = 0; i < n; i++)
    {
        nums.insert(arr[i]);
    }

    int smallestMissing = input + 1;
    while (nums.find(smallestMissing) != nums.end())
    {
        smallestMissing++;
    }

    cout << "The smallest missing number greater than " << input << " is: " << smallestMissing << endl;

    return 0;
}
