/**
#include<iostream>
using namespace std;
int main()
{
    string n;
    cout<<"write a sentence: "<<endl;
    getline(cin,n);
    int a=n.length();
    int word =0;
    for(int i=0;i<a;i++)
    {
        if(n[i]==' ')
        word++;
    }
    word+=1;
    cout<<"the no of word is "<<word;
}
*/
#include<iostream>
using namespace std;

int main()
{
    string n;
    getline(cin, n);

    int word = 0;
    int len = n.length();
    bool prevSeparator = true; // Initialize to true to handle the case where the input starts with a separator

    for (int i = 0; i < len; i++)
    {
        if (n[i] == ' ' || n[i] == '\t' || n[i] == '\n')
        {
            if (!prevSeparator) // Increment only if the previous character was not a separator
            {
                word++;
                prevSeparator = true;
            }
        }
        else
        {
            prevSeparator = false;
        }
    }

    if (!prevSeparator)
    {
        word++; // Increment the word count for the last word
    }

    cout << word;

    return 0;
}
