// string1.cpp -- String class methods
#include <cstring>                 // string.h for some
#include "string1.h"               // includes <iostream>
using std::cin;
using std::cout;
using std::endl;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char * s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    std::strcpy(str, s);           // initialize pointer
    num_strings++;                 // set object count
    cout << num_strings << ": \"" << str
         << "\" 显式构造函数--default object created\n";  // FYI
}

// 默认构造函数
String::String()                   // default constructor
{
    len = 4;
//    str = nullptr;
    str = new char[1];
    str[0] = '\0';                 // default string--等价于str = 0;--为了与析构函数中的delete []str兼容
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" 默认构造函数--default object created\n";  // FYI
}

// 复制构造函数
String::String(const String & st)
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char [len + 1];  // allot space
    std::strcpy(str, st.str);  // copy string to new location
    cout << num_strings << ": \"" << str
         << "\" 复制构造函数--default object created\n";  // FYI
}

String::~String()                     // necessary destructor
{
    cout << "\"" << str << "\" object deleted, 还剩 " << --num_strings << " 个对象" << endl;    // FYI
    //--num_strings;                    // required
    delete [] str;                    // required
}

// overloaded operator methods    

    // assign a String to a String--赋值运算符
String & String::operator=(const String & st)
{
    cout << "赋值运算符" << endl;
    // 判断自身赋值
    if (this == &st)
        return *this;
    // 释放旧资源
    delete [] str;
    // 重新分配
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;// 返回对象引用
}

    // assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

    // read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}

    // read-only char access for const String
const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

    // simple String output
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os; 
}

    // quick and dirty String input
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is; 
}
