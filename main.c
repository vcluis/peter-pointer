#include <stdio.h>
#include <stdlib.h>

void changeValue(int *ptr);
int *getDynamicInt();
int *getDynamicIntArray(int size);
int **get2DDynamicArray(int m, int n);

// utilities
void initialize2DArray(int **arr, int m, int n);
void print2DArray(int **arr, int m, int n);

int main() {
    int value = 0;
    int *ptr = &value;

    // Prints *ptr stored value
    printf("pointer address: %p\n", ptr);
    // Prints value, using *ptr
    printf("pointer address -> value: %d\n", *ptr);

    changeValue(&value);
    printf("Updated value (function): %d\n", value);
    // same as before but getting the &value address stored in *ptr
    changeValue(ptr);
    printf("Updated value (function): %d\n", value);

    // Dynamic memory allocation
    int *integer = getDynamicInt();
    printf("Dynamic allocated *ptr->value: %d\n", *integer);
    free(integer);

    // Dynamic array
    int size = 5;
    int *integers = getDynamicIntArray(size);
    int index = 0;
    while(index < size) {
        printf("integers[%d]: %d\n", index, integers[index]);
        index += 1;
    }
    free(integers);

    // Double pointer
    int **dptr = &ptr;
    printf("**dptr: %p\n", dptr); // Prints *ptr memory address
    printf("**dptr value: %p\n", *dptr); // Prints *ptr value

    **dptr = 21;
    printf("Updated int value: %d\n", value);

    int arr[5] = {0, 1, 2, 3, 4};
    int *arrPtr = arr;
    for(int i = 0; i < 5; i++) {
        printf("Array (plain): %d\n", *arrPtr);
        *arrPtr = *arrPtr + 1;
    }

    int m = 2, n = 2;
    int **multiArray = get2DDynamicArray(m, n);
    initialize2DArray(multiArray, m, n);
    print2DArray(multiArray, m, n);

    return 0;
}

void changeValue(int *ptr) {
    *ptr = *ptr + 5;
}

int *getDynamicInt() {
    int *dynamicInt = malloc(sizeof(int));
    *dynamicInt = 5;
    return dynamicInt;
}

int *getDynamicIntArray(int size) {
    int *dynamicIntArray = calloc(size, sizeof(int));
    return dynamicIntArray;
}

int **get2DDynamicArray(int m, int n) {
    int **dynamicArray = malloc(sizeof(int *) * m);
    for(int i = 0; i < m; i++)
        dynamicArray[i] = malloc(sizeof(int) * n);
    return dynamicArray;
}

// Utilities
void initialize2DArray(int **arr, int m, int n){
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = i + j;
}

void print2DArray(int **arr, int m, int n){
    printf("\n2D array values: \n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            printf("arr[%d][%d]: %d\n", i, j, arr[i][j]);
}
