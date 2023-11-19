#include <iostream>

using namespace std;

template<class T> class vector {
    T* v; // Type T vector
    int size;
public:
    vector(int m) {
        v = new T[size = m];
        for (int i = 0; i < size; i++)
            v[i] = 0;
    }

    vector(T* a, int m) {
        v = new T[size = m];
        for (int i = 0; i < size; i++)
            v[i] = a[i];
    }

    void modifyElement(int index, T value) {
        if (index >= 0 && index < size)
            v[index] = value;
        else
            cout << "Index out of bounds." << endl;
    }

    void display() {
        cout << "Vector elements: ";
        for (int i = 0; i < size; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    ~vector() {
        delete[] v;
    }
};

int main() {
    vector<int> intVector(5);
    intVector.display();

    int intArray[] = {1, 2, 3, 4, 5};
    vector<int> intVectorFromArray(intArray, 5);
    intVectorFromArray.display();

    intVectorFromArray.modifyElement(2, 10);
    intVectorFromArray.display();

    vector<double> doubleVector(3);
    doubleVector.display();

    double doubleArray[] = {1.1, 2.2, 3.3};
    vector<double> doubleVectorFromArray(doubleArray, 3);
    doubleVectorFromArray.display();

    doubleVectorFromArray.modifyElement(1, 5.5);
    doubleVectorFromArray.display();

    return 0;
}
