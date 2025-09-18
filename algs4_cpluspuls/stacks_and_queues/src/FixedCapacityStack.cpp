#include "Stack.h"
#include <string>
#include <iostream>
#include <stdexcept>

template<typename T>
class FixedCapacityStack: public Stack<T>
{
public:
    T* a;
    int N;          // 栈大小
    int capacity;   // 栈容量
public:
    FixedCapacityStack(int cap): N(0), capacity(cap) {
        a = new T[capacity];
    }
    ~FixedCapacityStack() override {
        delete[] a;
    }
    void push(T item) override {
        if (N == capacity) {
            throw std::runtime_error("Stack overflow");
        }
        a[N++] = item;
    }
    T pop() override {
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        return a[--N];
    }
    bool isEmpty() override {
        return N == 0;
    }
    int size() override {
        return N;
    }
};

int main(int argc, char* argv[]) {
    FixedCapacityStack<std::string> stack(100);
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
        for (int i = 0; i < stack.size(); i++) {
            std::cout << stack.a[i] << " "; // 访问栈内容
        }
        std::cout << std::endl;

    }
    std::cout << stack.size() << " left on stack" << std::endl;
    return 0;
}