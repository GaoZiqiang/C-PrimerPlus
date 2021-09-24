// strngbad.cpp -- StringBad class methods
#include <cstring>                    // string.h for some
#include "strngbad.h"
using std::cout;

// initializing static class member
// 初始化静态类成员变量--不能在类声明中初始化静态类成员变量
// 可以在类声明之外单独进行静态成员变量初始化--因为静态成员变量单独存储，而不是对象的组成部分\
// 如果在头文件中进行初始化，将出现等多个初始化语句副本，从而引发错误？？--不理解
int StringBad::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad::StringBad(const char * s)
{
    // 计算字符串的长度
    len = std::strlen(s);             // set size
    // 使用new分配足够的空间来保存字符串，并将新内存的地址赋给str
    str = new char[len + 1];          // allot storage
    // 将形参s传递的字符串负载到新分配的内存中
    std::strcpy(str, s);              // initialize pointer
    // 所有类对象共享同一个静态成员变量
    num_strings++;                    // set object count
    cout << num_strings << ": \"" << str
         << "\" object created\n";    // For Your Information
}

// 默认构造函数
StringBad::StringBad()                // default constructor
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");          // default string
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" default object created\n";  // FYI
}

StringBad::~StringBad()               // necessary destructor
{
    cout << "\"" << str << "\" object deleted, ";    // FYI
    --num_strings;// 析构一个对象,num_strings-1                    // required
    cout << num_strings << " left\n"; // FYI
    delete [] str;                    // required
}

// 重载运算符<<
std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os; 
}
