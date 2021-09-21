// support.cpp -- use external variable
// compile with external.cpp
#include <iostream>
extern double warming;  // use warming from another file

// function prototypes
void update(double dt);
void local();

using std::cout;
void update(double dt)      // modifies global variable
{
    // 此处声明使用外部定义的变量warming--通过这个名称使用在外面定义的变量
    // 可以省略，仍然会调用外部声明的warming--如果用double就不行了
    // 另外，使用extern外部声明变量，就不可以再次初始化了--extern double warming = 1.0;就不允许了
    //extern double warming;  // optional redeclaration
    warming += dt;          // uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()                // uses local variable
{
    double warming = 0.8;   // new variable hides external one--局部变量

    cout << "Local warming = " << warming << " degrees.\n";
        // Access global variable with the
        // scope resolution operator
    cout << "But global warming = " << ::warming;// 此时局部变量warming会覆盖掉全局变量warming
    cout << " degrees.\n";
}
