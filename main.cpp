#include"complex.h"
#include<iostream>
#include<memory>
#include<algorithm>
#include<ostream>
#include"IntArray.h"

using namespace std;



int main(){
    complex c1(2,1);
    complex c2;
    c2=c1+c2;
    int i=3/2;
    int *a = &i;
    int *p =new int[10];
    shared_ptr<int> sp(new int(1));
    delete p;
    int num[]={1,2,3,4};
    IntArray arr(num,4);
    int num1[]={1,2,3};
    int num2[]={3};
    IntArray arr2(num2,1);

    IntArray arr1(num1,3);
    
    arr=arr1=arr2;
    cout<<arr;
    return 0;
}
