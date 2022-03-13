#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>
#include <string.h>

uint8_t gencrc(uint8_t *data, size_t len)
{
    uint8_t crc = 0xff;
    size_t i, j;
    for (i = 0; i < len; i++) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if ((crc & 0x80) != 0)
                crc = (uint8_t)((crc << 1) ^ 0x31);
            else
                crc <<= 1;
        }
    }
    return crc;
}

int main(int argc, char *argv[]) {
    
    
    int child_pid;
    int wait_result;
    int status;
    int temp = 0;

    for (int i = 1; i < argc; i++) {
        if ((child_pid = fork()) == 0) {
            printf("%s=%i\n", argv[i], gencrc((uint8_t *)argv[i], sizeof((uint8_t *)argv[i]))); 
        } else {
            wait(NULL);
        }
    }
    
    return 0;
}
