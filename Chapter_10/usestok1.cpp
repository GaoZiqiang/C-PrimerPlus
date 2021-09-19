// usestok1.cpp -- using the Stock class
// compile with stock10.cpp
#include <iostream>
#include "stock10.h"

int main()
{
  {
    using std::cout, std::endl;
    cout << "测试使用默认构造函数" << endl;
    Stock stock;// 使用我们提供的默认构造函数:Stock::Stock()--且必须要有
    cout << "stock.show():" << endl;
    stock.show();

    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0);            // syntax 1
    stock1.show();
    Stock stock2 = Stock ("Boffo Objects", 2, 2.0); // syntax 2
    stock2.show();

    cout << "Assigning stock1 to stock2:\n";
    stock2 = stock1;// 将stock2对象赋值给stock1对象
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    // 不是对stock1对象进行初始化，而是将新值赋值给它--构造函数先创建一个临时对象，然后将该临时对象赋值给
    // stock1，然后再删除该临时对象
    stock1 = Stock("Nifty Foods", 10, 50.0);    // temp object
    cout << "Revised stock1:\n";
    stock1.show();
    cout << "Done\n";
  }
	// std::cin.get();
    return 0; 
}
