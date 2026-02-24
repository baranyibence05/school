#include <stdio.h>

int main(void) {
    int n1, n2;

    if (scanf("%d %d", &n1, &n2) != 2) {
        return 1;
    }

    if (n1 < n2) {
        printf("%d < %d\n", n1, n2);
    } else if (n1 > n2) {
        printf("%d > %d\n", n1, n2);
    } else {
        printf("%d = %d\n", n1, n2);
    }

    return 0;
}
