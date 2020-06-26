/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

double getMilliseconds() {
    return 1000.0 * clock() / CLOCKS_PER_SEC;
}

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("\n"
           "Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    result = argv[argc - 1];
    return (result);
}

int main(int argc, char *argv[]) {
    double elapsed;
    double elapsed_aux;
    /* parse the filepath given in command line arguments */
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    /* create a copy of the array, to do some checks later */
    int copy[MAX_SIZE];

    bool order_b = false; // false: ascending order and true: descending order
    int order_i = 0; // 0 = false and 1 = true
    while (order_i < 2) {
        /* an order is given to start */
        array_copy(copy, array, length);
        /* start to calculate the time */
        elapsed = getMilliseconds();
        printf("\n###### SELECTION SORT ######\n");
        /* do the actual sorting */
        selection_sort(copy, length, order_b);
        /* the time elapsed is calculated */
        elapsed_aux = elapsed;
        elapsed = getMilliseconds();
        elapsed =  elapsed - elapsed_aux;
        printf("Elapsed milliseconds = %g\n", elapsed);
        /* show the ordered array in the screen */
        array_dump(copy, length);
        /* check if it is sorted */
        assert(is_sorted(copy, length, order_b));
        /* check if it is a permutation of original */
        if (array_is_permutation_of(copy,array,length)) {
            printf("Your new array is a permutation of the original \n");
        }
        else {
            printf("Your new array is not a permutation of the original \n");
        }
        order_i += 1;
        order_b = !order_b;
    }
    order_b = false; // false: ascending order and true: descending order
    order_i = 0; // 0 = false and 1 = true
    while (order_i < 2) {
        /* an order is given to start */
        array_copy(copy, array, length);
        /* start to calculate the time */
        elapsed = getMilliseconds();
        printf("\n###### INSERTION SORT ######\n");
        /* do the actual sorting */
        insertion_sort(copy, length, order_b);
        /* the time elapsed is calculated */
        elapsed_aux = elapsed;
        elapsed = getMilliseconds();
        elapsed =  elapsed - elapsed_aux;
        printf("Elapsed milliseconds = %g\n", elapsed);
        /* show the ordered array in the screen */
        array_dump(copy, length);
        /* check if it is sorted */
        assert(is_sorted(copy, length, order_b));
        /* check if it is a permutation of original */
        if (array_is_permutation_of(copy,array,length)) {
            printf("Your new array is a permutation of the original \n");
        }
        else {
            printf("Your new array is not a permutation of the original \n");
        }
        order_i += 1;
        order_b = !order_b;
    }
    return (EXIT_SUCCESS);
}
