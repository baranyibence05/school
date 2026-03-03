#include <stdio.h>
#include <math.h>

double get_double();
double felszin(double radius);
double terfogat(double radius);

int main() {
    double radius;
    
    printf("Adja meg a gömb sugarát: ");
    radius = get_double();
    
    double surface_area = felszin(radius);
    double volume = terfogat(radius);
    
    printf("Felszín: %.2f\n", surface_area);
    printf("Térfogat: %.2f\n", volume);
    
    return 0;
}

double get_double() {
    double value;
    scanf("%lf", &value);
    return value;
}

double felszin(double radius) {
    return 4 * M_PI * radius * radius;
}

double terfogat(double radius) {
    return (4.0 / 3.0) * M_PI * radius * radius * radius;
}