#include <stdio.h>
#include <math.h>

double kerulet(double radius) {
    return 2 * M_PI * radius;
}

double terulet(double radius) {
    return M_PI * radius * radius;
}

int main() {
    double r;
    
    printf("Adja meg a kör sugarát: ");
    scanf("%lf", &r);
    
    printf("Kerület: %.2f\n", kerulet(r));
    printf("Terület: %.2f\n", terulet(r));
    
    return 0;
}