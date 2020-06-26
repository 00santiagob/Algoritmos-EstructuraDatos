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

static bool goes_before(int x, int y) {
return (x<=y);
}

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; goes_before(j, length-1); j++) {
        if (goes_before(a[j], a[min_pos])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

static unsigned int max_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int max_pos = i;
    for (unsigned int j = i + 1; goes_before(j, length-1); j++) {
        if (!goes_before(a[j], a[max_pos])) {
            max_pos = j;
        }
    }
    return (max_pos);
}

void selection_sort(int a[], unsigned int length, bool order) {
    for (unsigned int i = 0; goes_before(i, length-1); i++) {
        if (!order) {
            unsigned int min_pos = min_pos_from(a, i, length);
            swap(a, i, min_pos);
        }
        else {
            unsigned int max_pos = max_pos_from(a, i, length);
            swap(a, i, max_pos);
        }
    }
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
