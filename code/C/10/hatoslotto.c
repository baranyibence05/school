#include <stdio.h>

void keres_nyero_szamok() {
    int s1, s2, s3, s4, s5, s6;
    long cel_szorzat = 996300;
    int cel_osszeg = 90;

    for (s1 = 1; s1 <= 40; s1++) {
        for (s2 = s1 + 1; s2 <= 41; s2++) {
            for (s3 = s2 + 1; s3 <= 42; s3++) {
                for (s4 = s3 + 1; s4 <= 43; s4++) {
                    for (s5 = s4 + 1; s5 <= 44; s5++) {
                        for (s6 = s5 + 1; s6 <= 45; s6++) {
                            
                            if (s1 + s2 + s3 + s4 + s5 + s6 == cel_osszeg) {
                                // Ha az összeg stimmel, jöhet a szorzat
                                if ((long)s1 * s2 * s3 * s4 * s5 * s6 == cel_szorzat) {
                                    printf("A heti nyeroszamok: %d, %d, %d, %d, %d, %d\n", 
                                            s1, s2, s3, s4, s5, s6);
                                    return; 
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    keres_nyero_szamok();
    return 0;
}