#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SOR 100
#define MAX_HOSSZ 100

int is_pti(const char *szak) 
{
    if (strlen(szak) != 3){
        return 0;
    }
    return (toupper(szak[0]) == 'P' && toupper(szak[1]) == 'T' && toupper(szak[2]) == 'I');
}

int compare(const void *a, const void *b) 
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() 
{
    FILE *fp = fopen("nevek.csv", "r");
    if (!fp) 
    {
        perror("Hiba a fajl megnyitasakor");
        return 1;
    }

    char *pti_nevek[MAX_SOR];
    int pti_count = 0;
    char sor[MAX_HOSSZ];

    while (fgets(sor, MAX_HOSSZ, fp) && pti_count < MAX_SOR) 
    {
        sor[strcspn(sor, "\r\n")] = 0;

        char *nev = strtok(sor, ",");
        char *kor = strtok(NULL, ",");
        char *szak = strtok(NULL, ",");

        if (nev && szak && is_pti(szak)) 
        {
            char *formazott_nev = strdup(nev);
            formazott_nev[0] = toupper(formazott_nev[0]);
            
            pti_nevek[pti_count++] = formazott_nev;
        }
    }
    fclose(fp);

    qsort(pti_nevek, pti_count, sizeof(char *), compare);

    for (int i = 0; i < pti_count; i++) 
    {
        printf("%s%s", pti_nevek[i], (i == pti_count - 1) ? "" : ", ");
        free(pti_nevek[i]); 
    }
    printf("\n");

    return 0;
}