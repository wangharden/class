#include<iostream>
#include<string>
#include<typeinfo>

/*template<typename T>
void func() {
	static int count = 0;
	std::cout << "Type:" << typeid(T).name() << ", count: " << count++ << std::endl;
}

int main() {
	func<int>();
	func<double>();
	func<std::string>();
	func<int>();
	func<double>();
	return 0;
} */

class D{
	public:
	void printA(){std::cout<<"A"<<std::endl;}
	virtual void printB(){std::cout<<"B"<<std::endl;}
};

class E{
int a;
char b;
bool c;
};

class F{
char b;
int a;
bool c;
};

int main(){

	size_t d_size=sizeof(F);
	std::cout<<"sizeof(F) = "<<d_size<<std::endl;
	return 0;
}