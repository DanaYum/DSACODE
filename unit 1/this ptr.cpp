#include<iostream>
using namespace std;
class Test
{
private:
int l1,w1,l2,w2;
public:
void get1()
{
    cin>>this->l1;
    cin>>this->w1;
}
void get2()
{
    cin>>this->l2;
    cin>>this->w2;
}
void calculateArea1()
{
	cout<<"area1:"<<this->l1*this->w1<<endl;
}
void calculateArea2()
{
    cout<<"area2:"<<this->l2*this->w2<<endl;
}
void comparision()
{
    if(this->l1==this->l2 && this->w1==this->w2)
    cout<<"they have same dimensions..!";
    else
    cout<<"they got different dimensions..!";
}
};

int main()
{
Test obj;
obj.get1();
obj.calculateArea1();
obj.get2();
obj.calculateArea2();
obj.comparision();


return 0;
}

