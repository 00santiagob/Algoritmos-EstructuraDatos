#include <stdbool.h>
#include "sort_helpers.h"

void swap(int a[], unsigned int i, unsigned int j) {
    /* 'i' y 'j' son los indices a permutar*/
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void swap_ui(unsigned int a[], unsigned int i, unsigned int j) {
    /* 'i' y 'j' son los indices a permutar*/
    unsigned int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

bool goes_before(int x, int y) {
return (x <= y);
}

unsigned int partition(int a[], unsigned int izq, unsigned int der, bool order) {
    int piv = izq;
    int i = izq + 1;
    int j = der;
    while(i <= j) {
        if(!order) {
            if(goes_before(a[i], a[piv])) {
                i += 1;
            }
            else if(!goes_before(a[j], a[piv])) {
                j -= 1;
            }
            else {
                swap(a, i, j);
                i += 1;
                j -= 1;
            }
        }
        else {
            if(!goes_before(a[i], a[piv])){
                i += 1;
            }
            else if(goes_before(a[j], a[piv])) {
                j -= 1;
            }
            else {
                swap(a, i, j);
                i += 1;
                j -= 1;
            }
        }
    }
    swap(a, piv, j);
    piv = j;
    return(piv);
}
