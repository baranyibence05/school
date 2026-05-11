#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define VERSION "v1.2.0"

typedef struct 
{
    const char *id;
    const char *desc;
    const char *def_name;
    const char *template;
} Language;

const Language db[] = {
    {"c",  "C forraskod",        "main.c",  "#include <stdio.h>\n\nint main() {\n    printf(\"Hello World\\n\");\n    return 0;\n}\n"},
    {"py", "Python forraskod",   "main.py", "def main():\n    print(\"Hello World\")\n\nif __name__ == \"__main__\":\n    main()\n"},
    {"js", "Javascript forras",  "main.js", "console.log('Hello World');\n"},
    {"sh", "Bash script",        "main.sh", "#!/bin/bash\n\necho 'Hello World'\n"}
};

const int lang_count = sizeof(db) / sizeof(db[0]);

void show_help() 
{
    printf("Hasznalat: alap <nyelv> [fajlnev | --stdout]\n\n");
    printf("Kapcsolok:\n");
    printf("  -h, --help     Sugo megjelenitese\n");
    printf("  -v, --version  Verzioszam\n");
    printf("  --stdout       Kiirasss a konzolra fajlba iras helyett\n\n");
    printf("Tamogatott nyelvek:\n");
    for (int i = 0; i < lang_count; i++) {
        printf("  %-8s -> %-20s (alapertelmezett: %s)\n", db[i].id, db[i].desc, db[i].def_name);
    }
}

int main(int argc, char *argv[]) 
{
    // 1. Alapvető kapcsolók kezelése
    if (argc < 2) { 
        show_help(); return 0; 
    }
    
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) 
    {
        show_help();
        return 0;
    }

    if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) 
    {
        printf("alap verzió: %s\n", VERSION);
        return 0;
    }

    // 2. Nyelv keresése
    const Language *selected = NULL;
    for (int i = 0; i < lang_count; i++) 
    {
        if (strcmp(argv[1], db[i].id) == 0) 
        {
            selected = &db[i];
            break;
        }
    }

    if (!selected) 
    {
        fprintf(stderr, "Hiba: Ismeretlen nyelv: '%s'\n", argv[1]);
        return 1;
    }

    // 3. Mód és fájlnév meghatározása
    int is_stdout = 0;
    const char *target_file = selected->def_name;

    if (argc >= 3) 
    {
        if (strcmp(argv[2], "--stdout") == 0){
            is_stdout = 1;
        } else {
            target_file = argv[2];
        }
    }

    // 4. Végrehajtás
    if (is_stdout) 
    {
        printf("%s", selected->template);
    } 
    else 
    {
        if (access(target_file, F_OK) == 0) 
        {
            fprintf(stderr, "Hiba: A(z) '%s' fajl mar letezik!\n", target_file);
            return 2;
        }

        FILE *f = fopen(target_file, "w");
        if (!f) 
        {
            perror("Hiba a fajl megnyitasakor");
            return 3;
        }

        fprintf(f, "%s", selected->template);
        fclose(f);
        printf("Sikeresen letrehozva: %s\n", target_file);
    }

    return 0;
}