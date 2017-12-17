#include <iostream>
#include <math.h>

using namespace std;

class Number {
public:
    int i; // const
    int N; // users number
    int sum;

Number(){
    i = 1;
    N = 0;
    sum = 0;
}

void showNumber() {
    cout << "Enter a number: ";
    cin >> N;
    if (N < 1 || N > pow(10, 4)) {
        cout << "wrong number!" << endl;
        return;
    }
    int j = 0;
    int sum = 0;
    for (j = i; j <= N; j++) {
        sum = i + sum;
        i++;
    }
     cout << sum << endl;
}
};

int main(){

    Number* myNumber = new Number();
    myNumber->showNumber();

    return 0;
}
