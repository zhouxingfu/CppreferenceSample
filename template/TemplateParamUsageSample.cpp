//In this file, we will test the following scenarios
// 1. What if constructor template param type is not compatible with class template param type?
// 2. 

#include<iostream>
#include<string>
#include<cstring>

template<typename T, typename U>
class A
{
public:
    A(U u){
        str_ = u;
        std::cout << __LINE__ << std::endl;
    }

    T get_param()
    {
        return param_;
    }

    U get_str()
    {
        return str_;
    }
private:
    T param_;
    U str_;
};

template<int size>
class B
{
public:
    B(){
        param_ = new int[size];
        std::memset(param_, 0, sizeof(int)* size);
    }

    int Size(){
        return sizeof(param_) / sizeof(int);
    }
private:
    int* param_;
};

int main(int argc, char* argv[])
{
    A<int, std::string> a("HelloWorld!");
    std::cout << a.get_str() << std::endl;

    B<100> b;
    std::cout << b.Size() << std::endl;
    return 0;
}