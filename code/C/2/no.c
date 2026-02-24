#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    for (int i = 4; i <= n; i += 4) {
        printf("%d\n", i);
    }

    return 0;
}
