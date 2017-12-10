#include <iostream>

using namespace std;

const int S_SIZE = 100;

class S {
    int s[S_SIZE];
    int* f;
    int* l;

public:
    S();
    int get();
    void put(int p);
};

S::S(){
    f = s;
    l = s;
}

int S::get() {
    //cout << *l << endl;
    //l--;
    //cout << *l << endl;
    int d = *f;
    f--;
    return d;
}

void S::put(int p) {
    *l = p;
    cout << *l << endl;
    l++;
    cout << *l << endl;
    *f = p;
}

int main()
{
    S* myS = new S();
    myS->put(10);
    myS->put(20);
    myS->put(30);
    int k = myS->get();

    cout << k << endl;

    return 0;
}
