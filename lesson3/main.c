#include <stdio.h>
#include <stdlib.h>

int main()
{
    int searchedNum = 0;
    int usersNum = 0;
    int selector = 0;

    for (;;){
        srand(time(Null));
        searchedNum = rand()% 10;


        for (int i = 0; i < 3; i++){
                printf("%d-try")
                for (;;){
                    printf(" Enter positive value: ");
                    scanf("%d", &usersNum);
                  if (usersNum < 0);{
                    printf(" Hey! It's negative num!\n");
                    continue;
                  }
                }

        }

        break;
    }

    if (usersNum == searchedNum){
        printf("\nYahoo! RIGHT!");

        break;
    }
    if (usersNum < searchedNum){
        printf("Bigger!");
    }


    if (usersNum > searchedNum){
        printf("Lower");
    }
   printf("\nCont or exit? 1\0")
   scanf("%d", &selector);

   if (selector == 0){
    retorn 0;
   }
}

