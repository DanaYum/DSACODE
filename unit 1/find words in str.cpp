#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence = "Hello, world!";
    string wordToSearch = "foo";

    size_t found = sentence.find(wordToSearch);

    if (found != string::npos) //string::npos actually means until the end of the string.
    {
        cout << "Word found at position " << found << endl;
    } else {
        cout << "Word not found in the sentence." << endl;
    }

    return 0;
}
