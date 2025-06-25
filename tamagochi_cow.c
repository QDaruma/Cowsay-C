#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int fitness = 5;
int stock = 5;
int mode = 0; //mode 0 -> normal, mode 1 -> simpson

void affiche_vache(int etat){ // affiche la vache en fonction de son etat
    if (mode == 0){
        if (etat == 0){
            printf("^__^\n");
            printf("(XX)\\_ _ _ _ \n");
            printf("(~~)\\ ) ) ) )\\/\\\n");
            printf("    qp----W qp\n");
            printf("    ||      ||\n");

        }else if (etat == 1){
            printf("^__^\n");
            printf("(==)\\_______\n");
            printf("(__)\\       )\\/\\\n");
            printf("  U ||----w |\n");
            printf("    ||     ||\n");
        }else if (etat == 2){
            printf("^__^\n");
            printf("(^^)\\_______\n");
            printf("(__)\\       )\\/\\\n");
            printf("    ||----w |\n");
            printf("    ||     ||\n");
        }
    }else{
        if (etat == 0){
            printf("    &\n");
            printf(" .-¨`¨-.\n") ;       
            printf("/       \\\n");        
            printf("|   __  _|\n");        
            printf("|  /  \\/ \\\n");       
            printf("WW \\_X/_X/\n");        
            printf("(        _)\n");        
            printf("|   .----\\\n");        
            printf(";  | /----'\n");        
            printf("\\__'--;`\n");        
            printf("|___/\\|\n");

        }else if (etat == 1){
            printf("    &\n");
            printf(" .-¨`¨-.\n") ;       
            printf("/       \\\n");        
            printf("|   __  _|\n");        
            printf("|  /  \\/ \\\n");       
            printf("WW \\_=/_=/\n");        
            printf("(        _)\n");        
            printf("|   .----\\\n");        
            printf(";  | /----'\n");        
            printf("\\__'--;`\n");        
            printf("|___/\\|\n");
        }else if (etat == 2){
            printf("    &\n");
            printf(" .-¨`¨-.\n") ;       
            printf("/       \\\n");        
            printf("|   __  _|\n");        
            printf("|  /  \\/ \\\n");       
            printf("WW \\_o/_o/\n");        
            printf("(        _)\n");        
            printf("|   .----\\\n");        
            printf(";  | '----'\n");        
            printf("\\__'--;`\n");        
            printf("|___/\\|\n");
        }
    }
    
}

int generer_entier(int min, int max){ //genre un entier aleatoire dans un intervalle donné
    return rand()%(max-min+1) + min;
}

void stock_update(int lunchfood){ // met a jour le stock
    if (lunchfood>stock){
        lunchfood=stock;
    }else if (lunchfood<0){
        lunchfood=0;
    }
    int crop=generer_entier(-3, 3);
    //ex: si 3 gateaux pourrissent alors qu'ont en a que 2 c'est bizarre donc on met les pertes à 2
    if(stock + crop < 0){ 
        crop = -stock;
    }

    if(crop < 0){
        printf("Oh non ! %d gateau(x) a(ont) pourri...\n", (-1*crop));
    }else if (crop > 0){
        printf("Super ! Vous venez de retrouver %d gateau(x) au fond d'un placard !\n", crop);
    }
    // on met a jour le stock
    stock=(stock-lunchfood)+crop;
    if (stock>10){
        stock=10;
    }else if (stock<0){
        stock=0;
    }
}

void fitness_update(int lunchfood){ // met a jour la sante
    int digestion=generer_entier(-3, 0);
    fitness=(fitness+lunchfood)+digestion;
    if (fitness>10){
        fitness=10;
    }else if (fitness<0){
        fitness=0;
    }
}
int transition (){ // permet de transiter entre les etats en fonction de la sante
    int etat_suivant;
    if (fitness<=0){
            etat_suivant=0;
            affiche_vache(0); //vache morte
        }else if ((fitness >= 1 && fitness<=3) || (fitness >= 7 && fitness<=9)){
            etat_suivant=1;
            affiche_vache(1); //vache malade
        }
        else if (fitness >= 4 && fitness<=6){
            etat_suivant=2;
            affiche_vache(2); //vache contente
        } 
    return etat_suivant;
}

void affiche_food(){
    char perso[100];
    if (mode == 0){
        strcpy(perso, "la vache");
    }else{
        strcpy(perso, "Homer");
    }
    printf("\n   $$  $$  $$\n");
    printf(" __||__||__||__\n");
    printf("|              |\n");
    printf("|   stock: %d   |\n", stock);
    printf("|______________|\n");
    printf("\nCombien de gateaux donner à %s ?(stock: %d):\n", perso, stock);
}

void affiche_texte_anime(char texte_affiche[], char eyes[], char bouche){
    char texte[1000] = "";
    //Introduction
    //on reutilise une partie du code de reading_cow.c
    for (int i = 0; i < strlen(texte_affiche); i++) {
            system("clear");
            char strC[2];
            sprintf(strC, "%c", texte_affiche[i]);
            strcat(texte, strC);
            printf("%s\n", texte);
            for(int i = 0; i < strlen(texte);i++){
                printf("-");
            }
            printf("\n");
            printf("///-\\\\\\");
            printf("\n|-- --|\n");
            printf("|%c   %c|\n", eyes[0], eyes[1]);
            printf("|  v  |\n");
            printf(" \\ %c /\n", bouche);
            printf("  | |\n");
            usleep(300000); // Attente de 0.3s entre l'affichage de chaque caractère
    }
}
int intro(){
    affiche_texte_anime("Salut ! Mon nom est Bonclay, ça te dis de jouer à un jeu ? (o/n)", "^^", 'U');
    char reponse;
    scanf("%c", &reponse);

    if(reponse == 'o'){
        affiche_texte_anime("Super ! Dans ce cas jouons au tamagochi ! Je te propose 2 modes:\n1. vache(normal)\n2. Simpsons\n lequel veux tu ?\n", "^^", 'U');
        while (reponse != '1' && reponse != '2'){
            scanf("%c", &reponse);
            if(reponse == '1'){
                return 0;
            }else if(reponse == '2'){
                return 1;
            }
        }
        
    }else{
        affiche_texte_anime("Bon bah au revoir...", "==", '~');
        exit(0);
    }
    return 0;
}

int main(){
    int etat=2, score=0;
    int lunchfood = 0;
    srand(time(NULL));

    // Intro et choix du mode
    mode = intro();
    //tant que la vache est en vie
    while (etat!=0){
        affiche_food();
        scanf("%d",&lunchfood);
        fitness_update(lunchfood);
        stock_update(lunchfood);
        etat=transition();
        score++;
        // permet de rendre l'affichage plus claire
        if(etat != 0){
            printf("Prochain tour dans 10 secondes\n");
            sleep(10); // on laisse 10s entre chaque tours avant d'effacer la console
            system("clear"); 
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
        
    }
    char perso[100];
    if (mode == 0){
        strcpy(perso, "la vache");
    }else{
        strcpy(perso, "Homer");
    }
    if (score <= 5){
        printf("%s a seulement (sur)vécu %d jours... Nous avons contacté la SPA ainsi que la police.\n", perso,score);
    }else if(score >5 && score <= 15){
        printf("%s a vécu %d jours. Sa vie fut courte mais bien remplie ! (de gateaux)\n", perso ,score);
    }else{
        printf("Bravo ! %s a vécu %d jours.\n", perso ,score);
    }
    
    return 0;
}

