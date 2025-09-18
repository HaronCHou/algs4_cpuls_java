1. template模版类，接口类；
2. iterator 迭代器
3. generic

# 附录一

错误提示：

```
error: ‘bool LinkedStack<T>::LinkedStackIterator::operator!=(const LinkedStack<T>::LinkedStackIterator&) const [with T = std::__cxx11::basic_string<char>]’ marked ‘override’, but does not override
```

这个错误的意思是，`LinkedStackIterator::operator!=` 被标记为 `override`，但是它并没有正确覆盖基类中的虚函数。

### 错误原因

* 这个错误通常发生在你尝试重载一个虚函数（如 `operator!=`），但是基类中的虚函数签名和派生类中的签名不匹配。
* 具体来说，你在 `LinkedStackIterator` 中重载了 `operator!=` 函数，但是该函数的签名与基类中的 `operator!=` 函数签名不一致，因此编译器认为你没有正确重载。

### 解决方法

* 你应该确保 `LinkedStackIterator::operator!=` 的签名与基类中 `Stack<T>::Iterator::operator!=` 的签名完全一致。具体来说，你在 `LinkedStackIterator` 中重载的 `operator!=` 函数的参数类型必须与基类中的虚函数签名匹配。

### 代码修正

问题出在 `operator!=` 函数的参数类型不匹配。`LinkedStackIterator` 的 `operator!=` 参数应该是 `const Stack<T>::Iterator&` 类型，而不是 `const LinkedStackIterator&` 类型，因为 `operator!=` 是在基类 `Iterator` 中声明的。

### 1. 修正 `operator!=` 函数签名

修改 `LinkedStackIterator` 中的 `operator!=` 方法签名，确保它与基类中的 `operator!=` 完全一致：

#### 修正后的代码：

```cpp
template <typename T>
class LinkedStack : public Stack<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* topNode;

public:
    LinkedStack() : topNode(nullptr) {}

    ~LinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const override {
        return topNode == nullptr;
    }

    void push(const T& value) override {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() override {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const override {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        return topNode->data;
    }

    // LinkedStackIterator 类
    class LinkedStackIterator : public Stack<T>::Iterator {
    private:
        Node* current;

    public:
        LinkedStackIterator(Node* node) : current(node) {}

        T& operator*() override {
            return current->data;
        }

        LinkedStackIterator& operator++() override {
            current = current->next;
            return *this;
        }

        LinkedStackIterator operator++(int) override {
            LinkedStackIterator temp = *this;
            ++(*this);
            return temp;
        }

        // 修正 operator!= 参数类型为基类的 Iterator& 类型
        bool operator!=(const typename Stack<T>::Iterator& other) const override {
            return current != dynamic_cast<const LinkedStackIterator&>(other).current;
        }
    };

    // begin() 和 end() 返回迭代器
    Stack<T>::Iterator* begin() override {
        return new LinkedStackIterator(topNode);
    }

    Stack<T>::Iterator* end() override {
        return new LinkedStackIterator(nullptr);
    }
};
```

### 关键修正：

* `operator!=` 的参数类型修改为 `const typename Stack<T>::Iterator&`，这样就与基类 `Iterator` 的签名一致了。
* 通过 `dynamic_cast` 来将 `other` 转换为 `LinkedStackIterator` 类型，以便比较两个迭代器。

### 为什么会发生错误？

`operator!=` 是 `Stack<T>::Iterator` 类中的虚函数，因此它的签名在基类中已经确定。如果你在派生类（即 `LinkedStackIterator`）中想要重载它，必须确保参数类型完全匹配。如果不匹配，编译器就会报告你没有正确覆盖虚函数。

### 总结

通过确保 `LinkedStackIterator` 中的 `operator!=` 函数的参数类型与基类中的函数签名一致，问题就可以解决。




这个警告：

```
warning: reference to local variable ‘temp’ returned [-Wreturn-local-addr]
```

的意思是你正在返回一个局部变量的引用。具体来说，在你的 `operator++(int)` 方法中，`temp` 是一个局部变量，你返回了它的引用，但在函数结束后，`temp` 会被销毁，因此返回它的引用会导致悬空引用的问题。

### 解决方法

`operator++(int)` 是后置递增运算符，它应该返回一个 **值**（而不是引用），因此你应该返回 `temp` 的拷贝，而不是引用。为了避免返回悬空引用，你只需修改返回类型为返回 `temp` 的值。

### 修正代码

将 `operator++(int)` 返回 `temp` 的拷贝，而不是引用：

```cpp
LinkedStackIterator operator++(int) override {
    LinkedStackIterator temp = *this;  // 保存当前迭代器的副本
    ++(*this);  // 执行前置递增
    return temp;  // 返回副本（按值返回）
}
```

### 代码说明

* **`operator++(int)`**：后置递增运算符通常会先返回当前迭代器的副本，然后将迭代器递增，最后返回副本。返回副本是因为后置递增的语义是“返回当前值，并在原地递增”。
* **`temp`** 是一个局部变量，`operator++(int)` 的作用是保存当前迭代器的状态，并在递增后返回它的副本，而不是引用。返回副本是合法且推荐的做法。

### 总结

* 在 `operator++(int)` 中，返回副本而不是引用，避免了悬空引用问题。
* 通过这种方式，您将遵循 C++ 的惯例，确保返回有效的值。

这个警告是关于返回局部变量的引用的问题，正确的做法是返回一个副本。
