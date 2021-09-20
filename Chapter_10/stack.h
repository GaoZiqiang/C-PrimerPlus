// stack.h -- class definition for the stack ADT--实现一个栈
#ifndef STACK_H_
#define STACK_H_

// 定义栈内元素类型为long
typedef unsigned long Item;

class Stack
{
private:
//    enum {MAX = 10};    // constant specific to class
    static const int MAX = 10;// 也可以使用静态关键字static来表示类内常量
    Item items[MAX];    // holds stack items
    int top;            // index for top stack item
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
};
#endif
