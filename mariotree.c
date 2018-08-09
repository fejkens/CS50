#include <stdio.h>
#include <cs50.h>

int main(void) {

int height = 0;

    do {
         height = get_int("Number: ");
    }
    while (height < 0 || height > 23);

    for (int row = 0; row < height; row++) {
        int x = 0;
        while (x < height - row - 1) {
            printf(" ");
            x++;
        }
        x = 0;
        while (x < row + 1) {
            printf("#");
            x++;
        }

        printf("  ");

        x = 0;
        while (x < row + 1) {
            printf("#");
            x++;
        }

        printf("\n");
    }
}