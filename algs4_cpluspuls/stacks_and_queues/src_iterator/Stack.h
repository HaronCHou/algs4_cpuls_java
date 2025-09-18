#pragma once
template <typename T>
class Stack
{
public:
    class Iterator{
    public:
        virtual ~Iterator(){}
        virtual T& operator*() = 0;     // 解引用操作
        virtual Iterator& operator++() = 0; // 前置++
        virtual Iterator& operator++(int) = 0; // 后置++
        virtual bool operator!=(const Iterator& other) const = 0; // 不等于操作
    };
    virtual Iterator* begin() = 0; // 返回指向第一个元素的迭代器
    virtual Iterator* end() = 0;   // 返回指向最后一个元素之后


    Stack(){};                             // create an empty stack
    virtual ~Stack(){};                    // destroy the stack

    // 纯虚函数，确保派生类必须实现这些方法
    virtual void push(T item) = 0;           // add an item to the top of the stack
    virtual T pop() = 0;                     // remove and return the item from the top of the stack
    virtual bool isEmpty() = 0;              // is the stack empty?
    virtual int size() = 0;                  // return the number of items on the stack
};