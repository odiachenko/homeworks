#include <iostream>
#include <cstdlib>

using namespace std;

int const MAX_ANIMALS = 100;
int const MAX_LENGTH = 30;

class Animal {
    private:
        int age;
        char* kind;
        char* name;
        int health;
        int paws;
        bool isShow;

    public:
    Animal() {
        age = 0;
        paws = 0;
        health = 100;
        isShow = true;
    }
    Animal(int age, char* kind, char* name, int paws, int health, bool isShow) {
        this->age = age;
        this->kind = kind;
        this->name = name;
        this->paws = paws;
        this->health = health;
        this->isShow = isShow;
    }

     void showInfo() {
        char* showWord = "YES";
        if (!isShow) {
            showWord = "NO";
        }
        cout << "Animal: " << name;
        cout << " Kind: " << kind << "; Age: " << age << "; Health: " << health << "; Paws: " << paws << "; isShow: " << showWord << endl;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    int getAge() {
        return age;
    }

    void setKind(char* newKind) {
        kind = newKind;
    }

    char* getKind() {
        return kind;
    }

    void setName(char* newName) {
        name = newName;
    }

    char* getName() {
        return name;
    }

    void setPaws(int newPaws) {
        paws = newPaws;
    }

    int getPaws() {
        return paws;
    }

    void setHealth(int newHealth) {
        health = newHealth;
    }

    int getHealth() {
        return health;
    }

    void setIsShow (bool newIsShow) {
        isShow = newIsShow;
    }

    bool getIsShow() {
        return isShow;
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
            animalsList[i] = nullptr;
        }
    };

    void addNewAnimal(Animal* newOne){
        int i = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            if (animalsList[i] == nullptr) {
                animalsList[i] = newOne;
                //cout << "SUCCESS:addNewAnimal " << endl;
                animalsCount++;
                break;
            }
        }
    };

    void deleteAnimal(Animal* myAnimal){
        int i = 0;
        int count = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            if (count >= animalsCount) {
                return;
            }
            if (animalsList[i] == nullptr) {
                continue;
            }

            count++;
            Animal* tmp = animalsList[i];
            if (tmp == myAnimal) {
                animalsList[i] = nullptr;
                delete myAnimal;
                animalsCount--;
                break;
            }
        }
    };

    void deleteAnimal(int myAnimalNumber){
        int i = 0;
        int counter = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            Animal* tmp = animalsList[i];
            if (tmp != nullptr) {
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
            Animal* tmp = animalsList[i];
            if (tmp != nullptr) {
                if (tmp->getIsShow()) {
                    tmp->showInfo();
                }
            }
        }
    };
    void showAboutInfo(int numberOfAnimal) {
        int i = 0;
        int counter = 0;
        for (i = 0; i < MAX_ANIMALS; i++) {
            Animal* tmp = animalsList[i];
            if (tmp != nullptr) {
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
            if (tmp != nullptr) {
                counter++;
                if (counter == numberOfAnimal) {
                    return tmp;
                }
            }
        }
        return tmp;
    };

    void editAnimalInfo(Animal myAnimal) {

    }
};

void InitZooWithAnimals(Zoo *myZoo) {
    Animal* cat = new Animal(2, "cat", "Bars", 4, 100, true);
    Animal* dog = new Animal(5, "dog", "Nick", 4, 90, true);
    Animal* fish = new Animal(1, "fish", "Ariel", 0, 95, false);
    Animal* horse = new Animal(5, "horse", "Test", 4, 100, true);
    myZoo->addNewAnimal(cat);
    myZoo->addNewAnimal(dog);
    myZoo->addNewAnimal(fish);
    myZoo->addNewAnimal(horse);
}

class ZooManager {
    Zoo* myZoo = nullptr;
public:
    ZooManager(Zoo* existZoo) {
        myZoo = existZoo;
    }

    void run() {
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
                    Animal *newAnimal;
                    int age = 0;
                    int health = 100;
                    int paws = 4;
                    bool isShow = true;
                    char* kind = new char[MAX_LENGTH];
                    char* name = new char[MAX_LENGTH];
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
                    newAnimal = new Animal(age, kind, name, paws, health, isShow);
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

                    if (number < 0 || number >= myZoo->animalsCount) {
                        cout << "wrong number" << endl;
                        break;
                    }

                    Animal *editAnimal = myZoo->getAnimalByNumber(number);
                    int age = 0;
                    int health = 100;
                    int paws = 4;
                    bool isShow = true;
                    char* kind = new char[MAX_LENGTH];
                    char* name = new char[MAX_LENGTH];

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
                    editAnimal->setAge(age);
                    editAnimal->setHealth(health);
                    editAnimal->setKind(kind);
                    editAnimal->setName(name);
                    editAnimal->setPaws(paws);
                    editAnimal->setIsShow(isShow);

                    break;
                }
                default: {
                    exit(0);
                    break;
                }
            }
        }
    }
};

int main() {
    Zoo* myZoo = new Zoo();
    InitZooWithAnimals(myZoo);

    ZooManager *manager = new ZooManager(myZoo);
    manager->run();

    return 0;
}
