#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number:\n");
    int rows;

    scanf("%d", &rows);
    printf("you entered %d\n", rows);
    //tree1(rows);
    //tree2(rows);
    tree3(rows);
    return 0;
}

void tree1(int rows)
{
    int i;
    int j;
    for ( i = 0; i < rows; i++) {
        for ( j = 0; j <= i; j++) {
                printf("*");
        }
        printf("\n");}
}

void tree2(int rows)
{
    int i;
    int j;
    for ( i = rows; i > 0; i--) {
        for ( j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");}
}

void tree3(int rows)

{
    int i;
    int j;
    int k;
    int z;
    int m;
    for ( i = 0; i < rows; i++) {
            for (k = 0; k < (rows - i); k++){
            printf (" ");}

                for ( j = 0; j <= i; j++) {
                printf ("*");}

                    for (z = 1; z < j; z++){
                    printf ("*");}

             printf("\n");}
                        for ( i = 0; i < rows; i++) {
                        printf (" ");}

                        printf ("*");
}




