#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int const MAX_ANIMALS = 100;

class Animal {
public:
    int age;
    string kind;
    string name;
    int health;
    int paws;
    bool isShow;

    Animal() {
        age = 0;
        health = 100;
        paws = 4;
        isShow = true;
    }

    int pawsNum() {
        return paws;
    }

    void showInfo() {
        string showWord = "YES";
        if (!isShow) {
            showWord = "NO";
        }
        cout << "Animal: " << name;
        cout << " Kind: " << kind << "; Age: " << age << "; Health: " << health << "; Paws: " << paws << "; isShow: " << showWord << endl;
    }
};

class Zoo {

public:
    Animal *animalsList[MAX_ANIMALS];
    int animalsCount;

    Zoo(){
        animalsCount = 0;
        int i;
        for (i = 0; i < MAX_ANIMALS; i++) {
            animalsList[i] = 0;
        }
    };

    void addNewAnimal(Animal* newOne){
        int i = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            if (animalsList[i]) {
                //animalsList[i]->showInfo();
                //cout << "ERROR:addNewAnimal " << endl;
                continue;
            } else {
                animalsList[i] = newOne;
                //cout << "SUCCESS:addNewAnimal " << endl;
                break;
            }
        }
        animalsCount++;
    };

    void deleteAnimal(Animal* myAnimal){
        int i = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            Animal* tmp = animalsList[i];
            if (tmp == myAnimal) {
                animalsList[i] = nullptr;
            }
        }
        animalsCount--;
    };

    void deleteAnimal(int myAnimalNumber){
        int i = 0;
        int counter = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            Animal* tmp = animalsList[i];
            if (tmp) {
                counter++;
                if (counter == myAnimalNumber) {
                    deleteAnimal(tmp);
                }
            }
        }
    };

    void showPopulation(){
        int i = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            if (animalsList[i]) {
                Animal* tmp = animalsList[i];
                //if (tmp->isShow) {
                    tmp->showInfo();
                //}
            }
        }
    };

    void showAboutInfo(int numberOfAnimal) {
        int i = 0;
        int counter = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            Animal* tmp = animalsList[i];
            if (tmp) {
                counter++;
                if (counter == numberOfAnimal) {
                    tmp->showInfo();
                }
            }
        }
    };

    Animal* getAnimalByNumber(int numberOfAnimal) {
        int i = 0;
        int counter = 0;
        Animal* tmp = animalsList[0];
        for (i = 0; i < MAX_ANIMALS; i++) {
            Animal* tmp = animalsList[i];
            if (tmp) {
                counter++;
                if (counter == numberOfAnimal) {
                    return tmp;
                }
            }
        }
        return tmp;
    };



    void editAnimalInfo(Animal myAnimal) {

    };
};

int main() {

    Zoo* myZoo = new Zoo();

    Animal* cat = new Animal();
    cat->age = 3;
    cat->health = 99;
    cat->kind = "Cat";
    cat->name = "Archie";
    cat->paws = 4;
    cat->isShow = false;

    Animal* dog = new Animal();
    dog->age = 17;
    dog->health = 8;
    dog->kind = "Dog";
    dog->name = "Hatiko";
    dog->paws = 4;

    Animal* fish = new Animal();
    fish->age = 1;
    fish->health = 80;
    fish->kind = "Fish";
    fish->name = "Aquarelle";
    fish->paws = 0;

    Animal* horse = new Animal();
    horse->age = 10;
    horse->health = 100;
    horse->kind = "Horse";
    horse->name = "Nick";
    horse->paws = 4;

    myZoo->addNewAnimal(cat);
    myZoo->addNewAnimal(dog);
    myZoo->addNewAnimal(fish);
    myZoo->addNewAnimal(horse);

    for (;;) {
        cout << "Make a choise: " << endl;
        cout << "1 - add new animal;" << endl;
        cout << "2 - delete animal;" << endl;
        cout << "3 - show population;" << endl;
        cout << "4 - show about info;" << endl;
        cout << "5 - edit animal info" << endl;
        cout << "0 - Exit;" << endl;
        int choise = 0;
        cin>>choise;

        switch (choise) {
            case 1: //add new animal
            {
                Animal *newAnimal = new Animal();
                int age = 0;
                int health = 100;
                int paws = 4;
                bool isShow = true;
                string kind = "";
                string name = "";
                cout << "Enter a name: ";
                cin >> name;
                //cout << endl;
                cout << "Enter a kind: ";
                cin >> kind;
                //cout << endl;
                cout << "Enter an age: ";
                cin >> age;
                //cout << endl;
                cout << "Enter a health: ";
                cin >> health;
                //cout << endl;
                cout << "Enter number of paws: ";
                cin >> paws;
                //cout << endl;
                cout << "Is animal needed to show? 0-no; 1-yes ";
                cin >> isShow;
                //cout << endl;
                newAnimal->age = age;
                newAnimal->health = health;
                newAnimal->kind = kind;
                newAnimal->name = name;
                newAnimal->paws = paws;
                newAnimal->isShow = isShow;

                myZoo->addNewAnimal(newAnimal);

                break;
            }
            case 2: //delete animal
            {
                cout << "There are " << myZoo->animalsCount << " animals in the ZOO" << endl;
                int number = 0;
                cout << "Enter a number to delete :";
                cin >> number;

                if (number < 1 || number > myZoo->animalsCount) {
                    cout << "wrong number" << endl;
                    break;
                }

                myZoo->deleteAnimal(number);

                break;
            }
            case 3://show population
            {
                myZoo->showPopulation();
                break;
            }
            case 4://show about info
            {
                cout << "There are " << myZoo->animalsCount << " animals in the ZOO" << endl;
                int number = 0;
                cout << "Enter a number to show info :";
                cin >> number;

                if (number < 1 || number > myZoo->animalsCount) {
                    cout << "wrong number" << endl;
                    break;
                }

                myZoo->showAboutInfo(number);

                break;
            }
            case 5://edit animal info
            {
                cout << "There are " << myZoo->animalsCount << " animals in the ZOO" << endl;
                int number = 0;
                cout << "Enter a number to edit info :";
                cin >> number;

                if (number < 1 || number > myZoo->animalsCount) {
                    cout << "wrong number" << endl;
                    break;
                }

                Animal *editAnimal = myZoo->getAnimalByNumber(number);
                int age = 0;
                int health = 100;
                int paws = 4;
                bool isShow = true;
                string kind = "";
                string name = "";

                cout << "Enter new name: ";
                cin >> name;
                //cout << endl;
                cout << "Enter new kind: ";
                cin >> kind;
                //cout << endl;
                cout << "Enter new age: ";
                cin >> age;
                //cout << endl;
                cout << "Enter new health: ";
                cin >> health;
                //cout << endl;
                cout << "Enter new number of paws: ";
                cin >> paws;
                //cout << endl;
                cout << "Is animal needed to show? 0-no; 1-yes ";
                cin >> isShow;
                //cout << endl;
                editAnimal->age = age;
                editAnimal->health = health;
                editAnimal->kind = kind;
                editAnimal->name = name;
                editAnimal->paws = paws;
                editAnimal->isShow = isShow;

                break;
            }
            default: {
                exit(0);
                break;
            }
        }
    }

    return 0;
}
