#ifndef __MyList__
#define __MyList__
#include<cstddef>
#include<ostream>
#include<iterator>

template<typename T>
class MyList
{
private:
    struct ListNode
    {
        T data;
        ListNode* next;
        ListNode(const T& val,ListNode* n=nullptr):data(val),next(n){}
    };
    ListNode* m_head;
    ListNode* m_tail;
    size_t m_size;

//迭代器:
    class iterator {
    public:
        // 标准类型别名（兼容标准库算法）
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::input_iterator_tag; // 简化为输入迭代器

        // 构造函数：用 ListNode 指针初始化
        iterator(ListNode* node = nullptr) : m_node(node) {}

        // 解引用操作符：返回元素的引用
        reference operator*() const { return m_node->data; }
        // 箭头操作符：返回元素的指针
        pointer operator->() const { return &(m_node->data); }

        // 前缀自增（++it）：移动到下一个节点
        iterator& operator++() {
            if (m_node) m_node = m_node->next;
            return *this;
        }
        // 后缀自增（it++）：返回旧值，再自增
        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        // 相等性判断
        bool operator==(const iterator& other) const { return m_node == other.m_node; }
        bool operator!=(const iterator& other) const { return m_node != other.m_node; }

    private:
        ListNode* m_node; // 迭代器封装的节点指针
    };

    class const_iterator {
    public:
        using value_type = const T;
        using pointer = const T*;
        using reference = const T&;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::input_iterator_tag;

        const_iterator(ListNode* node = nullptr) : m_node(node) {}

        reference operator*() const { return m_node->data; }
        pointer operator->() const { return &(m_node->data); }

        const_iterator& operator++() {
            if (m_node) m_node = m_node->next;
            return *this;
        }
        const_iterator operator++(int) {
            const_iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const const_iterator& other) const { return m_node == other.m_node; }
        bool operator!=(const const_iterator& other) const { return m_node != other.m_node; }

    private:
        ListNode* m_node;
    };


public:

//length的初始值要设为0，因为push函数中有计数器
    MyList(size_t length=0 ,const T& initval=T() ):m_head(nullptr),m_tail(nullptr),m_size(0){
        for (size_t i = 0; i < length ; i++)
        {
            push_tail(initval);
        }
        
    }

    MyList(const MyList& other):m_head(nullptr),m_tail(nullptr),m_size(0){
        ListNode* current=other.m_head;
        while (current!=nullptr)
        {
            push_tail(current->data);
            current=current->next;
        }
        
    }

    MyList& operator=(const MyList& other){
        if(this==&other) return *this;
        MyList tmp(other);
        swap(*this,tmp);
        return *this;
        
    }

    //移动构造
    MyList(MyList && other) noexcept
        :m_head(other.m_head),m_tail(other.m_tail),m_size(other.m_size){
            other.m_head=nullptr;
            other.m_tail=nullptr;
            other.m_size=0;
        }
    
    //移动赋值
    MyList& operator=(MyList&& other)noexcept{
        if(this!=&other){
            swap(*this,other);
        }
        return *this;
    }

    // ------------------- 新增迭代器接口 -------------------
    // 返回指向第一个元素的迭代器
    iterator begin() { return iterator(m_head); }
    // 返回指向尾后位置的迭代器（即 nullptr）
    iterator end() { return iterator(nullptr); }

    // 常量版本（用于 const MyList 对象）
    const_iterator begin() const { return const_iterator(m_head); }
    const_iterator end() const { return const_iterator(nullptr); }
    const_iterator cbegin() const { return const_iterator(m_head); }
    const_iterator cend() const { return const_iterator(nullptr); }
    // ------------------- 迭代器接口结束 -------------------


    //辅助函数
    void push_front(const T& p);
    void push_tail(const T& p);
    ~MyList(){
        ListNode* current=m_head;
        while (current!=nullptr)
        {
            ListNode *next=current->next;
            delete current;
            current=next;
        }
        m_head=m_tail=nullptr;
        m_size=0;
    }
    size_t size() const{return m_size;}
    friend void swap(MyList& first, MyList& second) noexcept {
    using std::swap; // 允许 ADL (Argument-Dependent Lookup)
    swap(first.m_head, second.m_head);
    swap(first.m_tail, second.m_tail);
    swap(first.m_size, second.m_size);
}
    friend std::ostream& operator<<(ostream& os,const MyList &other){
        ListNode* current= other.m_head;
        while(current!=nullptr){
            os<< current->data<<" ";
            current=current->next;
        }
        return os;
    }
};

template<typename T>
void MyList<T>::push_front(const T& p){
    ListNode* newNode=new ListNode(p,m_head);
    if (!m_head)
    {
        m_tail=newNode;
    }
    m_head=newNode;
    m_size++;
    
}

template <typename T>
void MyList<T>::push_tail(const T& p){
    ListNode* newNode=new ListNode(p,nullptr);//新节点的next应设为nullptr（尾节点无后续）
    if (! m_tail)
    {
        m_head=newNode;
        m_tail=newNode;
    }else{
        m_tail->next=newNode;
        m_tail=newNode;
    }
    m_size++;
    
}

#endif