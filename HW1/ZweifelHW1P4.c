#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE* input;
    FILE* output;
    int rowsum;
    char line[1024];
    char* temp;
    input = fopen(argv[1], "r+");
    output = fopen(argv[2], "w+");

    while (fgets(line, 1024, input)) {
        rowsum = 0;
        strcpy(temp, line);
        strtok(temp, "\n");
        char * token = strtok(line, ",");
        while (token != NULL) {
            rowsum += atoi(token);
            token = strtok(NULL, ",");
        }
        fprintf(output, "%s,%d\n", temp, rowsum);
    }
    
    fclose(input);
    fclose(output);

}