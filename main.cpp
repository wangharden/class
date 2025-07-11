#include"complex.h"
#include<iostream>
#include<memory>
#include<algorithm>
#include<ostream>
#include"IntArray.h"
#include"MyList.h"
#include"MyTuple.h"

using namespace std;



int main(){
    /*complex c1(2,1);
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
    cout<<arr;*/

    MyTuple<int, int, const char*> m(11, 22, "wang");
    
    // 测试元素访问
    cout << get<0>(m) << endl;  // 11
    cout << get<1>(m) << endl;  // 22
    cout << get<2>(m) << endl;  // wang
    
    // 测试修改元素
    get<0>(m) = 100;
    cout << get<0>(m) << endl;  // 100
    
    return 0;
}

