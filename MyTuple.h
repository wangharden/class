#ifndef __MyTuple__
#define __MyTuple__

#include<iostream>
using namespace std;

template<typename... Value> class MyTuple;

// 空元组特化（递归终止）
template<> class MyTuple<> {};


template<typename Head, typename... Tail>
class MyTuple<Head,Tail...>: public MyTuple<Tail...> {
    typedef MyTuple<Tail...> inherited;
public:
    MyTuple() {}
    
    // 添加 const 引用和转发以支持更多类型
    MyTuple(const Head& v, const Tail&... vtail)
        : m_head(v), inherited(vtail...) {}
    
    MyTuple(Head&& v, Tail&&... vtail)
    : m_head(std::forward<Head>(v)), inherited(std::forward<Tail>(vtail)...) {}
    
    ~MyTuple() {}
     // 访问函数
    Head& head() { return m_head; }
    const Head& head() const { return m_head; }
    
    inherited& tail() { return *this; }
    const inherited& tail() const { return *this; }
    
protected:
    Head m_head;
};
   

// 辅助函数
template<size_t N, typename Tuple>
struct MyTupleElement;

// 特化：索引为 0 的情况（当前头部）
template<typename Head, typename... Tail>
struct MyTupleElement<0, MyTuple<Head, Tail...>> {
    using type = Head;  // 定义类型别名
};

// 特化：索引 > 0 的情况（递归处理尾部）
template<size_t N, typename Head, typename... Tail>
struct MyTupleElement<N, MyTuple<Head, Tail...>>
    : MyTupleElement<N-1, MyTuple<Tail...>> {};

// 获取元组元素的非成员函数
template<size_t N, typename... Args>
auto& get(MyTuple<Args...>& t) {
    // 使用 if constexpr 进行编译时条件判断
    if constexpr (N == 0) {
        return t.head();
    } else {
        // 递归调用 tail() 部分
        return get<N-1>(t.tail());
    }
}

// const 版本的 get
template<size_t N, typename... Args>
const auto& get(const MyTuple<Args...>& t) {
    if constexpr (N == 0) {
        return t.head();
    } else {
        return get<N-1>(t.tail());
    }
}


#endif