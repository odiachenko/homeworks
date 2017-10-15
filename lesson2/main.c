#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number:\n");
    int rows = 0;

    scanf("%d", &rows);
    printf("you entered %d\n", rows);
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;
    int m = 0;
    // Вывести треугольник;
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // Вывести перевернутый треугольник;
    for (i = rows; i > 0; i--) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // Нарисовать елочку;
    for ( i = 0; i < rows; i++) {
        for (k = 0; k < (rows - i); k++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        for (z = 1; z < j; z++){
                    printf("*");
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++) {
        printf(" ");
    }
    printf("*");

    return 0;
}
