/*
// My full C++ code
#include <iostream>
#include <string>
using namespace std;

double CelsiusToF(double c);
double FahrenheitToC(double f);


int main() {
    double tempf;
    double tempc;
    string input;
    bool correctinput = false;
    string again;
    do {
        cout << "Do you want to convert F to C or C to F?\n";
        getline(cin, input);
        if (input == "F to C"){
            correctinput = true;
            cout << "What is the temperature in F?\n";
            cin >> tempf;
            double result = FahrenheitToC(tempf);
            tempc = result;
            cout << "The temperature in C is: " << tempc << "\n";
        }
        else if (input == "C to F") {
            correctinput = true;
            cout << "What is the temperature in C?\n";
            cin >> tempc;
            double result  = CelsiusToF(tempc);
            tempf = result;
            cout << "The temperature in F is: " << tempf << "\n";
        }
        else {
            cout << "enter input as: \n1. F to C\n2.C to F\n";
            correctinput = false;
        }
        cout << "Do you want to convert again? (yes/no): ";
        cin >> again;
        cin.ignore(); // cleaning the newline from the buffer -_-
    } while (again == "yes");
    return 0;
}

double CelsiusToF(double c) {
    return (9.0/5.0) * c + 32;
}

double FahrenheitToC(double f) {
    return (5.0/9.0) * (f - 32);
}
*/

/* pure WebAssembly + JavaScript */
#include <emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    double CelsiusToF(double c) {
        return (9.0 / 5.0) * c + 32;
    }

    EMSCRIPTEN_KEEPALIVE
    double FahrenheitToC(double f) {
        return (5.0 / 9.0) * (f - 32);
    }
}


// Run using these:
/*
* emcc converter.cpp -o converter.js -s EXPORTED_FUNCTIONS='["_CelsiusToF","_FahrenheitToC"]' -s MODULARIZE=1 -s 'EXPORT_NAME="createModule"'
* python3 -m http.server --bind 127.0.0.1
*/

/* Hybrid option:
    #include <iostream>
#include <string>
#include <emscripten.h>
using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    double CelsiusToF(double c) {
        return (9.0 / 5.0) * c + 32;
    }

    EMSCRIPTEN_KEEPALIVE
    double FahrenheitToC(double f) {
        return (5.0 / 9.0) * (f - 32);
    }
}

int main() {
    double tempf;
    double tempc;
    string input;
    string again;
    do {
        cout << "Do you want to convert F to C or C to F?\n";
        getline(cin, input);
        if (input == "F to C") {
            cout << "What is the temperature in F?\n";
            cin >> tempf;
            cin.ignore();
            cout << "The temperature in C is: " << FahrenheitToC(tempf) << "\n";
        } else if (input == "C to F") {
            cout << "What is the temperature in C?\n";
            cin >> tempc;
            cin.ignore();
            cout << "The temperature in F is: " << CelsiusToF(tempc) << "\n";
        } else {
            cout << "Please enter input as:\nF to C\nor\nC to F\n";
        }
        cout << "Do you want to convert again? (yes/no): ";
        getline(cin, again);
    } while (again == "yes");
    return 0;
}
*/