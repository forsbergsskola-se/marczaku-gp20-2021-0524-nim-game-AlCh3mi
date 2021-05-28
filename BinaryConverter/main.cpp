#include <iostream>
#include <limits>

using namespace std; //why is this bad practice in c++?

int UserInput();
string AsBinaryModulo(int);
string AsBinaryOperations(int);

const uint32_t maxValue = numeric_limits<uint32_t>::max();

int main() {
    cout << "Binary Converter!" << endl;

    int input = UserInput();
    cout << AsBinaryModulo(input) << endl;
    cout << AsBinaryOperations(input) << endl;
    return 0;
}

int UserInput() {
    UserInput:
    cout << "Enter a number to see it represented as Binary: ";
    int input;
    cin >> input;
    if(cin.fail()){
        cout << "invalid input!" << endl;
        cin.clear();
        cin.ignore(maxValue,'\n' );
        goto UserInput; //I had to try it at least once XD
    }
    return input;
}

string AsBinaryOperations(int value){
    cout << "0b";
    for (int i = 31; i >= 0 ; i--) {
        int numberToConvert = value >> i;
        if (numberToConvert & 1) cout << "1";
        else cout << "0";
    }
}

string AsBinaryModulo(int value){

    if(value == 0) return "0b0";

    int enumerator = 0;
    int binary[32];
    string response = "0b";

    for (int i = 0; value > 0; i++)
    {
        binary[i] = value % 2;
        value /= 2;
        enumerator++;
    }

    for (int i = enumerator-1;i >= 0;i--)
        response += to_string(binary[i]);

    return response;
}
