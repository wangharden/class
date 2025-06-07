#include"complex.h"
#include<iostream>
#include<memory>

using namespace std;

int main(){
    complex c1(2,1);
    complex c2;
    c2=c1+c2;
    int i=3/2;
    int *a = &i;
    shared_ptr<int> sp(new int(1));
    cout<<*sp;
    return 0;
}
