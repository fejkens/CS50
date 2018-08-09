#include <stdio.h>
#include <cs50.h>

int main(void) {

long long cc_number;
int doubled = 0;
int othersum = 0;

    // Card number prompt

    do {
         cc_number = get_long("Credit card number: ");
    } while (cc_number <= 0);

    // Double and add all numbers starting from second to last from the right

    long long m = 10;

    for (int i = 0; i < 8; i++) {

        int x = (cc_number / m) % 10;
        m *= 100;

        // If the result is a two digit number, we need to add the digits together

        if ((x * 2) / 10 > 0) {
            x = x * 2;
            int counter = 0;

            int k = x;

            do {
                k = k / 10;
                counter++;
            }   while(k != 0);

            for (int j = 0; j < counter; j++) {
                int p = x % 10;
                x = x / 10;
                doubled = doubled + p;
            }

            // Otherwise just add the doubled number

        } else {
            doubled = doubled + 2 * x;
        }
    }

    // Sum every other number

    m = 1;

    for (int i = 0; i < 8; i++) {

        int x = (cc_number / m) % 10;
        m *= 100;
        othersum = othersum + x;
    }

    // Add the sums and see if the last digit is 0

    int sumcheck = doubled + othersum;

    if (sumcheck % 10 == 0) {

        // Count the number of digits

        int counter = 0;
        long long r = cc_number;

        while(r != 0) {
            r = r / 10;
            counter++;
        }

        // First two will be equal to counter - 2

        int firsttwo = counter - 2;
        double x = 1;

        // Raise 10 to the power of (number of digits - 2)

        for (int i = 0; i < firsttwo; i++) {
            x *= 10;
        }

        // Test for number of digits

        int y = cc_number / x;

        if (counter == 15) {
            switch (y) {
                case 34:
                case 37:
                    printf("Your credit card company: American Express\n");
                    break;
                default:
                    printf("Card number invalid\n");
            }
        } else if (counter == 16) {
            if (cc_number / x > 50) {
                switch (y) {
                    case 51:
                    case 52:
                    case 53:
                    case 54:
                    case 55:
                        printf("Your credit card company: MasterCard\n");
                        break;
                    default:
                        printf("Card number invalid\n");
                }
            } else {
                switch (y / 10) {
                    case 4:
                        printf("Your credit card company: Visa\n");
                        break;
                    default:
                        printf("Card number invalid\n");
                }
            }
        } else if (counter == 13) {
            switch (y / 10) {
                case 4:
                    printf("Your credit card company: Visa\n");
                    break;
                default:
                    printf("Card number invalid\n");
            }
            //Visa
        } else {
            printf("Card number invalid\n");
        }
    } else {
        printf("Card number invalid\n");
    }
    }