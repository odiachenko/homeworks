#include <stdio.h>
#include <stdlib.h>

const int MAX_CHARACTER = 10000;

void encrypt(char sourceArray[], int key);
void decrypt(char sourceArray[], int key);
void printArray(char sourceArray[]);


int main() {
    char characterArray[MAX_CHARACTER];
    printf("Enter some string!\n");
    fgets(characterArray, MAX_CHARACTER, stdin);

    int key = 0;
    printf("Enter your key!\n");
    scanf("\n%d", &key);

    printf("\nEncrypted string:\n");
    encrypt(characterArray, key);
    printArray(characterArray);

    printf("\nDecrypted string:\n");
    decrypt(characterArray, key);
    printArray(characterArray);

    return 0;
}
void encrypt(char sourceArray[], int key) {
    int k = 0;
    while (sourceArray[k] != '\0') {
        sourceArray[k] = sourceArray[k] + key;
        k++;
    }
}

void decrypt(char sourceArray[], int key) {
    int k = 0;
    while (sourceArray[k] != '\0') {
        sourceArray[k] = sourceArray[k] - key;
        k++;
    }

}
void printArray(char sourceArray[]) {
    int k = 0;
    while (sourceArray[k] != '\0') {
        printf("%c", sourceArray[k]);
        k++;
    }
}
