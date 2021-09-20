// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>  

class Stock  // class declaration
{
private:
    double total_val;
    void set_tot();// 设置为内联函数
public:
    std::string company;
    long shares;
    double share_val;

    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};    // note semicolon at the end

#endif