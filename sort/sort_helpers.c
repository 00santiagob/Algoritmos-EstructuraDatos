#include <stdbool.h>
#include "sort_helpers.h"

void swap(int a[], unsigned int i, unsigned int j) {
    /* 'i' y 'j' son los indices a permutar*/
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

bool goes_before(int x, int y) {
return (x <= y);
}

bool is_sorted(int array[], unsigned int length, bool order) {
    /* Comprueba que se haya ordenado*/
    bool is_sorted = true;
        for (unsigned int i = 1; goes_before(i, length-1) && is_sorted; i++) {
            if (!goes_before(array[i-1], array[i]) && !order) {
                is_sorted = false;
            }
            else if (goes_before(array[i-1], array[i]) && order) {
                is_sorted = false;
            }
            else { continue;}
        }
    return (is_sorted);
}