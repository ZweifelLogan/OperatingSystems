#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool prime(int x) {
    int i = 2;

    while (i*i<=x) { //condition runs loop up to sqrt of x, any factors will be found before/up-to this point
        if (x%i == 0) { //no remainder indicates there exists a factor for x, therefore not prime
            return false;
        }
        i++;
    }
    return true;
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    printf("%i \n", n);
    printf("%i \n", 1);

    //check to see if number is prime, prints if they are
    for (int x=2; x<=n; x++) {
        if (prime(x) == true) {
            printf("%i \n", x);
        }
    }
    return 0;
}