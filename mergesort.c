#include <stdio.h>

int* mergesort(int* list, int size);
int* merge(int* list1, int* list2, int size1, int size2);


int main(void) {
    int list[] = {10, 8 -9, 0, 4, 6};
    int size = sizeof(list) / sizeof(list[0]);
    int* sortedList = mergesort(list, size);

    for (int i = 0; i < size; ++i) {
        printf("%i ", list[i]);
    }
    printf("\n");

    for (int i = 0; i < size; ++i) {
        printf("%i ", sortedList[i]);
    }
    printf("\n");
}


int* mergesort(int* list, int size) {
    if (size < 2) return list;

    int mid = size / 2;

    int list1[mid];
    int list2[size - mid];

    for (int i = 0; i < mid; ++i) list1[i] = list[i];
    for (int i = 0; i < size - mid; ++i) list2[i] = list[i + mid];

    int* sorted_list1 = mergesort(list1, mid);
    int* sorted_list2 = mergesort(list2, size - mid);

    return merge(list1, list2, mid, size - mid);
}


int* merge(int* list1, int* list2, int size1, int size2) {
    int list[size1 + size2];
    int i = 0;

    int l = 0, r = 0;

    while (l < size1 && r < size2) {
        if (list1[l] < list2[r]) {
            list[i++] = list1[l++];
        }
        else {
            list[i++] = list2[r++];
        }
    }

    while (l < size1) {
        list[i++] = list1[l++];
    }

    while (r < size2) {
        list[i++] = list2[r++];
    }

    return list;
}