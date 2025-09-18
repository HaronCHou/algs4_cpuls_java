#pragma once
template <typename T>
class Stack
{
public:
    Stack(){};                             // create an empty stack
    virtual ~Stack(){};                    // destroy the stack

    // 纯虚函数，确保派生类必须实现这些方法
    virtual void push(T item) = 0;           // add an item to the top of the stack
    virtual T pop() = 0;                     // remove and return the item from the top of the stack
    virtual bool isEmpty() = 0;              // is the stack empty?
    virtual int size() = 0;                  // return the number of items on the stack
};