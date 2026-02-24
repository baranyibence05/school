#include <stdio.h>

int main(void) {
    int sum = 0;

    for (int i = 1; i <= 100; ++i) {
        sum += i;
    }

    printf("1-től 100-ig terjedő egész számok összege: %d\n", sum);
    return 0;
}
