#include <stdio.h>

int main() {
    unsigned int num = 1;
    unsigned char *byte = (unsigned char *)&num;

    if (*byte == 1) {
        printf("Your system is little-endian.\n");
    } else {
        printf("Your system is big-endian.\n");
    }

    return 0;
}
