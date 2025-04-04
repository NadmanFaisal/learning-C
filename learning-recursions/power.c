#include <stdio.h>
#include <stdlib.h>

int getPower(int number, int power) {
    if(power == 0) {
        return 1;
    }

    return number * getPower(number, power - 1);
}

int main(int argc, char *argv[]) {
    int a = 2;
    int b = 3;
    int poweredNumber = getPower(a, b);
    printf("Powered number: %d\n", poweredNumber);
    return 0;
}