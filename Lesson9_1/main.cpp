#include <iostream>

using namespace std;

const int QUEUE_SIZE = 100;

class Q {
    int q[QUEUE_SIZE];
    int* f;
    int* l;

public:
    Q();
    int get();
    void put(int p);
};

Q::Q(){
    f = q;
    l = q;
}

int Q::get() {
    int d = *f;
    f++;
    return d;
}

void Q::put(int p) {
    *l = p;
    l++;
}

int main()
{
    Q* myQ = new Q();
    myQ->put(10);
    myQ->put(20);
    int k = myQ->get();
    cout << k << endl;

    /*int h = 60;
    int* p;
    p = &h;
    *p = 55;

    cout << h << endl;
    cout << p << endl;
    cout << &h << endl;
    cout << *p << endl;
    cout << &p << endl;*/

    return 0;
}
