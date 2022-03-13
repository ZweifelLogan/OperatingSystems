#include <stdio.h>
#include <stdlib.h>

int fib(int x) {
    if (x<=1) {
        return x;
    }
    return fib(x-1) + fib(x-2);
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);

    for (int i=0; i<=n; i++){
        printf("%i \n", fib(i));
    }
    //printf("%i \n", n);
    return 0;
}