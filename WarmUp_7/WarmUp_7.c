#include <stdio.h>
#include <stdlib.h>

int linearSearch(int array[], int target){
    int len = sizeof(array);
    for (int i = 0; i < len; i++){
        if (array[i] == target){
            return i;
        }
    }
    return -1;
}


int main(void){
    int array[5] = {1, 4, 7, 9, 12};
    int target = 9;
    int index = linearSearch(array, target);
    if (index != -1){
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found");
    }
    return 0;
}