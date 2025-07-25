# C++

## class

首先是类的构造函数，以complex的构造为例

```C++

class complex
{
    private:
        double re,im;
    public:
        complex(double r=0,double i=0)
        : re(r),im(i)
        {}
}
```

complex的三行分别是参数设置，私有变量的初始化，以及另外的函数设置。
设置友元函数，可以访问私有成员变量。
参数的传递尽量考虑&。
返回的是by value还是by ref.

### 操作符

在c++中，操作符也是一种函数。所有成员函数都带有一个隐藏的this。

### 函数

成员函数 非成员函数，成员函数都隐藏有一个this指针，

### 操作符重载

cout是ostream的一个实例化对象，所以重载的第一个参数是 ostream& os,这个参数不能加const，因为加了const之后，os在这个函数中不可以改变，但在传输中，os在状态一直在改变。

### 类的编写过程

首先考虑类的数据类型，一般是存在private当中，然后考虑数据的类型会是什么（double，int，还是template）。接下来是构造函数，构造函数要接受预设的数据，然后要考虑数据的传递是by value还是by ref。构造函数要考虑初值列。接下来是设计函数，函数分为成员函数和非成员函数

## 构造函数big3

拷贝构造 拷贝赋值 析构函数

## 深拷贝和浅拷贝

浅拷贝只将指针拷贝过来，只用default copy ctor或者default op = 会造成别名，即一块内存对应两个地址。

## 栈和堆

栈是存在于作用域的一块内存空间。 在函数本体内声明的任何变量，其所使用的内存块都取自栈。
堆是指又操作系统提供的一块global内存空间，程序可动态分配从中获得若干块。当离开作用域的时候，指针就死亡了，但是指针指向的区域还在。
static的生命在作用域结束之后任然存在，直到程序结束。

## new 和 delete

new分为三步，第一步分配内存，第二步转化指针类型并返回首地址，第三步调用构造函数。
delete包括两个动作，第一步是调用析构函数，第二步释放内存。
以构造复数为例

```C++
complex* pc=new complex(2,1);
```

首先，你会获得两个double，也就是8个字节，除了复数本身，还会有8+1个（32+4字节）代码块，以及头尾各一个cookie（这里cookie的作用是记录大小），也就是2×4字节=8字节。总计8+36+8=52。而由于编译器每个内存块是16的倍数，所以会是64个字节。
如果array new没有和array delete搭配，会造成析构函数调用次数不足，出现内存泄漏

## 虚函数

non-virtual.virtual函数，pure virtual函数。

## 类与类之间的三大关系

* 复合
一个类包含另外一个类，就算是复合

## 转化函数不需要带返回值类型(conversion function)

## pointer-like classes 智能指针

以下是智能指针的源代码

```C++
template<class T>
class shared_ptr
{
public:
    T& operator*() const //解引用指针，返回对象的引用
    {return *px; }
    T* operator->() const  //访问对象成员 返回类型是T*
    {return px;}
    
    // 构造函数
    explicit shared_ptr(T* p=nullptr) :px(p) {
        if(px != nullptr){
            pn =new long(1);
        } else{
            p=nullptr;
        }
    }

    //拷贝构造
    explicit shared_ptr(const shared_ptr other ) : px(other.px),pn(other.pn){
        if(pn!=nullptr){
            ++(*pn);
        }
    }

    //拷贝赋值
    shared_ptr operator=(const shared_ptr &other){
        if(this!= &ohter){
            this=~shared.ptr;
            px=other.px;
            pn=other.pn;
            if(pn!=nullptr){
                ++(*pn);
            }
        }
        return *this;
    }
    //析构函数
    ~shared_pt(){
        decrementAndDestroy();
    }
private:
    T* px;
    long* pn;
    void decrementAndDestroy(){
        if(pn!=nullptr){
            --(*pn);
            if(*pn==0){
                delete px;
                delete pn;
            }
            pn=nullptr;
            px=nullptr;
        }
    }
}
```

## 三个主题

数量不定的模板参数，使用如下：

```C++
void print(){}
template<typename T,typename... Types>
void print(const T& firstArg,const Tpyes&...args){
    cout<<firstArg<<endl;
    print(args...);
}
```

## vptr和Vtbl

子类当中有父类的成分，所以父类有虚函数，子类一定也有虚函数，虚函数当中有一个指针，继承函数是继承调用权。虚函数的指针指向虚函数表，虚函数表中存放着函数的地址。
(* p-> vptr[n])(p) // 虚函数的作用路径

```c++
class A{
public:
    virtual void vfun1();
    virtual void vfun2();
            void fun1();
            void fun2();
private:
    int m_data1,m_data2;
};
class B:public A{
    public:
        virtual void vfun1();
            void fun2();
    private:
        m_data3;
};
class C:public A{
    public:
        virtual void vfun1();
        void fun2();
    private:
        int m_data1,m_data4;
} ;
```

静态绑定(call)和动态绑定(通过指针调用，up cast向上转析保证安全，调用的是虚函数)
