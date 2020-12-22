#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Starting..." << endl;

    ifstream input("dictionary.txt");
    ofstream output("doubleDictionary.txt");

    if (!input.is_open()) {
        cout << "Error opening dictionary.txt" << endl;
        return 1;
    }

    string line1;
    while (getline(input, line1)&&line1!="") {
        ifstream inputDouble("dictionary2.txt");
        if (!inputDouble.is_open()) {
            cout << "Error opening dictionary2.txt" << endl;
            return 1;
        }

        string line2;
        while (getline(inputDouble, line2)) {
            output << line1 << line2 << endl;
        }

        inputDouble.close();
    }

    input.close();

    cout << "Creation of doubleDictionary.txt is complete" << endl;

    return 0;
}