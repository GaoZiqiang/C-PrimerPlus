// usestok2.cpp -- using the Stock class
// compile with stock20.cpp
#include <iostream>
#include "stock20.h"

const int STKS = 4;

int main()
{{
// create an array of initialized objects--初始化对象的数组
    Stock stocks[STKS] = {// 先创建的后析构--因为对象作为自动变量被存放在栈中
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        stocks[st].show();

    // 使用打擂台法选择top Stock对象
    // 使用stock指针来追踪值最高的Stock对象
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
// now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
	top->show();}
    // std::cin.get();
    return 0; 
}
