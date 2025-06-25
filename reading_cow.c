#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    FILE *input_file;

    // Si le nom d'un fichier est fourni en argument, on le prend sinon on prend le stdin
    if (argc > 1) {
        input_file = fopen(argv[1], "r");
    }else {
        input_file = stdin;
    }

    char ligne[1000];
    char texte[1000] = ""; 

    // on lit le fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), input_file)) {
        
        // on affiche chaque caractère de la ligne
        for (int i = 0; i < strlen(ligne); i++) {
            system("clear");
            char strC[2];
            sprintf(strC, "%c", ligne[i]);
            strcat(texte, strC);
            printf("%s\n", texte);
            printf("-----\n");
            printf(" \\  ^__^\n");
            printf("  \\ (oo)\\_______\n");
            printf("    (__)\\       )\\/\\\n");
            printf("        ||----w |\n");
            printf("        ||     ||\n");
            sleep(1); // Attente de 1s entre l'affichage de chaque caractère
            
        }
    }

    // Ferme le fichier (si il y'en a un)
    if (argc > 1) {
        fclose(input_file);
    }
    return 0;
}

