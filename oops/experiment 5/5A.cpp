#include <iostream>
using namespace std;

class Shape {
public:
    float area;
    void getArea() {
        cout << "Area: " << area << endl;
    }
};

class Circle : public Shape {
public:
    float radius;
    Circle(float r) {
        radius = r;
        area = 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
public:
    float length, width;
    Rectangle(float l, float w) {
        length = l;
        width = w;
        area = length * width;
    }
};

int main() {
    Circle circle(5);
    Rectangle rectangle(4, 6);

    cout << "Circle:" << endl;
    circle.getArea();

    cout << "Rectangle:" << endl;
    rectangle.getArea();

    return 0;
}
