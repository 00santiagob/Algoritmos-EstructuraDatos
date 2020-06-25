#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort.h"


static void swap(int a[], unsigned int i, unsigned int j) {
    /* 'i' y 'j' son los indices a permutar*/
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; j++) {
        if (a[j] < a[min_pos]) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}

bool is_sorted(int array[], unsigned int length) {
    /* Comprueba que se haya ordenado*/
    bool is_sorted = true;
        for (unsigned int i = 1; i < (length) && is_sorted; i++) {
            if (array[i-1] > array[i]) {
                is_sorted = false;
            }
        }
    return (is_sorted);
}
