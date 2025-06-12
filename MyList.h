#ifndef __MyList__
#define __MyList__
#include<cstddef>

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
public:
//length的初始值要设为0，因为push函数中有计数器
    MyList(size_t length=0 ,const T& initval=T() ):m_head(nullptr),m_tail(nullptr),m_size(0){
        for (size_t i = 0; i < m_size ; i++)
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
        ListNode *current=m_head;
        MyList tmp(other);
        swap(*this,tmp);
        return *this;
        
    }
    void push_front(const T& p);
    void push_tail(const T& p);
    ~MyList(){
        ListNode* current=m_head;
        while (current!=nullptr)
        {
            ListNode *next=m_head->next;
            delete current;
            current=next;
        }
        m_head=m_tail=nullptr;
        m_size=0;
    }
    friend void swap(MyList& first, MyList& second) noexcept {
    using std::swap; // 允许 ADL (Argument-Dependent Lookup)
    swap(first.m_head, second.m_head);
    swap(first.m_tail, second.m_tail);
    swap(first.m_size, second.m_size);
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