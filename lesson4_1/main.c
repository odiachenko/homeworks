#include <stdio.h>
#include <stdlib.h>

int main()
{
    const ARRAY_SIZE = 5000;
    const NOT_EXIST = 10000;
    int ADMIN_ID = 0;
    int PIN_ADMIN = 1111;
    int usersPinArr[ARRAY_SIZE]; // users password
    int usersCashArr[ARRAY_SIZE]; // users balance
    int userPassword = 0;
    int unicPassword = 0;
    int userID = NOT_EXIST;
    int command = 0;
    int putMoney = 0;
    int getMoney = 0;
    int newBalance = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    srand(time(NULL));
    //init unic passwords
    for (i = 1; i < ARRAY_SIZE; ) {
        int unicPassword = rand()% 8999+1000;
        //printf("%d\n", p);
        for (j = 0; j < i; j++) {
            if (usersPinArr[j] == unicPassword) {
                unicPassword = 0;
                break;
            }
        }
        if (unicPassword != 0){
            usersPinArr[j] = unicPassword;
            i++;
        }
    }

    //init cash
    for (i = 0; i < ARRAY_SIZE; i++) {
        usersCashArr[i] = rand() % 10000;
    }

    //work with user
    for (;;) {
        if (k == 3) {
            break;
        }
        if (userID == NOT_EXIST) {
            printf(" Enter password: ");
            scanf("%d", &userPassword);
            for (i = 0; i < ARRAY_SIZE; i++ ) {
                if (userPassword == usersPinArr[i]) {
                userID = i;
                break;
                }
            }
        }
        if (userID == ADMIN_ID) { //admin
            k = 0;
            printf("make a choice:\n show all balances - 1,\nclear all balances - 2,\nexit - 3\n");;
            printf("Your choice: ");
            scanf("%d", &command);

            if (command == 1) {
                for (i = 0; i < ARRAY_SIZE; i++ ) {
                    printf("user id %d has cash %d\n", i, usersCashArr[i]);
                }
            }
            if (command == 2) {
                for (i = 0; i < ARRAY_SIZE; i++ ) {
                    usersCashArr[i] = 0;
                }
            }
            if (command == 3) {
                userID = NOT_EXIST;
                k = -1;
                }
            }

        if (userID != NOT_EXIST && userID != ADMIN_ID ) {
            printf("make a choice:\n check balance - 1,\nto put money - 2,\nto get money - 3,\nexit - 4\n");
            printf("Your choice: ");
            int command = 0;
            scanf("%d", &command);

            if (command == 1) {
                printf("You have $%d\n", usersCashArr[userID]);
            }
            if (command == 2) {
                printf("Enter the amount to be put to the account\n");
                scanf("\n%d", &putMoney);
                newBalance = usersCashArr[userID] + putMoney;
                usersCashArr[userID] = newBalance;
            }

            if (command == 3) {
                printf("Enter the amount to be get to the account\n");
                scanf("\n%d", &getMoney);
                newBalance = usersCashArr[userID] - getMoney;
                usersCashArr[userID] = newBalance;

            }
            if (command == 4) {
                userID = NOT_EXIST;
                k = 0;
            }
        }
        else {
            k++;
        }
   }
    return 0;
}

