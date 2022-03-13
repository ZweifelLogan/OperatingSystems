#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


void main() {
  int main ()
{
    pid_t father = getpid();
    int syncpipe[4];
    pipe(syncpipe);
    pipe(syncpipe + 2);

    fork();
    fork();
    exit();

    close(syncpipe[3]);
    if (getpid() == father) {
        // wait for all children to spawn
        read(syncpipe[2], &i, 1);
        char mypid[16];
        sprintf(mypid, "%d", father);
        char * args[] = {"pstree", "-p", mypid, NULL};
        execvp(*args, args);
    } else {
        close(syncpipe[1]);
        read(syncpipe[0], &i, 1);
        // father will close all open file descriptors on exit
        // then this will return with EOF
    }

    return 0;
}
}
//int main(int argc, char *argv[]) {
//    return 0;
//}