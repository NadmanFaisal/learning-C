#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *string, int firstIndex, int lastIndex) {
    if(firstIndex >= lastIndex) {
        return;
    }

    char temp = string[firstIndex];
    string[firstIndex] = string[lastIndex];
    string[lastIndex] = temp;

    reverseString(string, firstIndex + 1, lastIndex - 1);
}

int main(int argc, char *argv[]) {
    char string[] = "Nadman";
    int length = strlen(string);
    reverseString(string, 0, length - 1);
    printf("Reversed string: %s\n", string);
    return 0;
}