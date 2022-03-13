#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    char line[1024]; //max line length of 1024 bytes
    char *args[1024]; //contains the users command, max size of 1024 bytes
    char path[1024]; //holds path of executable
    
    while(1) {
        printf("\n"); //formatting in shell
        printf("INPUT: ");

        //TODO: return to this if statement and determine if necessary
        if (!fgets(line, 1024, stdin)) {
            break;
        }
        if (strcmp(line, "quit\n")==0) { //if quit keyword is entered, exit shell
            break;
        }
    
        printf("\n"); //formatting in shell

        char *token;
        token = strtok(line, " "); //break up input using space as delimiter
        int i = 0;
        while(token != NULL) { //broken up input added to argv array
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL; //for exec funcs to work NULL needs to be last parameter/argument

        //path is set to value in argv[0]
        strcpy(path, args[0]);

        //deletes newline at end of path
        for (i = 0; i < strlen(path); i++) {
            if (path[i] == '\n') {
                path[i] = '\0';
            }
        }


        //TODO: add error handling so if the command doesn't execute properly, the shell can still be exited 
        int child_pid = fork();

        if (child_pid == 0) { //child
            execvp(path, args);
            printf("\n");
        } else { //parent
            wait(NULL);
        }


    }

    return 0;
}