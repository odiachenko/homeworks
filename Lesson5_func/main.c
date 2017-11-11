#include <stdio.h>
#include <stdlib.h>

const int MAX_CHARACTER = 10000;
const int ASCII_SIZE = 256;

void initArray(char sourceArray[][2]);
void sortArray(char sourceArray[][2]);
void printArray(char sourceArray[][2]);

int main() {
    char characterArray[MAX_CHARACTER];
    char insertionsForSort[ASCII_SIZE][2];

    printf("Enter some string!\n");

    fgets(characterArray, MAX_CHARACTER, stdin);

    // Initialization array with ASCII codes
    initArray(insertionsForSort);

    // calculate insertions
    int i = 0;
    int k = 0;
    while (characterArray[i] != '\0') {
        int charCode = characterArray[i];
        for (k = 0; k < ASCII_SIZE; k++) {
            if (insertionsForSort[k][0] == charCode) {
                insertionsForSort[k][1]++;
            }
        }
        i++;
    }

    //Sort insertions
    sortArray(insertionsForSort);

    // Print result
    printArray(insertionsForSort);

    return 0;
}

 void initArray(char sourceArray[][2]) {
    int k = 0;
    const int asciiStart = -128;
    for (k = 0; k < ASCII_SIZE; k++) {
        sourceArray[k][0] = asciiStart + k;
        sourceArray[k][1] = 0;
    }
 }

 void sortArray(char sourceArray[][2]) {
    int i = 0;
    int k = 0;
    for (k = 0; k < ASCII_SIZE; k++) {
        for (i = k + 1; i < ASCII_SIZE; i++) {
            if (sourceArray[k][1] < sourceArray[i][1]) {
                int tmp[2] = {sourceArray[k][0], sourceArray[k][1]};
                sourceArray[k][0] = sourceArray[i][0];
                sourceArray[k][1] = sourceArray[i][1];
                sourceArray[i][0] = tmp[0];
                sourceArray[i][1] = tmp[1];
            }
        }
    }
 }

 void printArray(char sourceArray[][2]) {
    int k = 0;
    for (k = 0; k < ASCII_SIZE; k++) {
        int charCode = sourceArray[k][0];
        if ((charCode >= 65 && charCode <= 90) || (charCode >= 97 && charCode <= 122)) {
            if (sourceArray[k][1] != 0) {
                /*if (sourceArray[k][0] == 32) { // check for space
                    printf("insertions of space is %d\n", sourceArray[k][1]);
                    continue;
                }
                if (sourceArray[k][0] == 10) { // check for new line
                    printf("insertions of \\n is %d\n", sourceArray[k][1]);
                    continue;
                }*/
                printf("insertions of %c is %d\n", sourceArray[k][0], sourceArray[k][1]);
            }
        }
    }
 }
