#include "search.h"

static unsigned int linear_search(int a[], unsigned int length, int x) {
    unsigned int pos = -1;
    for (unsigned int i=0; i<length; i++) {
        if (a[i] == x) {
            pos = i;
            break;
        }
    }
    return(pos);
}

static unsigned int binary_search(int a[], unsigned int length, int x) {
    unsigned int pos = -1;
    unsigned int izq = 1;
    unsigned int der = length - 1;
    unsigned int med;
    while (izq <= der && pos == -1) {
        med = (izq + der) / 2;
        if (x < a[med]) {
            der = med - 1;
        }
        else if (x == a[med]) {
            pos = med;
        }
        else {
            izq = med + 1;
        }
    }
    return(pos);
}

static unsigned int binary_search_rec(int a[], int x, unsigned int izq,
                             unsigned int der) {
    unsigned int pos;
    unsigned int med;
    if (izq > der) {
        pos = -1;
    }
    else {
        med = (izq + der) / 2;
        if (x < a[med]) {
            pos = binary_search_rec(a, x, izq, med-1);
        }
        else if (x == a[med]) {
            pos = med;
        }
        else {
            pos = binary_search_rec(a, x, med+1, der);
        }
    }
    return(pos);
}
