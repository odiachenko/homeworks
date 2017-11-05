#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    const int MAX_CHARACTER = 10000;
    const int ASCII_SIZE = 256;
    char characterArr[MAX_CHARACTER];

    printf("Enter some string!\n");

    fgets(characterArr, MAX_CHARACTER, stdin);

    int i = 0;
    bool isWord;
    isWord = false;
    int countWords = 0;
    while (characterArr[i] != '\0') {
        int charCode = characterArr[i];
        if ((charCode >= 65 && charCode <= 90) || (charCode >= 97 && charCode <= 122)) { // A-Z or a-z
            isWord = true;
        }
        else {
            if (isWord == true) {
                countWords++;
            }
            isWord = false;
        }
        i++;
    }
    printf("%d", countWords);
    return 0;
}
