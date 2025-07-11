#ifndef __MyVector__
#define __MyVector__

using namespace std;
#include<iostream>

template<typename T>
class MyVector{
    private:
        T* m_data;
        size_t m_size;
        size_t capacity;
    public:
    //默认构造
    MyVector():m_data(nullptr),m_size(0),capacity(0){}
    explicit MyVector(size_t n,const T& value=T()) : m_data(nullptr),m_size(0),capacity(0){
        reserve(size);
        for(size_t i=0;i<n;i++){
            push_back(value);
        }
    }

    //拷贝构造
    MyVector(const MyVector& other):m_data(nullptr),m_size(0),capacity(0){
        reserve(other.m_size);
        for(size_t i=0;i<n;i++){
            push_back(other.m_data[i]);
        }
    }
    MyVector(const MyVector& other){
        if(this!=&other){
            MyVector temp(other);
            swap(temp);
            return *this;
        }
    }

    //拷贝赋值
    MyVector(const MyVector&& other)noexcept:m_data(other.m_data),m_size(other.m_size),capacity(other.capacity){
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    MyVector& operator=(MyVector&& other) noexcept{
        if(this!=&other){
            swap(*this,other);
        }
        return *this;
    }


    //辅助函数
    void swap(MyVector& other) noexcept {
            std::swap(m_data, other.m_data);
            std::swap(m_size, other.m_size);
            std::swap(m_capacity, other.m_capacity);
        }
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    bool empty() const { return m_size == 0; }
    void reserve(size_t new_capacity) {
            if (new_capacity <= m_capacity) return;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < m_size; i++) {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
    void push_back(const T& value) {
            if (m_size >= m_capacity) {
                reserve(m_capacity == 0 ? 1 : m_capacity * 2);
            }
            m_data[m_size] = value;
            m_size++;
        }
    void pop_back() {
            if (m_size > 0) {
                m_size--;
            }
        }
    T& operator[](size_t index) {
            return m_data[index];
        }
        const T& operator[](size_t index) const {
            return m_data[index];
        }
        void clear() {
            m_size = 0;
        }
    ~MyVector(){
        delete[] m_data;
    }

};



#endif