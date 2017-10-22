#include <stdio.h>
#include <stdlib.h>

int main()
{
    int users[5000]; // password
    int cash[5000]; // balance
    int i = 0;
    int j = 0;
    users[0] = 1111; // admin

    srand(time(NULL));
    //init unic passwords
    for (i = 1; i < 5000; ) {
        int p = rand()% 10000;
        //printf("%d\n", p);
        for (j = 0; j < i; j++) {
            if (users [j] == p) {
                p = 0;
                break;
            }
        }
        if (p != 0){
            users [j] = p;
            i++;
        }
    }

    //init cash
    for (i = 0; i < 5000; i++) {
        cash [i] = rand() % 10000;
    }

    //work with user

    int userID = 10000;
    int k = 0;
    i = 0;
    int userPassword = 0;

    for (;;) {
        if (k == 3) {
            break;
        }
        if (userID == 10000) {
            printf(" Enter password: ");
            scanf("%d", &userPassword);
            for (i = 0; i < 5000; i++ ) {
                if (userPassword == users[i]) {
                    userID = i;
                    break;
                }
            }
        }

        if (userID == 0) //admin
        {
            k = 0;
            printf("make a choice:\n show all balances - 1,\nclear all balances - 2,\nexit - 3\n");
            printf("Your choice: ");
            int command = 0;
            scanf("%d", &command);

            if (command == 1) {
                for (i = 0; i < 5000; i++ ) {
                    printf("user id %d has cash %d\n", i, cash[i]);
                }
            }

            if (command == 2) {
                for (i = 0; i < 5000; i++ ) {
                    cash[i] = 0;
                }
            }

            if (command == 3) {
                userID = 10000;
            }
        }

        if (userID != 10000 && userID != 0) {
            printf("make a choice:\n check balance - 1,\nto put money - 2,\nto get money - 3,\nexit - 4\n");
            printf("Your choice: ");
            int command = 0;
            scanf("%d", &command);

            if (command == 1) {
                printf("You have $%d\n", cash[userID]);
            }

            if (command == 2) {
                printf("Enter the amount to be put to the account\n");
                int putMoney = 0;
                int newBalance = 0;
                scanf("\n%d", &putMoney);
                newBalance = cash[userID] + putMoney;
                cash[userID] = newBalance;
            }

            if (command == 3) {
                printf("Enter the amount to be get to the account\n");
                int getMoney = 0;
                int newBalance = 0;
                scanf("\n%d", &getMoney);
                newBalance = cash[userID] - getMoney;
                cash[userID] = newBalance;

            }
            if (command == 4) {
                userID = 10000;
                k = 0;
            }
        }
        else {
            k++;
        }
   }
    return 0;
}
