#include<iostream>
#include <cmath>
using namespace std;

#define PI 3.14

class Shape {
public:
    virtual float area() = 0;

    virtual float perimeter() = 0;
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}

    float area(){
        return PI * radius * radius;
    }

    float perimeter(){
        return 2 * PI * radius;
    }
};

class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float area() {
        return length * width;
    }

    float perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Shape *ptr;
    Circle circle(5);
    Rectangle rectangle(4, 6);
    ptr = &circle;
    cout << "Circle Area: " << ptr->area() << ", Perimeter: " << ptr->perimeter() << endl;
    ptr = &rectangle;
    cout << "Rectangle Area: " << ptr->area() << ", Perimeter: " << ptr->perimeter() << endl;

    return 0;
}
