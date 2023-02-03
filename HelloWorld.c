#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "HelloWorld.h"

#define ERR -1

int main() {
    /* (seed generator given epoch time.) */
    srand(time(NULL));

    int array[] = {rand()%50, rand()%50, rand()%50, rand()%50, rand()%50};

    size_t n = sizeof(array) / sizeof(*array);

    printf("total size of array: %d\n", n);

    for(int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }

    printf("\n");

    int arrayMaximum = findMax(array, n);

    printf("array maximum: %d\n", arrayMaximum);

    return 0;
}

/* exercise 1.1 - Run the "hello, world" program on your system. Experiment with leaving out parts of the program, to see what error messages you get. */
void helloWorld() {

    printf("hello, world!\n");
}

/* exercise 1.7 - Write a program to print the value of EOF. */
void printEOF() {

    printf("EOF as integer: %d\n", EOF);
}

/* exercise 1.8 - Write a program to count blanks, tabs, and newlines. */
void blanksTabsNewlines(FILE *file) {

    int c, blanks, tabs, nl;

    while((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++nl;
    }

    printf("# of blanks %d, # of tabs %d, # of newlines %d\n", blanks, tabs, nl);
}

/* exercise 1.9 - Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
void contractBlanks(FILE *file) {

    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            putchar(' ');
        else
            putchar(c);
    }
}

/* exercise 1.10 - Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. */

/* exercise 1.11 - How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */

/* exercise 1.12 - Write a program that prints its input one word per line. */
void printWordPerLine(FILE *file) {

    if (file == NULL)
        return;

}

int findMax(int array[], int length) {

    int max = 0;

    if(length < 0)
        return ERR;
    else
        max = array[0];

    for (int i = 1; i < length; i++) {
        if(array[i] > max)
            max = array[i];
    }

    return max;
}
