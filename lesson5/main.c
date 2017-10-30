#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int MAX_CHARACTER = 10000;
    const int ASCII_SIZE = 256;
    char characterArr[MAX_CHARACTER];
    int insertionsForSort[ASCII_SIZE][2];

    printf("Enter some string!\n");

    fgets(characterArr, MAX_CHARACTER, stdin);

    int k = 0;
    const int asciiStart = -128;
    for (k = 0; k < ASCII_SIZE; k++) {
        insertionsForSort[k][0] = asciiStart + k;
        insertionsForSort[k][1] = 0;
    }

    //printf("Entered string: %s", characterArr);
    int i = 0;
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
        for (k = 0; k < ASCII_SIZE; k++) {
            for (i = k + 1; i < ASCII_SIZE; i++) {
                if (insertionsForSort[k][1] < insertionsForSort[i][1]) {
                    int tmp[2] = {insertionsForSort[k][0], insertionsForSort[k][1]};
                    insertionsForSort[k][0] = insertionsForSort[i][0];
                    insertionsForSort[k][1] = insertionsForSort[i][1];
                    insertionsForSort[i][0] = tmp[0];
                    insertionsForSort[i][1] = tmp[1];
                }
            }
        }

        for (k = 0; k < ASCII_SIZE; k++) {
            if (insertionsForSort[k][1] != 0) {
                if (insertionsForSort[k][0] == 32) { // check for space
                    printf("insertions of space is %d\n", insertionsForSort[k][1]);
                    continue;
                }
                if (insertionsForSort[k][0] == 10) { // check for new line
                    printf("insertions of \\n is %d\n", insertionsForSort[k][1]);
                    continue;
                }
                printf("insertions of %c is %d\n", insertionsForSort[k][0], insertionsForSort[k][1]);
            }
        }
    return 0;
}
