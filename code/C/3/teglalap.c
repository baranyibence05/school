#include <stdio.h>

float kerulet(float a, float b) {
    return 2 * (a + b);
}

float terulet(float a, float b) {
    return a * b;
}

int main() {
    float hosszusag, szelesseg;
    
    printf("Add meg a téglalap hosszúságát (cm): ");
    scanf("%f", &hosszusag);
    
    printf("Add meg a téglalap szélességét (cm): ");
    scanf("%f", &szelesseg);
    
    printf("\nKerület: %.2f cm\n", kerulet(hosszusag, szelesseg));
    printf("Terület: %.2f cm²\n", terulet(hosszusag, szelesseg));
    
    return 0;
}