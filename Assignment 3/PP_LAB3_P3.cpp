#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <string>

template<typename T>
class MyStack {
private:
    T *data;
    int maxS;
    int currentS;
public:
    MyStack(int maxSize);
    void push(const T& element);
    T pop();
    int maxSize();
    int currentSize();
    bool isEmpty();
    void display();
    ~MyStack() {
        delete[] data;
    };
};

template<typename T>
MyStack<T>::MyStack(int maxSize) {
    this->maxS = maxSize;
    data = new T[maxS];
    currentS = 0;
}

template<typename T>
void MyStack<T>::push(const T& element) {
    if (currentS >= maxS) {
        std::cout << "Error: Stack overflow" << std::endl;
        return;
    }
    data[currentS] = element;
    currentS++;
}

template<typename T>
T MyStack<T>::pop() {
    if (currentS <= 0) {
        std::cout << "Error: Stack underflow" << std::endl;
        return T();
    }
    currentS--;
    T element = data[currentS];
    return element;
}

template<typename T>
int MyStack<T>::maxSize() {
    return maxS;
}

template<typename T>
int MyStack<T>::currentSize() {
    return currentS;
}

template<typename T>
bool MyStack<T>::isEmpty() {
    return currentS == 0;
}

template<typename T>
void MyStack<T>::display() {
    std::cout << "Stack: ";
    for (int i = currentS - 1; i >= 0; i--) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    MyStack<int> stack1(5);
    MyStack<float> stack2(3);

    // Push elements into stack1
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    // Display stack1
    stack1.display();

    // Pop element
    stack1.pop();
    stack1.display();

    // Push elements into stack2
    stack2.push(4.1);
    stack2.push(5.2);
    stack2.push(6.3);
    
    // Display stack2
    stack2.display();

    // Push elements into stack3
    MyStack<std::string> stack3(2);
    stack3.push("omk");
    stack3.push("aha");

    // Display stack3
    stack3.display();


    return 0;
}
