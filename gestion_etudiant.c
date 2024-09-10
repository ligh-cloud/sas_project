#include <stdio.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int annee;

} date;

typedef struct
{
    int id;
    char nom[20];
    char prenom[20];
    char departement[20];
    int note_generale;
    date date_naissance;
} etudiant;

etudiant T[100];
int taille;
int nombre = 1;

void ajoute_eleve()
{
    int choix;
    printf("----------------------departement------------------\n");
    printf("\n");
    printf("1=>math | 2=>physique | 3=>chimie | 4=>informatique\n");
    printf("-------   -----------   ---------   ---------------\n");

    switch (choix)
    {
    case 1:
        strcpy(T[taille].departement, "math");
    case 2:
        strcpy(T[taille].departement, "physique");
    case 3:
        strcpy(T[taille].departement, "chimie");
    case 4:
        strcpy(T[taille].departement, "informatique");
    }
    printf("entrer votre nom ");
    scanf("%s", T[taille].nom);
    printf("entrer votre prenom ");
    scanf("%s", T[taille].prenom);
    printf("entrer votre date de naissance : \n");
    do
    {
        printf("entrer le jour : ");
        scanf("%d", &T[taille].date_naissance.jour);
        printf("entrer le mois : ");
        scanf("%d", &T[taille].date_naissance.mois);
        printf("entrer lannee : ");
        scanf("%d", &T[taille].date_naissance.annee);
        if (T[taille].date_naissance.jour > 32 || T[taille].date_naissance.mois > 13 || T[taille].date_naissance.annee < 1000)
        {
            printf("entrer la correcte date");
        }
    } while (T[taille].date_naissance.jour > 32 || T[taille].date_naissance.mois > 13 || T[taille].date_naissance.annee < 1000);
    T[taille].id = nombre;
    taille++;
    nombre++;
}
int cherhche_elt(int indice){
    int t;
    int found = 0;
    for(int i = 0 ; i < taille ; i++){
        if(indice == T[taille].id){
            t = i;
            found = 1;
        }
    }
    if(found == 0 ) printf("element n'existe pas");
    return t;
}
void modifier_etud(){
    int id_recherecher;
    int f; //indice qui return lelement trouver
    printf("entrer id de letudiant que vous voulez modifier : ");
    scanf("%d",&id_recherecher);
    f = cherhche_elt(id_recherecher);
    printf("entrer le nouveau nom : ");
    scanf("%s",T[f].nom);
    printf("entrer le nouveau prenom : ");
    scanf("%s",T[f].prenom);

}



int main()
{
    printf("----------------------------------------------------------------------\n");
    printf("******************************menu************************************\n");
    printf("----------------------------------------------------------------------\n");
    ajoute_eleve();
}
