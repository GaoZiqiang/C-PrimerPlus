// strngbad.h -- flawed string class definition
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class StringBad
{
private:
    char * str;                // pointer to string
    int len;                   // length of string

    // 静态成员变量--所有类对象共享同一个静态类成员
    // 如果静态成员变量为const整数类型或枚举型，则可以在类生命中进行初始化
    static int num_strings;    // number of objects
public:
    StringBad(const char * s); // constructor
    StringBad();               // default constructor
    ~StringBad();              // destructor
// friend function
    // 重载运算符<<
    friend std::ostream & operator<<(std::ostream & os, 
                       const StringBad & st);
};
#endif
