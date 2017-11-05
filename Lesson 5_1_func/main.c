#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countWords(char myArray[]);

int main()
{
    const int MAX_CHARACTER = 10000;
    const int ASCII_SIZE = 256;
    char characterArr[MAX_CHARACTER];

    printf("Enter some string!\n");

    fgets(characterArr, MAX_CHARACTER, stdin);

    int count;
    count = countWords(characterArr);

    printf("%d", count);
    return 0;
}

 int countWords(char myArray[])
 {
    int countWords = 0;
    int i = 0;
    bool isWord = false;
    while (myArray[i] != '\0') {
        int charCode = myArray[i];
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
    return countWords;
 }
