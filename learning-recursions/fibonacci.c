#include <stdio.h>
#include <stdlib.h>

int getFibonacci(int number) {
    if(number == 0) {
        return 0;
    } else if(number == 1) {
        return 1;
    }

    return getFibonacci(number - 1) + getFibonacci(number - 2);
}

int main(int argc, char *argvp[]) {
    int fibo = getFibonacci(10);
    printf("Fibo: %d\n", fibo);
}