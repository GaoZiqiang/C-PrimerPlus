// vegnews.cpp -- using new and delete with classes
// compile with strngbad.cpp
#include <iostream>
using std::cout;
//#include "strngbad.h"
#include "string1.h"

void callme1(String &);  // pass by reference
void callme2(String);    // pass by value

int main()
{
    using std::endl;
    // 内部代码块
    {
        cout << "Starting an inner block.\n";
        String headline1("对象headline1");
        String headline2("对象headline2");
        String sports("对象sports");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        // 引用传递
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;\
        // 值传递--生成对象副本--使用了复制构造函数
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";

        // 对象赋值时使用复制构造函数--
        // 有两种可能的处理方式：
        // 1 它将创建对象的一个副本/临时对象，然后将该临时对象赋值给sailor;
        // 2 直接创建sailor;

        // 等价于--(逐个复制非静态成员)--静态成员变量num_strings不变
        // StringBad sailor;
        // sailor.str = sports.str;
        // sailor.str = sports.len;
        String sailor = sports;// 使用复制构造函数(或者复制+赋值)
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        String knot;// 使用默认构造函数
        knot = headline1;// 使用重载的赋值运算符--赋值
        cout << "knot: " << knot << endl; 
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    // std::cin.get();
    return 0;
}

// 引用传递
void callme1(String & rsb)
{
    cout << "String passed by reference:\n";
    cout << "       \"" << rsb << "\"\n";
}

// 值传递
void callme2(String sb)
{
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}
