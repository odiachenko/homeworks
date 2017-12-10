#include <iostream>
#include <cstring>

using namespace std;

const int ARRAY_SIZE = 100;

class Map {
public:
    char array[ARRAY_SIZE];
    int hashMap(char* str); // "vasya" -> 5;
    int get(char* str);
    void put(char* str, int data);
};

void Map::put(char* str, int data) {
    array[hashMap(str)] = data;
}

int Map::hashMap(char* str) {
    int i = 0;
    int h = 0;
    for(i = 0; i < strlen(str); i++ ) {
        h += str[i];
    }
    return h;
}

int Map::get(char* str) {
    return array[hashMap(str)];
}

int main() {

    Map* myMap = new Map();
    myMap->put("Vasya", 24);
    myMap->put("Ivan", 30);
    int k = myMap->get("Vasya");
    cout << k << endl;

    return 0;
}
