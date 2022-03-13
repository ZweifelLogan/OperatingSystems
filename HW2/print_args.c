#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i;
    
    //for if every argument should be on a newline
    for (i=1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    
    
    //for if every argument should be one the same line then declare a new line
    /*for (i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");*/
}