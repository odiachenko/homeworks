#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* listEnd;
    Node* listStart;

    int listSize;

    LinkedList() {
        listStart = nullptr;
        listEnd = nullptr;
        listSize = 0;
    }

    void add(Node* n) {
        if (listStart == nullptr) {
            listStart = n;
            listEnd = n;
            listSize++;
        }
        else {
            listEnd->next = n;
            n->prev = listEnd;
            listEnd = n;
            listSize++;
        }
    }

    void show() {
        Node* n = listStart;
        if (listStart == nullptr) {
            cout << "empty list!" << endl;
            return;
        }
        do {
            cout << n->data << "; " << endl;
            n = n->next;
        } while (n != nullptr);
    }

    void add(Node* n, int index) {
        if (index < 1 || index > listSize) {
            cout << "wrong index!" << endl;
            return;
        }
        int i = 1;
        Node *x = listStart;
        while (i < index) {
            x = x->next;
            i++;
        }
        x->prev->next = n;
        n->prev = x->prev;
        n->next = x;
        x->prev = n;
        listSize++;
    }

    void remove(int index) {
        if (index < 1 || index > listSize) {
            cout << "wrong index!" << endl;
            return;
        }
        int i = 1;
        Node *x = listStart;
        while (i < index) {
            x = x->next;
            i++;
        }
        x->prev->next = x->next;
        x->next->prev = x->prev;
        listSize--;
        delete x;
    }

    Node* get(int index) {
        if (index < 1 || index > listSize) {
            cout << "wrong index!" << endl;
            return NULL;
        }
        int i = 1;
        Node *x = listStart;
        while (i < index) {
            x = x->next;
            i++;
        }
        return x;
    }
};

int main()
{
    LinkedList *myList = new LinkedList();
    Node *first = new Node();
    first->data = 100;
    Node *sec = new Node();
    sec->data = 102;
    Node *thrd = new Node();
    thrd->data = 103;
    Node *aaa = new Node();
    aaa->data = 999;

    myList->add(first);
    myList->add(sec);
    myList->add(thrd);
    myList->show();

    myList->add(aaa, 2);
    myList->remove(3);
    myList->show();

    Node *test = myList->get(2);
    test->data = 1000;
    myList->show();


    return 0;
}
