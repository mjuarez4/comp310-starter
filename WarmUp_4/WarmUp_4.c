#include <stdio.h>
#include <stdlib.h>

int main(void){
    char s[] = "Hello";
    int size = sizeof(s) - 1;
    char temp;
    for (int i = 0; i<size/2; i++){
        temp = s[i];
        s[i] = s[size - 1 - i];
        s[size - 1 - i] = temp;
    }
    printf("final string: %s\n", s);
    return 0;
}
