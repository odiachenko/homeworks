
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int searchedNum = 0;
    int usersNum = 0;
    char selector;
    int i = 0;

    for (;;) {
        srand(time(NULL));
        searchedNum = rand()% 10;
        i = 0;

        for (;;){
            if (i == 3) {
                break;
            }
            printf(" Enter positive value: ");
            if (!scanf("%d", &usersNum)) {
                printf(" Hey! It's not num!\n");
                cleanBuffer();
                continue;
            }

            if (usersNum < 0){
                printf(" Hey! It's negative num!\n");
                continue;
            }
            i++;
            printf("%d-try\n", i);

            if (usersNum == searchedNum){
                printf("\nYahoo! RIGHT!");
                //break;
                return 0;
            }
            if (usersNum < searchedNum){
                printf("Bigger!\n");
            }
            if (usersNum > searchedNum){
                printf("Lower!\n");
            }
        }

        printf("\nContinue or exit? yes or no\n");
        scanf("\n%c", &selector);
        cleanBuffer();

        if (selector == 'n'){
            return 0;
        }
    }
    return 0;
}

void cleanBuffer(){
    while (getchar()!='\n');
}
