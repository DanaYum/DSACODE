// You are using GCC
#include<iostream>
using namespace std;
int main()
{
    int n,key;
    cin>>n;
    int h[10];
    for(int i=0;i<n;i++)
        h[i]=-1;
        for(int i=0;i<n;i++)
        {
            //pass key, and find mid square
            cin>>key;
            int index=key*key;
            while(index>=n)
            {
                index=index/10;//descard from right
                //now left discard
                if(index >=n)
                {
                    int t;
                    if(index>1000)
                        t=1000;
                    else if(index>100)
                        t=100;
                    else
                        t=10;
                    index=index % t;    
                }
            }
            if(h[index]==-1)//no collision
                h[index]=key;
            else
            {
                while(h[index]!=-1)
                {
                    index++;
                    if(index==10)
                        index=0;
                }
                h[index]=key;
            }
            cout<<"Index "<<index<<" of key: "<<key<<endl;
        }
        for(int i=0;i<n;i++)
        {
            cout<<h[i]<<" ";
        }
}