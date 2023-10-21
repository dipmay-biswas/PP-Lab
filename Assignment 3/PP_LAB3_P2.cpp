#include <iostream>

class MyStack {
private:
    int *data;
    int maxS;
    int currentS;
public:
    MyStack(int maxSize);
    void push(int element);
    int pop();
    int maxSize();
    int currentSize();
    bool isEmpty();
    void display();
    ~MyStack();
};

MyStack::MyStack(int maxSize) {
    this->maxS = maxSize;
    data = new int[maxS];
    currentS = 0;
}

void MyStack::push(int element) {
    if (currentS >= maxS) {
        std::cout << "Error: Stack overflow" << std::endl;
        return;
    }
    data[currentS] = element;
    currentS++;
}

int MyStack::pop() {
    if (currentS <= 0) {
        std::cout << "Error: Stack underflow" << std::endl;
        return -1;
    }
    currentS--;
    int element = data[currentS];
    return element;
}

int MyStack::maxSize() {
    return maxS;
}

int MyStack::currentSize() {
    return currentS;
}

bool MyStack::isEmpty() {
    return currentS == 0;
}

void MyStack::display() {
    std::cout << "Stack: ";
    for (int i = currentS - 1; i >= 0; i--) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

MyStack::~MyStack() {
    delete[] data;
}


int main() {
    MyStack stack1(5);
    MyStack stack2(3);

    // Push elements into stack1
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    // Display stack1
    stack1.display();

    int p = stack1.pop();
    std::cout << "Popped "  << p << std::endl;

    // Push elements into stack2
    stack2.push(4);
    stack2.push(5);
    stack2.push(6);

    // Display stack2
    stack2.display();

    // Create a new stack using copy constructor
    MyStack stack3(stack1);

    // Display stack3
    stack3.display();

    // Update stack3 using = operator
    stack3 = stack2;

    // Display stack3
    stack3.display();

    return 0;
}

