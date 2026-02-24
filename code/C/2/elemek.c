#include <stdio.h>

int main(void) {
    int x;
    long sum = 0;

    while (scanf("%d", &x) == 1 && x != 0) {
        sum += x;
    }

    printf("Összeg: %ld\n", sum);
    return 0;
}
