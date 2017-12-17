#include <iostream>
#include <stdio.h>

using namespace std;

const int FILE_LENGTH = 50;

class FileManager {
public:
    char* fileName = "example.txt";
    FILE* pFile;
    //int array[5] = {1,2,3,4,5};

FileManager() {
    pFile = fopen(fileName, "w+");
}

~FileManager() {
    fclose(pFile);
}

void writeFile (char* text) {
    if (pFile == NULL) {
        cout << "Error writing to file" << endl;
        return;
    }
    fputs(text, pFile);
}

void deleteFile () {
    if (pFile == NULL) {
        cout << "Error deleting file" << endl;
        return;
    }
    fclose(pFile);
    pFile = fopen(fileName, "w+");
}

char* readFile() {
    if (pFile == NULL) {
        cout << "Error reading from file" << endl;
        return NULL;
    }
    rewind(pFile);
    char buf[FILE_LENGTH];
    if (fgets(buf, FILE_LENGTH, pFile) != NULL) {
        return buf;
    }
    return NULL;
}

};

int main()
{
    FileManager* myManager = new FileManager();
    myManager->writeFile("Test string");
    char* myText = myManager->readFile();
    //puts(myText);
    cout << myText << endl;

    myManager->writeFile("ALA");
    myText = myManager->readFile();
    //puts(myText);
    cout << myText << endl;

    myManager->deleteFile();

    myText = myManager->readFile();
    //puts(myText);
    cout << myText << endl;

    delete myManager;

    return 0;
}
