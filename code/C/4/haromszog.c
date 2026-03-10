#include <stdio.h>
#include <stdbool.h>

bool valid_triangle(double a, double b, double c);

bool valid_triangle(double a, double b, double c) {
    return (a > 0 && b > 0 && c > 0) &&
           (a + b > c) &&
           (a + c > b) &&
           (b + c > a);
}

int main() {
    double side1, side2, side3;
    
    printf("Adja meg a háromszög három oldalát:\n");
    printf("Első oldal: ");
    scanf("%lf", &side1);
    printf("Második oldal: ");
    scanf("%lf", &side2);
    printf("Harmadik oldal: ");
    scanf("%lf", &side3);
    
    if (valid_triangle(side1, side2, side3)) {
        printf("Szerkeszthető háromszög.\n");
    } else {
        printf("Nem szerkeszthető háromszög.\n");
    }
    
    return 0;
}