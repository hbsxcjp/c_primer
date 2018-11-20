#include <stdio.h>

void print_file(char * filename) {
    int ch;
    FILE * fp;
    fp = fopen(filename, "r");
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
    }
}

int main (void) {
    print_file("ch13.c");
    
}