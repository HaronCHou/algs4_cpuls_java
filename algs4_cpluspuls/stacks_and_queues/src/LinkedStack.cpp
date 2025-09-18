#include "Stack.h"
#include <iostream>
#include <string>

template <typename T>
class LinkedStack: public Stack<T>
{
public:
    struct Node
    {
        T item;
        Node* next;
        Node(): item(T()), next(nullptr) {} // 默认构造函数
    };
public:
    Node* first; // top of stack
    int n;       // size of the stack

public:
    LinkedStack():n(0),first(nullptr) {}         // create an empty stack
    ~LinkedStack() override{
        while (!isEmpty()) {
            pop();
        }
    }         // destroy the stack


    void push(T item) override{
        Node* oldFirst = first;
        first = new Node;
        first->item = item;
        first->next = oldFirst;
        n++;
    }     // add an item to the top of the stack
    T pop() override{
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        T item = first->item;
        Node* oldFirst = first;
        first = first->next;
        delete oldFirst;
        n--;
        return item;
    }               // remove and return the item from the top of the stack
    bool isEmpty() override{
        return first == nullptr;
    }        // is the stack empty?
    int size(){
        return n;
    }             // return the number of items on the stack
};


int main(int argc, char* argv[]) {
    LinkedStack<std::string> stack;
    std::string s;
    while (std::cin >> s) {
        if (s == "-") {
            if (!stack.isEmpty()) {
                stack.pop();
            }
        } else {
            stack.push(s);
        }
        // 手动遍历
        std::cout  << s << " | Stack Display: ";
        LinkedStack<std::string>::Node* cur = stack.first;
        while (cur != nullptr) {
            std::cout << cur->item << " ";
            cur = cur->next;
        }
        std::cout << std::endl; // 换行
    }
    std::cout << "(" << stack.size() << " left on stack)" << std::endl;
    return 0;
}