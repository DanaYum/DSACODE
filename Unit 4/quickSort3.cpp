// quick sort of strings
#include <iostream>
#include <string>

using namespace std;



int partition(string names[], int low, int high) {
    
    string pivot=names[high];
    int tail=low-1;
    for(int i=low;i<high;i++)
    {
        if(names[i]<=pivot)
        {
            tail++;
            string temp=names[i];
            names[i]=names[tail];
            names[tail]=temp;
        }
    }
    string temp=names[high];
    names[high]=names[tail+1];
    names[tail+1]=temp;
    return tail+1;
}
void quickSort(string names[], int low, int high) {
    
    if(low<high)
    {
        int p=partition(names,low,high);
        quickSort(names,low,p-1);
        quickSort(names,p+1,high);
    }
}

int main() {
    int n;
    cin >> n;
    
    string names[n];
    
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    
    quickSort(names, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }
    
    return 0;
}