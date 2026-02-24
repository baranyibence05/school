#include <stdio.h>
#include <math.h>

int main() {
    double sugar;
    double kerulet, terulet;
    
    printf("===== KÖR KALKULÁTOR =====\n\n");
    
    printf("Kérjük adja meg a kör sugarát!\n");
    printf("Sugár (cm): ");
    scanf("%lf", &sugar);
    
    kerulet = 2 * M_PI * sugar;
    terulet = M_PI * sugar * sugar;
    
    printf("\nEredmények:\n");
    printf("Kör sugara: %.2f cm\n", sugar);
    printf("Kerület: %.2f cm\n", kerulet);
    printf("Terület: %.2f cm²\n", terulet);
    printf("\n");
    
    return 0;
}
