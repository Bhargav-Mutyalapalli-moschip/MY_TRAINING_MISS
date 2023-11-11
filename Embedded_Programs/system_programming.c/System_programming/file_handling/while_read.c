#include <stdio.h>
#include <stdlib.h>

#define SIZE 200

int main() {

    FILE *input = fopen("sample.txt", "r");
    char buffer[1];
    int counter = 0;

    if (input == NULL) {
        printf("Error! Could not open file\n"); 
        exit(-1);
    }

    while (fscanf(input, "%s\n", buffer) != EOF) {
        counter++;
    }

    fclose(input);
    printf("%d\n", counter);
    return 0;
}

