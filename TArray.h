#ifndef __TArray__
#define __TArray__
#include<iostream>
#include<memory>
#include<algorithm>
#include<ostream>



template<typename T>
class TArray{
    private:
        T* m_data;
        size_t length;
    public:

        explicit TArray()=default;//默认构造函数

        //带参数的构造函数
        TArray(const T* tarray=nullptr,size_t length=0)
            :length(length)
        {
            if(length >0){
                m_data=new T[length];
                copy(tarray,tarray+length,m_data);
            }else{
                m_data=nullptr;
                length=0;
            }
        }

        //拷贝构造
        TArray(const TArray &other):length(other.length){
                if(other && length>0){
                    m_data=new  T[length];
                    copy(other.m_data,other.m_data+length,m_data);
                }else{
                    m_data=nullptr;
                    length=0;
            }
        }

        //拷贝赋值
        TArray& operator= (const TArray &other){
            if (this!=&other){
                delete[] m_data;
                length=other.length;
                if(length>0){
                    m_data=new T[length];
                    copy(other.m_data,other.m_data+length,m_data);
                }else{
                    m_data=nullptr;
                }
            }
            return *this;
        }
        ~TArray(){
            delete[] m_data;
        }


};

//智能指针管理内存
#endif