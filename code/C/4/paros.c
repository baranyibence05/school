#include <stdio.h>

int is_even(int n) {
    return n % 2 == 0;
}

int is_odd(int n) {
    return n % 2 != 0;
}

int main() {
    int num;
    
    printf("Szám: ");
    scanf("%d", &num);
    
    printf("Páros: %d\n", is_even(num));
    printf("Páratlan: %d\n", is_odd(num));
    
    return 0;
}