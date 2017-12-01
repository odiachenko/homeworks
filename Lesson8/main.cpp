#include <iostream>

using namespace std;

class ArrayList {
private:
    const int INIT_SIZE = 10;
    int currentSize;
    int allocatedSize;
    int* array;
public:
    ArrayList();
    ~ArrayList();
    void add(int n);
    void add(int n, int index);
    int get(int index);
    void remove(int index);
    void print();
};

ArrayList::ArrayList() {
    currentSize = 0;
    allocatedSize = INIT_SIZE;
    array = new int[INIT_SIZE];
}

ArrayList::~ArrayList() {
    delete[] array;
}

void ArrayList::print() {
    for (int i = 0; i < currentSize; i++){
        cout << array[i] << endl;
    }
}

void ArrayList::add(int n) {
    if (currentSize < allocatedSize){
        array[currentSize] = n;
        cout << "Added to index: " << currentSize << endl;
        currentSize++;
        return;
    } else {
        int* newArray = new int[allocatedSize * 2];
        allocatedSize *= 2;
        cout << "Allocated new array with size: " << allocatedSize << endl;
        int i = 0;
        for (i = 0; i < currentSize; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        array[currentSize] = n;
        currentSize++;
    }
}

void ArrayList::add(int n, int index) {
    if (index < 0 || index >= currentSize) {
        cout << "Wrong index!" << endl;
        return;
    }
    array[index] = n;
}

int ArrayList::get(int index) {
    if (index < 0 || index >= currentSize) {
        cout << "Wrong index!" << endl;
        return -1; //error value
    }
    return array[index];
}

void ArrayList::remove(int index) {
    if (index < 0 || index >= currentSize) {
        cout << "Wrong index!" << endl;
        return; //error value
    }
    int i = 0;
    for (i = index; i < currentSize; i++) {
        if (i == currentSize - 1) {
            break;
        }
        array[i] = array[i+1];
    }
    currentSize--;
}

int main()
{
    ArrayList *list = new ArrayList();

    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    list->add(6);
    list->add(7);
    list->add(8);
    list->add(9);
    list->add(10);
    list->print();
    list->remove(9);
    list->print();
    list->add(10);
    list->print();
    cout << "Element on index 3 is " << list->get(3) << endl;
    return 0;
}
