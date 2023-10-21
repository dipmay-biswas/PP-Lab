#include <iostream>

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    Node(int coefficient, int exponent) {
        this->coefficient = coefficient;
        this->exponent = exponent;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void addTerm(int coefficient, int exponent) {
        Node* newNode = new Node(coefficient, exponent);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void addPolynomials(LinkedList list1, LinkedList list2) {
        Node* current1 = list1.head;
        Node* current2 = list2.head;
        while (current1 != nullptr && current2 != nullptr) {
            if (current1->exponent > current2->exponent) {
                addTerm(current1->coefficient, current1->exponent);
                current1 = current1->next;
            } else if (current1->exponent < current2->exponent) {
                addTerm(current2->coefficient, current2->exponent);
                current2 = current2->next;
            } else {
                int coefficient = current1->coefficient + current2->coefficient;
                addTerm(coefficient, current1->exponent);
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        while (current1 != nullptr) {
            addTerm(current1->coefficient, current1->exponent);
            current1 = current1->next;
        }
        while (current2 != nullptr) {
            addTerm(current2->coefficient, current2->exponent);
            current2 = current2->next;
        }
    }

    void displayPolynomial() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->coefficient << "x^" << current->exponent << " + ";
            current = current->next;
        }
        std::cout << "0" << std::endl;
    }
};

int main() {
    LinkedList list1;
    list1.addTerm(5, 3);
    list1.addTerm(9, 2);
    list1.addTerm(1, 0);

    LinkedList list2;
    list2.addTerm(2, 3);
    list2.addTerm(1, 1);
    list2.addTerm(9, 0);

    LinkedList result;
    result.addPolynomials(list1, list2);

    std::cout << "Polynomial 1: ";
    list1.displayPolynomial();

    std::cout << "Polynomial 2: ";
    list2.displayPolynomial();

    std::cout << "Added polynomial: ";
    result.displayPolynomial();
}
