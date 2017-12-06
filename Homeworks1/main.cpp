#include <iostream>
#include <math.h>
using namespace std;

int const ARRAY_SIZE = 100;

class Number {
public:
    int number; // user number
    int k; // notation
    int result[ARRAY_SIZE];
    int sum;
    int mult;

Number() {
    number = 0;
    k = 0;
    sum = 0;
    mult = 1;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = -1;
    }
}

void showNumber() {
    cout << "Enter a number: ";
    cin >> number;
    if (number < 1 || number > pow(10, 9)) {
        cout << "wrong number!" << endl;
        return;
    }

    cout << "Enter a calc: ";
    cin >> k;
    if (k < 2 || k > 10) {
        cout << "wrong number!" << endl;
        return;
    }
    int remainder = 0;
    int fraction = 0;
    int i = 0;

    fraction = number;
    while (fraction > k) {
        remainder = fraction % k;
        //cout << "remainder " << remainder << endl;
        fraction = fraction / k;
        //cout << "fraction " << fraction << endl;
        result[i] = remainder;
        i++;
    }
    result[i] = fraction;

    i = 0;
    while (result[i] != -1) {
        //cout << result[i] << " ";
        i++;
    }
    for (i = i - 1; i >= 0; i--) {
       cout << result[i];
    }
    cout << endl;

    i = 0;
    while (result[i] != -1) {
        sum = sum + result[i];
        i++;
    }
    cout << "Summa: " << sum << endl;

    i = 0;
    while (result[i] != -1) {
        mult = mult * result[i];
        i++;
    }
    cout << "Mult: " << mult << endl;
    cout << "Mult - summa = " << mult - sum << endl;
}

};


int main() {
    Number* myNumber = new Number();
    myNumber->showNumber();
    delete myNumber;

    return 0;
}
