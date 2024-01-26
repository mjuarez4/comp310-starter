#include <stdio.h>
#include <stdlib.h>

int main(void){
    char filename[] = "example.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("No file found");
        return 1;
    } else {
        fprintf(fp, "Hello, World!");
        fclose(fp);
    }
    return 0;

}

