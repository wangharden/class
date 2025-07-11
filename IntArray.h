#include<iostream>
#include<memory>
#include<algorithm>
#include<ostream>
#include <stdexcept> // 用于异常

using namespace std;

class IntArray{
public:
    IntArray():data(nullptr),length(0){}
    IntArray(const int* other=nullptr,size_t length=0):length(length){
        if(other && length>0){
            data=new int[length];
            std::copy(other, other + length, data);
        }else{
            data=nullptr;
            this->length=0;
        }
    }
    IntArray(const IntArray &other):length(other.length){
        if(other.data && length>0){
            data=new int[length];
            copy(other.data,other.data+length,data);
        }else{
            data=nullptr;
            length=0;
        }
    }
    IntArray& operator=(const IntArray &other){
        if(this!= &other){
            delete[] data;
            length=other.length;
            if(length>0){data=new int[length];
            std::copy(other.data, other.data + length, data);}
            else{
            data=nullptr;
        }
        }
        return *this;
    }
    ~IntArray(){
        delete[] data;
    }
    // 访问元素
    int& operator[](int& index){
        if(index>length) throw out_of_range("index out of range");
        return data[index];
    }

    // 内容比较
    bool operator==(const IntArray& other) const {
        if (length != other.length) return false;
        return equal(data, data + length, other.data);
    }

    friend ostream& operator<<(ostream& os,const IntArray& ina);
    private:
        int* data;
        size_t length;
    
};
ostream& operator<<(ostream& os,const IntArray& ina){
    if(ina.length==0){
        os<<"[]";
        return os;
    }else{
        os<<"[";
        for(size_t i=0;i<ina.length-1;++i){
            os<<ina.data[i]<<",";
        }
        os<<ina.data[ina.length-1]<<"]";
        return os;
    }
}