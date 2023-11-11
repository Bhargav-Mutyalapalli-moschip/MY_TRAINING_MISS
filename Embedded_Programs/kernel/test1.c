#include <stdio.h>

unsigned int reverseBits(unsigned int num) {
    unsigned int reverse = 0;
    int i;
    for (i = 0; i < 32; i++) {
        reverse = (reverse << 1) | (num & 1);
        num >>= 1;
    }
    return reverse;
}

int main() {
    unsigned int num = 0xABCD;
    printf("Original number: %x\n", num);
    printf("Reversed number: %x\n", reverseBits(num));
    return 0;
}

