#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

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

static void insert(int a[], unsigned int i, bool order) {
    int j = i;
    if (!order) {
        while (goes_before(1, j) && !goes_before(a[j-1], a[j])) {
            swap(a, j-1, j);
            j -= 1;
        }
    }
    else {
        while (goes_before(1, j) && goes_before(a[j-1], a[j])) {
            swap(a, j-1, j);
            j -= 1;
        }
    }
}

void insertion_sort(int a[], unsigned int length, bool order) {
    for (unsigned int i = 1; goes_before(i, length-1); i++) {
        assert(is_sorted(a, i-1, order));
        insert(a, i, order);
    }
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der, bool order) {
    int pivot;
    if (der > izq) {
    pivot = partition(a, izq, der, order);
    quick_sort_rec(a, izq, (pivot == 0) ? 0 : pivot - 1, order);
    quick_sort_rec(a, pivot+1, der, order);
    }
}

void quick_sort(int a[], unsigned int length, bool order) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, order);
}

static void next_permutation(unsigned int perm[], unsigned int length) {
    unsigned int i, j;
    /*
        taken (and modified) from
        https://www.nayuki.io/page/next-lexicographical-permutation-algorithm 
    */
    // Find non-increasing suffix
    i = length - 1;
    while (i > 0 && goes_before(perm[i], perm[i-1])) {
        i--;
    }
    // Find successor to pivot
    j = length - 1;
    while (goes_before(perm[j], perm[i-1])) {
        j--;
    }
    swap_ui(perm, i-1, j);
    // Reverse suffix
    j = length - 1;
    while (i < j) {
        swap_ui(perm, i, j);
        i++;
        j--;
    }
}

static void mk_fst_permutation(unsigned int perm[], unsigned int length) {
/* makes the first permutation 0 1 2 ... length-1 */
    unsigned int i = 0;
    while (i < length) {
        perm[i] = i;
        i = i + 1;
    }
}

static bool sorted(int a[], unsigned int perm[], unsigned int length, bool order) {
/*
    returns true if the array a would be sorted following the order indicated by perm
    (the ordering relation is determined by the abstract function goes_before)
*/
    bool res = true;
    unsigned int i = 0;
    while (((length == 0) ? 0 : length-1) && i<length-1 && res) {
        if(!order) {
            res = goes_before(a[perm[i]],a[perm[i+1]]) && res;
            i = i+1;
        }
        else {
            res = goes_before(a[perm[i+1]],a[perm[i]]) && res;
            i = i+1;
        }
    }
    return res;
}

static void update(int a[], unsigned int perm[], unsigned int length) {
/* resets a according to the order indicated in perm */
    int copy[length];
    array_copy(copy,a,length);
    unsigned int i = 0;
    while (i < length) {
        a[i] = copy[perm[i]];
        i = i + 1;
    }
}

void permutation_sort(int a[], unsigned int length, bool order) {
/* tries systematically with all te possible permutations until a sorted one is found */
    unsigned int perm[length];
    mk_fst_permutation(perm, length);
    while (!sorted(a, perm, length, order)) {
        next_permutation(perm, length);
    }
    update(a, perm, length);
}

bool is_sorted(int array[], unsigned int length, bool order) {
    /* Check that it has been ordered */
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
