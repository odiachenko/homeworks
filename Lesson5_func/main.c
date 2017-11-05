#include <stdio.h>
#include <stdlib.h>

const int MAX_CHARACTER = 10000;
const int ASCII_SIZE = 256;

void initArray(char myArray[][2]);
void sortArray(char myArray[][2]);
void printArray(char myArray[][2]);

int main()
{
    int size = 256;

    char characterArr[MAX_CHARACTER];
    char insertionsForSort[ASCII_SIZE][2];

    printf("Enter some string!\n");

    fgets(characterArr, MAX_CHARACTER, stdin);

    // Initialization array with ASCII codes
    initArray(insertionsForSort);

    // calculate insertions
    int i = 0;
    int k = 0;
    while (characterArr[i] != '\0') {
        int charCode = characterArr[i];
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

 void initArray(char myArray[][2])
 {
    int k = 0;
    const int asciiStart = -128;
    for (k = 0; k < ASCII_SIZE; k++) {
        myArray[k][0] = asciiStart + k;
        myArray[k][1] = 0;
    }
 }

 void sortArray(char myArray[][2])
 {
    int i = 0;
    int k = 0;
    for (k = 0; k < ASCII_SIZE; k++) {
        for (i = k + 1; i < ASCII_SIZE; i++) {
            if (myArray[k][1] < myArray[i][1]) {
                int tmp[2] = {myArray[k][0], myArray[k][1]};
                myArray[k][0] = myArray[i][0];
                myArray[k][1] = myArray[i][1];
                myArray[i][0] = tmp[0];
                myArray[i][1] = tmp[1];
            }
        }
    }
 }

 void printArray(char myArray[][2])
 {
     int k = 0;
    for (k = 0; k < ASCII_SIZE; k++) {
        if (myArray[k][1] != 0) {
            if (myArray[k][0] == 32) { // check for space
                printf("insertions of space is %d\n", myArray[k][1]);
                continue;
            }
            if (myArray[k][0] == 10) { // check for new line
                printf("insertions of \\n is %d\n", myArray[k][1]);
                continue;
            }
            printf("insertions of %c is %d\n", myArray[k][0], myArray[k][1]);
        }
    }
 }

