#include "Stack.h"
#include <string>
#include <iostream>
#include <stdexcept>

template<typename T>
class FixedCapacityStack: public Stack<T>
{
private:
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

    class FixedCapacityStackIterator: public Stack<T>::Iterator{
    private:
        FixedCapacityStack* stack;
        int index; // 当前索引
    public:
        FixedCapacityStackIterator(FixedCapacityStack* s, int idx): stack(s), index(idx) {}
        ~FixedCapacityStackIterator() override {}
        T& operator*() override {
            if (index < 0 || index >= stack->N) {
                throw std::runtime_error("Dereferencing out of bounds");
            }       
            return stack->a[index];
        }
        FixedCapacityStackIterator& operator++() override { // 前置++
            ++index;    
            return *this;
        }
        FixedCapacityStackIterator& operator++(int) override { // 后置++
            FixedCapacityStackIterator temp = *this;
            ++(*this); // 使用前置++逻辑
            return temp;
        }
        bool operator!=(const typename Stack<T>::Iterator& other) const override {
            return index != dynamic_cast<const FixedCapacityStackIterator&>(other).index;
        }
    };
    typename Stack<T>::Iterator* begin() override {
        return new FixedCapacityStackIterator(this, 0); // 指向第一个元素
    }
    typename Stack<T>::Iterator* end() override {
        return new FixedCapacityStackIterator(this, N); // 指向最后一个元素之后 
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
        // for (int i = 0; i < stack.size(); i++) {
        //     std::cout << stack.a[i] << " "; // 访问栈内容
        // }
        for(auto it = stack.begin(); it != stack.end(); ++it)
        {
            std::cout << **it << " "; // 访问栈内容
        }
        std::cout << std::endl;

    }
    std::cout << stack.size() << " left on stack" << std::endl;
    return 0;
}