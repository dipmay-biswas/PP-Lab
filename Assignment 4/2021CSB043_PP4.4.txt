#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double area() = 0;
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    double area() {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double area() {
        return M_PI * pow(radius, 2);
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }
    double area() {
        return 0.5 * base * height;
    }
};

class ShapeStack {
private:
    vector<Shape*> stack;
public:
    void push(Shape* shape) {
        stack.push_back(shape);
    }

    Shape* pop() {
        Shape* shape = stack.back();
        stack.pop_back();
        return shape;
    }

    void display() {
        for (int i = 0; i < stack.size(); i++) {
            cout << "Shape " << i+1 << ": Area = " << stack[i]->area() << endl;
        }
    }

    double totalAreaCovered() {
        double totalArea = 0;
        for (int i = 0; i < stack.size(); i++) {
            totalArea += stack[i]->area();
        }
        return totalArea;
    }
};

int main() {

    int W, H, R, B, Ht;	

    ShapeStack shapeStack;

    cout << "Enter the width and height of the rectangle respectively: ";
    cin >> W >> H;
    shapeStack.push(new Rectangle(W, H));

    cout << "Enter the radius of the circle: ";
    cin >> R;
    shapeStack.push(new Circle(R));

    cout << "Enter the base and height of the triangle respectively: ";
    cin >> B >> Ht;
    shapeStack.push(new Triangle(B, Ht));

    shapeStack.display();
    cout << "The total area covered by the shapes is: " << shapeStack.totalAreaCovered() << endl;

    delete shapeStack.pop();
    delete shapeStack.pop();
    delete shapeStack.pop();

    return 0;
}