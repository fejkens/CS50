#include <stdio.h>
#include <cs50.h>

int main(void) {

    int counter = 0;

    double change = get_double("Change: ");

    counter = 0;

    while (change >= 0.25) {
        change -= 0.25;
        counter++;
    }
    while (change >= 0.10) {
        change -= 0.10;
        counter++;
    }
    while (change >= 0.05) {
        change -= 0.05;
        counter++;
    }
    while (change > 0) {
        change -= 0.01;
        counter++;
    }
    printf("%i\n", counter);
}