#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void update () { 
    printf (" \033[ H \033[ J") ;
    }
void gotoxy (int x , int y ) { 
    printf (" \033[% d;% dH",x , y ) ;
}

void skating_cow(){ // affiche une vache animee qui avance de la droite vers la gauche
    char *vache[] = {
        "        \\   ^__^\n",
        "         \\  (oo)\\_______\n",
        "            (__)\\       )\\/\\\n",
        "                ||----w |\n",
        "                ||     ||\n",
        "               (=========)\n",
        "                O       O\n"};
    
    int cow_height = sizeof(vache) / sizeof(char*);
    int x = 50;
    int y = 50;
    for(int j=0; j < 50; j++){
        system("clear");
        update();
        for (int i = 0; i < cow_height; i++) {
            gotoxy(x, y-j);
            printf("%s", vache[i]);
        }
        sleep(1);
        
    }    
}

void multicolor(char texte[]){ // permet de colorer du texte
    int couleurs[] = { 196, 202, 208, 214, 220, 226, 190, 21, 27, 33, 39, 45, 51, 57, 93, 99, 105, 111, 117, 123, 159, 165, 171, 177, 183, 189 };
    int nombreCouleurs = sizeof(couleurs) / sizeof(int);
    for (int i = 0; i < strlen(texte); i++) {
        int couleur = couleurs[rand() % nombreCouleurs]; // Choix d'une couleur au hasard 
        printf("\033[38;5;%dm%c", couleur, texte[i]);
    }
}
void affiche_vache(char eyes[], char langue[],int rgb,int pc, char texte[]){ // affiche la vache
    
    if(rgb == 1){ // si la vache n'a pas l'option multicouleur
        printf("%s\n", texte); // affiche le message
        for(int i = 0; i < strlen(texte)-1;i++){
            printf("-");
        }
        printf("\n");
        if (pc == 1){ // si la vache n'a pas l'option pc
            printf("        \\   ^__^\n");
            printf("         \\  (%c%c)\\_______\n", eyes[0], eyes[1]);
            printf("            (__)\\       )\\/\\\n");
            printf("             %c%c||----w |\n",langue[0], langue[1]);
            printf("               ||     ||\n");
        }else{ // si la vache a l'option pc
            printf("              ,---------------------------,\n");
            printf("              |  -----------------------  |\n");
            printf("              | |                       | |\n");
            printf("              | |                       | |\n");
            printf("              | |       %c       %c       | |\n", eyes[1], eyes[0]);
            printf("              | |                       | |\n");
            printf("              | |          %c%c%c          | |\n", langue[1],langue[0], langue[1]);
            printf("              |  _______________________  |\n");
            printf("              |___________________________|\n");
            printf("            ,----_____     []     _______-------,\n");
            printf("          /         |______________|           /|\n");
            printf("        /___________________________________ /  | ___\n");
            printf("        |                                   |   |    )\n");
            printf("        |  _ _ _                 [-------]  |   |   (\n");
            printf("        |  o o o                 [-------]  |  /    _)_\n");
            printf("        |__________________________________ |/     /  /\n");
            printf("    /-------------------------------------/|      ( )/\n");
            printf("  /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
            printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }else{ // si la vache a l'option multicouleur
        multicolor(texte);
        printf("\n");
        for(int i = 0; i < strlen(texte)-1;i++){
            multicolor("-");
        }
        printf("\n");
        if (pc == 1){ // si la vache n'a pas l'option pc
            char yeux_texte[100];
            char langue_texte[100];
            sprintf(yeux_texte, "         \\  (%c%c)\\_______\n", eyes[0], eyes[1]);
            sprintf(langue_texte, "             %c%c ||----w |\n",langue[0], langue[1]);
            multicolor("        \\   ^__^\n");
            multicolor(yeux_texte);
            multicolor("            (__)\\       )\\/\\\n");
            multicolor(langue_texte);
            multicolor("                ||     ||\n");
        }else{ // si la vache a l'option pc
            char yeux_texte[100];
            char langue_texte[100];
            sprintf(yeux_texte, "              | |       %c       %c       | |\n", eyes[1], eyes[0]);
            sprintf(langue_texte, "              | |          %c%c%c          | |\n", langue[1],langue[0], langue[1]);
            multicolor("              ,---------------------------,\n");
            multicolor("              |  -----------------------  |\n");
            multicolor("              | |                       | |\n");
            multicolor("              | |                       | |\n");
            multicolor(yeux_texte);
            multicolor("              | |                       | |\n");
            multicolor(langue_texte);
            multicolor("              |  _______________________  |\n");
            multicolor("              |___________________________|\n");
            multicolor("            ,----_____     []     _______-------,\n");
            multicolor("          /         |______________|           /|\n");
            multicolor("        /___________________________________ /  | ___\n");
            multicolor("        |                                   |   |    )\n");
            multicolor("        |  _ _ _                 [-------]  |   |   (\n");
            multicolor("        |  o o o                 [-------]  |  /    _)_\n");
            multicolor("        |__________________________________ |/     /  /\n");
            multicolor("    /-------------------------------------/|      ( )/\n");
            multicolor("  /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
            multicolor("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
            multicolor("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
    
}

int main(int argc, char* argv[]) {
    // on separe les options du texte 
    char *options = malloc(100 * sizeof(char));
    char *message = malloc(100 * sizeof(char));
    for (int i = 1; i < argc; i++) {
        if(argv[i][0] == '-'){
            strcat(options, argv[i]);
        }else{
            strcat(message, argv[i]);
            strcat(message, " ");
        }
        
    }      
    // On initialise les variables
    char eyes[] = {'0','0'};
    char langue[] = {' ',' '};
    int changer_forme = 1;
    int rgb = 1;
    int j = 0;
    // Pour toutes les options on verifie si elle correspond a une option connue
    // Si elle est connue on fait l'action correspond à l'option
    while(j < strlen(options)){
        if(options[j] == '-'){
            j++; 
            if(options[j] == 'e'){ // option changer les yeux
                eyes[0] = options[j+1]; 
                eyes[1] = options[j+2]; 
                j+=3;
            }else if(options[j] == 't'){ // option changer la langue
                langue[0] = options[j+1]; 
                langue[1] = options[j+2]; 
                j+=3;
            //option changer la vache en pc
            }else if(options[j] == 'c' && options[j+1] == 'p' && options[j+2] == 'u'){
                changer_forme = 0;
                j+=3;
            //option changer la couleur
            }else if(options[j] == 'r' && options[j+1] == 'g' && options[j+2] == 'b'){
                rgb = 0;
                j+=3;
            }else{
                printf("Commande %c inconnue\n", options[j]);
                j++; 
            }
        }else{
            while(options[j] != '-' && j < strlen(options)){
                j++;
            }
        }
        
    }

    affiche_vache(eyes, langue, rgb, changer_forme, message);
    free(options);
    free(message);
    return 0;
}
