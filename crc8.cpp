#include "crc8.h"


int crc8(int adr, int data) {

    int val = (adr << 8) | data;
    int crc = val << 8;
    int magic = 0x107<<15; // polinom
    int mask = 0x1<<23;    // sign MSB 1

    for (int i = 0; i < 20; i++)
    {
        if((mask & crc) != 0)
        {
            crc = (crc^magic);
        }
        magic = magic >> 1;
        mask = mask >> 1;
        if(magic < 0xFF)
            break;
    }
    return crc;

}
