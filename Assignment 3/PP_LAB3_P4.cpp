#include <iostream>

class MyStack {
private:
    static int stackCount;
    static const int MAX_STACK_COUNT = 10;
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
    friend MyStack operator + (MyStack const &obj1, MyStack const &obj2);
    ~MyStack();
};

MyStack::MyStack(int maxSize) {
    if (stackCount < MAX_STACK_COUNT) {
            this->maxS = maxSize;
            data = new int[maxS];
            this->currentS = 0;
            stackCount++;
    }

    else{
            std::cout << "Maximum stack limit reached" << std::endl;
            exit(0);
    }
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

MyStack operator + (MyStack const &obj1, MyStack const &obj2) {
    MyStack res(obj1.maxS + obj2.maxS);
    for (int i = 0; i < obj1.currentS; i++) {
        res.push(obj1.data[i]);
    }
    for (int i = 0; i < obj2.currentS; i++) {
        res.push(obj2.data[i]);
    }
    return res;
}

MyStack::~MyStack() {
    stackCount--;
    delete[] data;
}

int MyStack::stackCount = 0;

int main() {
    int size1, size2;
    std::cout << "Enter stack one size: ";
    std::cin >> size1;

    std::cout << "Enter stack two size: ";
    std::cin >> size2;

    MyStack aStackA(size1), aStackB(size2);

    std::cout << "Push " << size1 << " data into stack 1: ";
    for(int i = 0; i < size1; i++){
        int n;
        std::cin >> n;
        aStackA.push(n);
    }

    std::cout << "Push " << size2 << " data into stack 2: ";
    for(int i = 0; i < size2; i++){
        int n;
        std::cin >> n;
        aStackB.push(n);
    }

    std::cout << "Stack A: ";
    aStackA.display();
    std::cout << "Stack B: ";
    aStackB.display();
    MyStack aStackC = aStackA + aStackB;
    std::cout << "Stack C: ";
    aStackC.display();
}

