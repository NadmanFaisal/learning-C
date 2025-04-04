#include <stdio.h>
#include <stdlib.h>

int getFactorial(int number) {
    if(number == 1) {
        return 1;
    }

    return number * getFactorial(number - 1);
}

int main(int argc, char *argv[]) {
    
    int factorial = getFactorial(5);
    printf("Factorial: %d\n", factorial);
    return 0;
}