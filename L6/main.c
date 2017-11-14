#include <stdio.h>
#include <stdlib.h>

const int MAX_CHARACTER = 10000;

int getData(char characterArray[]);
void encrypt(char sourceArray[], int key);
void decrypt(char sourceArray[], int key);
void printArray(char sourceArray[]);


int main() {
    char characterArray[MAX_CHARACTER];
    int key = 0;
    int k;
    for (;;) {
        if (k == 3) {
           break;
        }
    const int ENCRYPTED_STRING = 1;
    const int DECRYPTED_STRING = 2;
    const int EXIT = 3;
    int command = 0;

    printf("make a choice:\n Encrypted string - 1,\nDecrypted string - 2,\nExit - 3\n");
    printf("Your choice: ");
    scanf("%d", &command);

    if (command == ENCRYPTED_STRING) {
        key = getData(characterArray);
        printf("\nEncrypted string:\n");
        encrypt(characterArray, key);
        printArray(characterArray);
        continue;
    }

    if (command == DECRYPTED_STRING) {
        key = getData(characterArray);
        printf("\nDecrypted string:\n");
        decrypt(characterArray, key);
        printArray(characterArray);
        continue;
    }
    if (command == EXIT) {
        return 0;
    }
    }

    return 0;
}

int getData(char characterArray[]){
    int key = 0;

    fflush (stdin);
    printf("Enter some string!\n");
    fgets(characterArray, MAX_CHARACTER, stdin);

    printf("Enter your key!\n");
    scanf("\n%d", &key);

    return key;
}

void encrypt(char sourceArray[], int key) {
    int k = 0;
    while (sourceArray[k] != '\0') {
        sourceArray[k] = sourceArray[k] + ((key + 26) % 26);
        if (sourceArray[k] > 'z' ) {
            sourceArray[k] -= 26;
        }
        k++;
    }
}

void decrypt(char sourceArray[], int key) {
    int k = 0;
    while (sourceArray[k] != '\0') {
        sourceArray[k] = sourceArray[k] - ((key + 26) % 26);
        if (sourceArray[k] < 'a' ) {
            sourceArray[k] += 26;
        }
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
