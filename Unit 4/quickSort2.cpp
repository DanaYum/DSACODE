// enter names and heights and sort the name according to their height
#include <iostream>
#include <string>

using namespace std;

int partition(string names[], int heights[], int low, int high) {
    int pivot=heights[high];
    int tail=low-1;
    for(int i=low;i<high;i++)
    {
        if(heights[i] > pivot)
        {
            tail++;
            string temp=names[i];
            names[i]=names[tail];
            names[tail]=temp;
            int t=heights[i];
            heights[i]=heights[tail];
            heights[tail]=t;
        }
    }
    string temp=names[high];
    names[high]=names[tail+1];
    names[tail+1]=temp;
    int t=heights[high];
    heights[high]=heights[tail+1];
    heights[tail+1]=t;
    return tail+1;
    
}

void quickSort(string names[], int heights[], int low, int high) {
    
    if(low<high){
    
    int pe=partition(names,heights,low,high);
    quickSort(names,heights,low,pe-1);
    quickSort(names,heights,pe+1,high);
    }
    
}

int main() {
    int n;
    cin >> n;

    string names[100];
    int heights[100];

    for (int i = 0; i < n; i++) {
        cin >> names[i] >> heights[i];
    }

    quickSort(names, heights, 0, n - 1);

    for (int i =0; i<n; i++) {
        cout << names[i] << " ";
    }

    delete[] names;
    delete[] heights;
    return 0;
}