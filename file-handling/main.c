#include <stdlib.h>
#include <stdio.h>
// -----typedefs -------
typedef struct {
char firstname[20];
char famname[20];
char pers_number[13]; // yyyymmddnnnc
} PERSON;

PERSON input_record(void);
void write_new_file(PERSON *inrecord);
void printfile(void);
void search_by_firstname(char *name);
void append_file(PERSON *inrecord);

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void printConsole() {
    printf("1 Create a new and delete the old file.\n2 Add a new person to the file.\n3 Search for a person in the file.\n4 Print out all in the file.\n5 Exit the program.");
    printf("\n");
}

int main(void){
    PERSON ppost;

    // FILE *file;
    // file = fopen("nadman", "w");
    // fprintf(file, "Zahid is a chigga\n");

    // printf("Write name: ");
    // scanf("%s", ppost.firstname);
    // clearBuffer();
    
    // printf("Write fam name: ");
    // scanf("%s", ppost.famname);
    // clearBuffer();

    // printf("Write personnummer: ");
    // scanf("%s", ppost.pers_number);
    // clearBuffer();

    // file = fopen("nadman", "a");
    // fprintf(file, "name: %s, famname: %s, personnummer: %s\n", ppost.firstname, ppost.famname, ppost.pers_number);
    // fclose(file);

    int userInput;
    while(userInput != 5) {
        printConsole();
        scanf("%d", &userInput);
        clearBuffer();

        switch(userInput) {
            case 1:
                write_new_file(&ppost);
                break;
            case 2:
                append_file(&ppost);
                break;
            case 3:
                search_by_firstname(&ppost);
                break;
            case 4:
                printfile();
                break;
            default:
                break;

        }
    }
    return(0);
}

void write_new_file(PERSON *inrecord) {
    FILE *file;
    file = fopen("nadman", "wb");
    fprintf(file, "Zahid is a chigga\n");
}