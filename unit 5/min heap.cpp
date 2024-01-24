// You are using GCC
#include <iostream>
using namespace std;

void heapify(int a[], int n, int i){
   int left=2*i +1;
   int right=2*i +2;
   int smallest=i;
   if(left<n && a[left]<a[smallest])
   smallest=left;
   if(right<n && a[right]<a[smallest])
   smallest=right;
   if(smallest!=i)
   {
       swap(a[i],a[smallest]);
       heapify(a,n,smallest);
   }
}
void minheap(int a[], int n) {
   for(int i= n/2-1; i >= 0; i--) {
      heapify(a,n,i);
   }
}
int main() {
   int n, i;
   cin>>n;
  
   int a[n];
   for (i = 0; i < n; i++) {
     cin>>a[i];
   }
   minheap(a, n);
   for (i = 0; i < n; i++) {
      cout<<a[i]<<" ";
   }
}