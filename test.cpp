#include<iostream>
#include<string>

template <typename T>
void func() {
    static int count = 0;  
    std::cout << "Type: " << typeid(T).name() 
              << ", Count: " << ++count << std::endl;
}

int main(){
    func<int>();
    func<double>();
    func<int>();
    func<std::string>();
    func<double>();
    return 0;
}