#include <stdio.h>

int main() {
    int magassag;
    
    printf("magassag: ");
    scanf("%d", &magassag);
    printf("\n");
    
    for (int i = 1; i <= magassag; i++) {

        for (int j = 0; j < magassag - i; j++) {
            printf(" ");
        }
        
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        
        printf("  ");
        
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        
        printf("\n");
    }
    
    return 0;
}