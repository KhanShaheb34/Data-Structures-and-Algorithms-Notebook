#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a&a-1)
    cout<<a<<" is not power of 2"<<endl;
    else
    cout<<a<<" is power of 2"<<endl;
}
