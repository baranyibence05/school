#include <stdio.h>

int main(void) {
    int x;
    int pos = 0, neg = 0;

    while (scanf("%d", &x) == 1 && x != 0) {
        if (x > 0) {
            pos++;
        } else if (x < 0) {
            neg++;
        }
    }

    printf("Pozitív számok: %d\n", pos);
    printf("Negatív számok: %d\n", neg);
    return 0;
}