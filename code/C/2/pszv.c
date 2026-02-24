#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    for (int i = n; i >= 1; --i) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
