//----------------------------------------Projet SAS-------------------------------------------------

//--------------------------------------Gestion Bancaire---------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//(CIN, Nom et Prénom, Montant)Structure de client.

typedef struct{
    char cn[15];
    char nom[30];
    char prenom[30];
    float montant;
}client;

//Declaration des variables globales.
client clt[100]; // Tableau clt de type client pour enregistrer des donnees des comptes.
int c, k, n, nmbr = 0;
client temp; // un variable de type client pour effectuer l'échange des valeurs dans le tri.
char cni[15]; // une variable utilisé pour comparer une CIN entre par utilisateur et les CIN existes.
float chfr;


void creer_compte(); // Foction pour creation des comptes.
void trier_descendant(); // Fonction pour le tri descendant.
void trier_ascendant(); // Fonction pour le tri ascendant.
void affichage(); // Fonction pour affichage la liste des comptes
void prendre_chiffre(); // Fonction qui afficher la liste des comptes ayant un montant seperieur a un chiffre.
void verifier_cin(); // Fonction pour vérification la disponibilité d'un CIN.


int main()
{

    int choix, oprt, affich; // Des variables pour determiner les choix de l'utilisateur.
    float rtr, dpt; // Des variables pour les opérations retrait et dépot.

    // Cette ligne pour afficher un titre.
    printf("\n----------------------------------------//  Gestion Bancaire  //----------------------------------------\n\n");

do{
    do{

        //Afichage de la menu
        printf("\n-------------------------------------------- Menu pricipale --------------------------------------------\n");

        printf("1 . Ajouter un seul compte.\n");
        printf("2 . Ajouter plusieurs comptes.\n");
        printf("3 . Operations: Retrait, Depot.\n");
        printf("4 . Afficher des donnees.\n");
        printf("5 . Rechercher par CIN.\n");
        printf("6 . Ajouter 1.3%% pour le programme de fidelisation.\n");
        printf("7 . Quitter\n");
        printf("\n------------------------------------------------------------------\n\n");
        printf("Entrez votre choix (Entre 1 et 7):\t");
        scanf("%d", &choix);
        if(choix<1 || choix>7)
            printf("\nVotre choix est invalide!\n");
    }
    while(choix<1 || choix>7);

    switch(choix){


        //1 . Ajouter un seul compte.
        case 1:
            printf("\n-----------Entrez les donnees d'un compte------------\n\n");

            creer_compte();
            break;


        //2 . Ajouter plusieurs comptes.
        case 2:
            printf("Entrez le nombre des comptes:\t");
            scanf("%d", &c);


            for (int i=0; i<c; i++){

                printf("\n-----------Entrez les donnees de compte:%d------------\n", nmbr);

                creer_compte();
            }
            break;


        //3 . Operations: Retrait, Depot.
        case 3:
            printf("1 . Retrait\n2 . Depot\n");
            scanf("%d", &oprt);
            switch(oprt){

                //1 . L'operation de retrait
                case 1:


                    do{
                        verifier_cin();

                    }
                    while(k == 0);


                    if(k == 1){

                        printf("Combien vous voulez retrait:\t");   scanf("%f", &rtr);
                        if(rtr < clt[n].montant){
                            clt[n].montant-=rtr;
                            printf("Le solde maintenant est:\t%.1f", clt[n].montant);
                        }
                        else
                            printf("\nAttention! Le montant que voulez retrait est superieur de montant dans le compte.\n");
                    }
                    else
                        printf("Le CIN a ajouter n'est pas disponible!\n");

                    break;

                //2 . L'operation de depot
                case 2:
                    do{
                        verifier_cin();

                    }while(k == 0);
                    if(k == 1){
                        printf("Combien vous voulez ajouter:\t");   scanf("%f", &dpt);
                        clt[n].montant+=dpt;
                        printf("Le solde maintenant est:\t%.1f", clt[n].montant);
                    }
                    else
                        printf("Le CIN a ajouter n'est pas disponible!\n");

                    break;

                default:
                    break;
            }
            break;


        //4 . Afficher les donnees
        case 4:
            printf("1 . Afficher la liste des comptes par ordre ascendant.\n");
            printf("2 . Afficher la liste des comptes par ordre descendant.\n");
            printf("3 . Afficher la liste des comptes ayant un montant seperieur a un chiffre par ordre ascendant.\n");
            printf("4 . Afficher la liste des comptes ayant un montant seperieur a un chiffre par ordre descendant.\n");
            scanf("%d", &affich);
            switch(affich){

                //1 . Afficher la liste des comptes par ordre ascendant
                case 1:
                    trier_ascendant();
                    affichage();

                    break;


                //2 . Afficher la liste des comptes par ordre descendant
                case 2:
                    trier_descendant();
                    affichage();
                    break;

                //3 . Afficher la liste des comptes ayant un montant seperieur a un chiffre par ordre ascendant
                case 3:


                    trier_ascendant();

                    printf("\nLes comptes bancaire ayant un montant superieur a chiffre introduit Par Ordre Ascendant:\n\n");

                    prendre_chiffre();

                    break;

                //4 . Afficher la liste des comptes ayant un montant seperieur a un chiffre par ordre descendant
                case 4:


                    trier_descendant();

                    printf("\nLes comptes bancaire ayant un montant superieur a chiffre introduit Par Ordre Descendant:\n\n");

                    prendre_chiffre();

                    break;

                default:
                    break;
                    }
                    break;

        //5 . Rechercher par CIN
        case 5:
            verifier_cin();
            if(k == 1){
                printf("CIN:\t%s\n",clt[n].cn);
                printf("NOM:\t%s\n",clt[n].nom);
                printf("PRENOM:\t%s\n",clt[n].prenom);
                printf("MONTANT:\t%.1f\n",clt[n].montant);
            }
            else
                    printf("\nLe CIN a ajouter n'est pas disponible!\n");
            break;

        //6 . Ajouter 1.3% pour le programme de fidelisation
        case 6:
            trier_descendant();
            for(int i=0; i<3; i++){
                clt[i].montant += ((1.3/100) * clt[i].montant);
            }
            printf("\n----------------------------------\n");
            for(int i=0; i<3; i++){

                printf("\nVous avez ajouter 1.3%% aux comptes ayant les 3 premiers montants supérieurs\n");


                printf("CIN:\t%s\n",clt[i].cn);
                printf("NOM:\t%s\n",clt[i].nom);
                printf("PRENOM:\t%s\n",clt[i].prenom);
                printf("MONTANT:\t%.1f\n",clt[i].montant);
            }
            break;


        default:
            break;
    }
}
while(choix != 7);


return 0;
}

void creer_compte(){

    do{
            k = 0;
    printf("CIN:\t\t");     scanf("%s", cni);

    for(int i=0; i<nmbr; i++){
        if (stricmp(cni,clt[i].cn) == 0){
            printf("CIN deja existe! Entrez un nouveau!\n");
            k = 1;
        }
    }
    }
    while(k == 1);
    if(k == 0){
        strcpy(clt[nmbr].cn, cni);
        printf("NOM:\t\t");       scanf("%s", clt[nmbr].nom);
        printf("PRENOM:\t\t");       scanf("%s", clt[nmbr].prenom);
        printf("MONTANT:\t");       scanf("%f", &clt[nmbr].montant);
        nmbr++;
    }
    }

void trier_descendant(){

    for(int i=0; i<nmbr; i++){
        for(int j=i+1; j<nmbr; j++){
            if(clt[i].montant < clt[j].montant){
                temp = clt[i];
                clt[i] = clt[j];
                clt[j] = temp;
            }
        }
    }
}
void trier_ascendant(){
    for(int i=0; i<nmbr; i++){
        for(int j=i+1; j<nmbr; j++){
            if(clt[i].montant > clt[j].montant){
                temp = clt[i];
                clt[i] = clt[j];
                clt[j] = temp;
            }
        }
    }
}
void affichage(){
    for(int i=0; i<nmbr; i++){

        printf("\n----------------------------------\n");


        printf("CIN:\t%s\n",clt[i].cn);
        printf("NOM:\t%s\n",clt[i].nom);
        printf("PRENOM:\t%s\n",clt[i].prenom);
        printf("MONTANT:\t%.1f\n",clt[i].montant);
    }
}
void prendre_chiffre(){
    printf("Entrez un chiffre:\t");       scanf("%f", &chfr);

        for(int i=0; i<nmbr; i++){
            if(clt[i].montant > chfr){

                printf("\n---------------------------------------\n");

                printf("CIN:\t%s\n",clt[i].cn);
                printf("NOM:\t%s\n",clt[i].nom);
                printf("PRENOM:\t%s\n",clt[i].prenom);
                printf("MONTANT:\t%.1f\n",clt[i].montant);

            }
        }
}
void verifier_cin(){
    k = 0;
    printf("Entrez le CIN:\t");     scanf("%s", cni);
    for(int i=0; i<nmbr; i++){
        if(stricmp(cni,clt[i].cn) == 0){
            k = 1;
            n = i;
            break;
        }
    }
}
