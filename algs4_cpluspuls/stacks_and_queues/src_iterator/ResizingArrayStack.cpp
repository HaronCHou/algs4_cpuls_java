#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"

template<typename T>
class ResizingArrayStack: public Stack<T>{
private:
    T* a;          // 栈元素
    int N;         // 栈大小
    int capacity;  // 栈容量

    void resize(int newCapacity){
        T* newArray = new T[newCapacity];
        for(int i = 0; i < N; i++){
            newArray[i] = a[i];
        }
        delete[] a;
        a = newArray;
        capacity = newCapacity;
    }

public:
    ResizingArrayStack(): N(0), capacity(2){
        a = new T[capacity];
    }       
    ~ResizingArrayStack() override{
        delete[] a;
    }
    void push(T item) override{
        if(N == capacity){
            resize(2 * capacity);
        }
        a[N++] = item;
    }     // add an item to the top of the stack
    T pop() override{
        if(isEmpty()){
            throw std::runtime_error("Stack underflow");        
        }
        T item = a[--N];
        if(N > 0 && N == capacity / 4){
            resize(capacity / 2);
        }
        return item;
    }               // remove and return the item from the top of the stack
    bool isEmpty() override{
        return N == 0;  
    }        // is the stack empty?
    int size() override{
        return N;
    }             // return the number of items on the stack    

    class ResizingArrayStackIterator: public Stack<T>::Iterator{
    private:
        ResizingArrayStack* stack;
        int index; // 当前索引
    public:
        ResizingArrayStackIterator(ResizingArrayStack* s, int idx): stack(s ), index(idx) {}
        ~ResizingArrayStackIterator() override{}
        T& operator*() override{
            if(index < 0 || index >= stack->N){
                throw std::runtime_error("Dereferencing out of bounds");
            }       
            return stack->a[index];
        }   
        ResizingArrayStackIterator& operator++() override{ // 前置++
            ++index;    
            return *this;
        }
        ResizingArrayStackIterator& operator++(int) override{ // 后置++
            ResizingArrayStackIterator temp = *this;
            ++(*this); // 使用前置++逻辑
            return temp;    
        }
        bool operator!=(const typename Stack<T>::Iterator& other) const override{
            return index != dynamic_cast<const ResizingArrayStackIterator&>(other).index;
        }   
    };
    typename Stack<T>::Iterator* begin() override{
        return new ResizingArrayStackIterator(this, 0); // 指向第一个元素
    }       
    typename Stack<T>::Iterator* end() override{
        return new ResizingArrayStackIterator(this, N); // 指向最后一个元素之后 
    }

};

int main(int argc, char* argv[]){
    ResizingArrayStack<std::string> stack;
    std::string item;

    stack.push("a");
    // 迭代器测试
    for(auto it = stack.begin(); it != stack.end(); ++it)
    {
        std::cout << "rr";
        std::cout << **it << " "; // 访问栈内容
    }
    while(std::cin >> item){
        if(item != "-"){
            stack.push(item);
        }else if(!stack.isEmpty()){
            std::cout << stack.pop() << " ";
        }

        std::cout << "(" << stack.size() << " left on stack)" << std::endl;

        // 迭代器测试
        for(auto it = stack.begin(); it != stack.end(); ++it)
        {
            std::cout << "rr";
            std::cout << **it << " "; // 访问栈内容
        }
        std::cout << std::endl;
    }

    return 0;
}