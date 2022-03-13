#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>


//TODO: throws error for uint_8 but changing to u_int_8 fixes stuff
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
    printf("%i\n", gencrc(argv[1], sizeof(argv[1])));
    //uint8_t temp;
    //temp = gencrc(argv[1], sizeof(argv[1]));
    //printf("%i\n", temp);
    return 0;
}
