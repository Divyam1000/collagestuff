#include <iostream>
#include <fstream>

using namespace std;

void insertElementsToFile(const string& filename, int numElements) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    for (int i = 0; i < numElements; i++) {
        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        file << element << " ";
    }

    file.close();
}

void mergeAndSortFiles(const string& file1, const string& file2, const string& outputFile) {
    ifstream input1(file1);
    ifstream input2(file2);
    ofstream output(outputFile);

    int element1, element2;
    int temp1, temp2; // Temporary variables to store elements

    if (input1 >> element1 && input2 >> element2) {
        temp1 = element1;
        temp2 = element2;
    }
    while (!input1.eof() && !input2.eof()) {
        if (temp1 < temp2) {
            output << temp1 << " ";
            if (input1 >> temp1) continue; // Read next element from input1
        } else {
            output << temp2 << " ";
            if (input2 >> temp2) continue; // Read next element from input2
        }
    }

    while (input1 >> element1) {
        output << element1 << " ";
    }

    while (input2 >> element2) {
        output << element2 << " ";
    }

    input1.close();
    input2.close();
    output.close();
}

int main() {
    insertElementsToFile("file1.txt", 5);
    insertElementsToFile("file2.txt", 3);

    mergeAndSortFiles("file1.txt", "file2.txt", "output.txt");

    cout << "Merged and sorted elements written to output.txt" << endl;

    return 0;
}
