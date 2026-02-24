#include <stdio.h>

int main() {
    int hosszusag, szelesseg;
    int kerulet, terulet;
    
    printf("Ez egy téglalap kalkulátor program!\n\n");
    
    printf("Kérjük adja meg a téglalap oldalainak hosszát!\n");
    printf("Hosszúság (cm): ");
    scanf("%d", &hosszusag);
    
    printf("Szélesség (cm): \n");
    scanf("%d", &szelesseg);
    
    kerulet = 2 * (hosszusag + szelesseg);
    terulet = hosszusag * szelesseg;
    
    printf("Eredmények:\n");
    printf("Téglalap méretei: %d cm × %d cm\n", hosszusag, szelesseg);
    printf("Kerület: %d cm\n", kerulet);
    printf("Terület: %d cm^2\n", terulet);
    
    return 0;
}
