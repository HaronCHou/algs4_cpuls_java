#include "Stack.h"
#include <iostream>
#include <string>

template <typename T>
class LinkedStack: public Stack<T>
{
private:
    struct Node
    {
        T item;
        Node* next;
        Node(): item(T()), next(nullptr) {} // 默认构造函数
    };
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

    class LinkedStackIterator : public Stack<T>::Iterator {
    private:
        Node* current;
    public:
        LinkedStackIterator(Node* start) : current(start) {}
        ~LinkedStackIterator() override {}
        T& operator*() override{
            if(current == nullptr) {
                throw std::runtime_error("Dereferencing end iterator");
            }
            return current->item;
        }
        // 前置++ == stackIterator it = ...; ++it; 先自增，再获取内容
        LinkedStackIterator& operator++() override{
            if(current != nullptr) {
                current = current->next;
            }
            return *this;
        }
        // 后置++ == stackIterator it = ...; it++; 先获取内容，再自增
        LinkedStackIterator& operator++(int) override{
            LinkedStackIterator temp = *this;
            ++(*this);  // 使用上面已经实现了的前置++逻辑
            return temp;
        }
        // bool operator!=(const LinkedStackIterator& other) const override{
        //     // other 可能是基类类型的引用，需要动态转换, dynamic_cast是运行时类型检查
        //     return this->current !=dynamic_cast<const LinkedStackIterator&>(other).current;            
        // }
        // 修正 operator!= 参数类型为基类的 Iterator& 类型
        bool operator!=(const typename Stack<T>::Iterator& other) const override {
            return current != dynamic_cast<const LinkedStackIterator&>(other).current;
        }
    };
    // 为什么这里要返回基本类型的迭代器，使用new？因为栈的迭代器类型是嵌套类，无法在外部直接访问
    // 这里返回值类型使用LinkedStackIterator* 会导致编译错误？为什么？
   typename Stack<T>::Iterator* begin() override {
        return new LinkedStackIterator(first);
    } // 返回指向第一个元素的迭代器
    typename Stack<T>::Iterator* end() override {
        return new LinkedStackIterator(nullptr);
    }   // 返回指向最后一个元素之后


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
        // for(Stack<std::string>::Iterator* it = stack.begin(); *it != *stack.end(); ++(*it)) {
        //     std::cout << **it << " "; // 访问栈内容
        // }
        for(auto it = stack.begin(); *it != *stack.end(); ++(*it)) {
            std::cout << **it << " "; // 访问栈内容
        }
        std::cout << std::endl;
    }
    std::cout << "(" << stack.size() << " left on stack)" << std::endl;
    return 0;
}