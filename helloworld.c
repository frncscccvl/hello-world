#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ERR -1

/* chapter one - function prototypes (alphabetical order) */
void blanksTabsNewlines(FILE *loremipsum);
void celsiusToFahrenheitTable();
void contractBlanks(FILE *loremipsum);
void helloWorld();
void printEOF();
void printEscapes();
void printWordPerLine(FILE *loremipsum);
void reverseTemperatureTable();
void swap(int *a, int *b);
void temperatureTableWithHeader();
void textFileStatistics(FILE *loremipsum);
void verifyGetChar(FILE *loremipsum);
void visibleEscapes(FILE *loremipsum);

int main(void) {
    /* number randomizer seed */
    srand((unsigned int)time(NULL));

    FILE *loremipsum = fopen("loremipsum.txt", "r");

    if (loremipsum == NULL) {
        printf("text file does not exist.\n");
        return 1;
    }

    fclose(loremipsum);

    return 0;
}

/* exercise 1.1 - Run the "hello, world" program on your system. Experiment with leaving out parts of the program, to see what error messages you get. */
void helloWorld() {
    printf("hello, world!\n");
}

/* exercise 1.2 - Experiment to find out what happens when printf’s argument string contains \c, where c is some character not listed above. */
void printEscapes() {
    /* basically experiment with different escape characters */
    printf("contents: \\\n");
}

/* exercise 1.3 - Modify the temperature conversion program to print a heading above the table. */
void temperatureTableWithHeader() {
    /* a given temperature converter program via C programming guide */
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;

    /* injected print statement */
    printf("fahrenheit to celsius temperature converter\n\nfahrenheit\tcelsius\n");

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t\t%6.1f\n", fahr, celsius);

        fahr += step;
    }
}

/* exercise 1.4 - Write a program to print the corresponding Celsius to Fahrenheit table. */
void celsiusToFahrenheitTable() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;

    printf("celsius to fahrenheit temperature converter\n\ncelsius\t\tfahrenheit\n");

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%6.1f\t\t%3.0f\n", celsius, fahr);

        fahr += step;
    }
}

/* exercise 1.5 - Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0. */
void reverseTemperatureTable() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 300;
    upper = 0;
    step = 20;
    fahr = lower;

    printf("celsius to fahrenheit temperature converter\n\ncelsius\t\tfahrenheit\n");

    while(fahr >= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%6.1f\t\t%3.0f\n", celsius, fahr);

        fahr -= step;
    }
}

/* exercise 1.6 - Verify that the expression, (getchar() != EOF) is 0 or 1. */
void verifyGetChar(FILE *loremipsum) {
    printf("Enter a character\n");

    int c = getchar();

    if(c != EOF)
        printf("\ncharacter != EOF = 1\n");
    else
        printf("\ncharacter == EOF = 0\n");

    printf("\nCharacter entered: %c\n", c);
}

/* exercise 1.7 - Write a program to print the value of EOF. */
void printEOF() {
    printf("EOF is equivalent to %d.\n", EOF);
}

/* exercise 1.8 - Write a program to count blanks, tabs, and newlines. */
void blanksTabsNewlines(FILE *loremipsum) {
    int blanks = 0, tabs = 0, nl = 0, ch;
    char buffer[100000];

    for(int i = 0; (i < (sizeof(buffer)-1) && ((ch = fgetc(loremipsum)) != EOF)); i++) {
        if(ch == ' ')
            ++blanks;
        else if(ch == '\t')
            ++tabs;
        else if(ch == '\n')
            ++nl;
    }

    printf("# of blanks: %d\n# of tabs: %d\n# of new lines: %d\n", blanks, tabs, nl);
}

/* exercise 1.9 - Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
void contractBlanks(FILE *loremipsum) {
    char buffer[1000000];
    int i, ch;

    for(i = 0; (i < (sizeof(buffer)-1) && ((ch = fgetc(loremipsum)) != EOF)); i++) {
        buffer[i] = ch;

        if(buffer[i] == ' ' && buffer[i-1] == ' ')
            buffer[i] = '\b';
    }

    buffer[i] = '\0';

    printf("contents:\n\n%s\n", buffer);
}

/* exercise 1.10 - Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. */
void visibleEscapes(FILE *loremipsum) {
    char buffer[1000000];
    int ch, j;

    for(j = 0; (j < (sizeof(buffer)-1) && ((ch = fgetc(loremipsum)) != EOF)); j++) {
        buffer[j] = ch;

        if(ch == '\t')
            printf("\\t");
        else if(ch == '\b')
            printf("\b");
        else if(ch == '\\')
            printf("\\\\");
        else
            printf("%c", ch);
    }

    buffer[j] = '\0';

    printf("\ncharacter count: %d\n", j-1);
}

/* exercise 1.11 - How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */

/* exercise 1.12 - Write a program that prints its input one word per line. */
void printWordPerLine(FILE *loremipsum) {
    char buffer[1000000];
    int j, ch;

    for(j = 0; (j < (sizeof(buffer)-1) && ((ch = fgetc(loremipsum)) != EOF)); j++) {
        if(ch == ' ')
            buffer[j] = '\n';
        else if(ch == '.' || ch == ',' || ch == '\t')
            buffer[j] = ' ';
        else if(ch == '\n')
            buffer[j] = '\b';
        else
            buffer[j] = tolower(ch);
    }

    buffer[j] = '\0';

    printf("\ncontents:\n\n%s\n", buffer);
}

/* exercise 1.13 - Write a program to print a histogram of the lengths of words in its input. */

/* exercise 1.14 - Write a program to print a histogram of the frequencies of different characters in its input. */

/* exercise 1.15 - Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */

/* exercise 1.16 - Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input line, and as much as possible of the text. */

/* exercise 1.17 - Write a program to print all input lines that are longer than 80 characters. */

/* exercise 1.18 - Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */

/* exercise 1.19 - Write a function (reverse(s)) that reverses the character string s. */

/* exercise 1.20 - Write a program (detab) that replaces tabs in the input with the proper number of blanks to space to the next tab stop. */

/* exercise 1.21 - Write a program (entab) that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. */

/* exercise 1.22 - Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. */

/* exercise 1.23 - Write a program to remove all comments from a C program. */

/* exercise 1.24 - Write a program to check a C program for rudimentary syntax errors like unbalanced parenthesis, brackets and braces. */

/* utility swap function */
void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void textFileStatistics(FILE *loremipsum) {
    char buffer[100000];
    int words = 0, ch = 0, j = 0, paragraphs = 0, sentences = 0;

    for(j = 0; (j < (sizeof(buffer)-1) && ((ch = fgetc(loremipsum)) != EOF)); j++) {
        buffer[j] = ch;

        if(buffer[j] == '\n' && buffer[j-1] == '\n')
            continue;

        if(buffer[j] == '.')
            ++sentences;

        if(buffer[j] == '\n' && buffer[j-1] == '.')
            ++paragraphs;

        if(ch == ' ' || ch == '\n' || ch == '\t')
            ++words;
    }

    buffer[j] = '\0';

    printf("\nfile contents:\n\n%s\n\nfile word count: %d\n\nparagraphs: %d\n\ncharacter count: %d\n\nsentences: %d\n", buffer, words, paragraphs, j-1, sentences);
}
