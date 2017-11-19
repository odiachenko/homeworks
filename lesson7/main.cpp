#include <iostream>
#include <string>

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
        cout << "Animal: " << name << endl;
        cout << "Kind: " << kind << "; Age: " << age << "; Health: " << health << "; Paws: " << paws << endl;
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

    void showPopulation(){
        int i = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            if (animalsList[i]) {
                //cout << "SUCCESS:showPopulation " << endl;
                Animal* tmp = animalsList[i];
                if (tmp->isShow) {
                    tmp->showInfo();
                }
            }
        }
    };

    void showAboutInfo(Animal myAnimal){
        myAnimal.showInfo();
    };

    void editAnimalInfo(Animal myAnimal){

    };
};

int main()
{
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

    myZoo->addNewAnimal(cat);
    myZoo->addNewAnimal(dog);
    myZoo->addNewAnimal(fish);
    cout << "Show all: " << endl;
    myZoo->showPopulation();
    cout << "Deleted dog " << endl;
    myZoo->deleteAnimal(dog);
    cout << "Show all: " << endl;
    myZoo->showPopulation();

    Animal* horse = new Animal();
    horse->age = 10;
    horse->health = 100;
    horse->kind = "Horse";
    horse->name = "Nick";
    horse->paws = 4;
    cout << "Added horse " << endl;
    myZoo->addNewAnimal(horse);

    cout << "Show all: " << endl;
    myZoo->showPopulation();

//    cout << "Enter string: " << endl;
//    int z = 0;
//    string k;
//    cin>>k;
//    cout << "Entered value - " << k << endl;

    return 0;
}
