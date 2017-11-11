#include <stdio.h>
#include <stdlib.h>

const int MAX_CHARACTER = 10000;
const int MAX_KEY_LENGTH = 5;


void encrypt(char sourceArray[], char keyArray[], int keyLength);
void decrypt(char sourceArray[], char keyArray[], int keyLength);
void printArray(char sourceArray[]);


int main() {
    char characterArray[MAX_CHARACTER];
    char keyArray[MAX_KEY_LENGTH];

    printf("Enter some string!\n");
    fgets(characterArray, MAX_CHARACTER, stdin);

    int keyLength = 0;
    printf("Enter your key string!\n");
    fgets(keyArray, MAX_KEY_LENGTH, stdin);
    while (keyArray[keyLength] != '\0') {
        keyLength++;
    }

    printf("\nEncrypted string:\n");
    encrypt(characterArray, keyArray, keyLength);
    printArray(characterArray);

    printf("\nDecrypted string:\n");
    decrypt(characterArray, keyArray, keyLength);
    printArray(characterArray);

    return 0;
}
void encrypt(char sourceArray[], char keyArray[], int keyLength) {
    int k = 0;
    while (sourceArray[k] != '\0') {
        int keyIndex = (k+1) %keyLength;
        sourceArray[k] = sourceArray[k] + keyArray[keyIndex];
        k++;
    }
}

void decrypt(char sourceArray[], char keyArray[], int keyLength) {
    int k = 0;
    while (sourceArray[k] != '\0') {
        int keyIndex = (k+1) %keyLength;
        sourceArray[k] = sourceArray[k] - keyArray[keyIndex];
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
