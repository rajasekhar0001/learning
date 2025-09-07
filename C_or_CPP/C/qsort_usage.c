#include<stdlib.h>
#include <stdio.h>

int sortAscending(const void* a, const void * b) {
    return *(int*)a > *(int*)b;
}

int sortDescending(const void* a, const void* b) {
    return *(int*)a < *(int*)b;
}

void print(int arr[], int sz) {
    for(int i=0;i<sz;i++) {
        printf("%d ", arr[i]);
    } printf("\n"); 
}

int main() {
    int arr[] = {4, 1, 5, 3, 2};
    printf("Sorted order in Ascending: ");
    qsort(arr, 5, sizeof(arr[0]), sortAscending);
    print(arr, 5);
    printf("Sorted order in Descending: ");
    qsort(arr, 5, sizeof(arr[0]), sortDescending);
    print(arr, 5);
    
}