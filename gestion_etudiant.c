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
    float note_generale;
    date date_naissance;
} etudiant;

etudiant T[100];
int taille = 0;
int nombre = 1;

void ajoute_eleve()
{
    int choix;
    int jours_dans_mois;
    printf("-------------------------------------departement--------------------------------\n");
    printf("+-------------------+-------------------+-------------------+-------------------+\n");
    printf("| 1 => math         | 2 => physique     | 3 => chimie       | 4 => informatique |\n");
    printf("+-------------------+-------------------+-------------------+-------------------+\n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        strcpy(T[taille].departement, "math");
        break;
    case 2:
        strcpy(T[taille].departement, "physique");
        break;
    case 3:
        strcpy(T[taille].departement, "chimie");
        break;
    case 4:
        strcpy(T[taille].departement, "informatique");
        break;
    default:
        printf("Choix invalide.\n");
        break;
    }

    printf("Entrer votre nom : ");
    scanf("%s", T[taille].nom);
    printf("Entrer votre prenom : ");
    scanf("%s", T[taille].prenom);

    printf("entrer la moyenne general : ");
    scanf("%f", &T[taille].note_generale);
    T[taille].id = nombre;
    printf("Entrer votre date de naissance : \n");

    do
    {
        printf("Entrer le jour : ");
        scanf("%d", &T[taille].date_naissance.jour);
        printf("Entrer le mois : ");
        scanf("%d", &T[taille].date_naissance.mois);
        printf("Entrer l'année : ");
        scanf("%d", &T[taille].date_naissance.annee);

        //  le mois
        if (T[taille].date_naissance.mois < 1 || T[taille].date_naissance.mois > 12)
        {
            printf("Mois invalide. Il doit être entre 1 et 12.\n");
            continue;
        }

        // jour de  le mois
        if (T[taille].date_naissance.mois == 2)
        {
            if ((T[taille].date_naissance.annee % 4 == 0 && T[taille].date_naissance.annee % 100 != 0) || (T[taille].date_naissance.annee % 400 == 0))
            {
                jours_dans_mois = 29; // Année bissextile
            }
            else
            {
                jours_dans_mois = 28; // Année non bissextile
            }
        }
        else if (T[taille].date_naissance.mois == 4 || T[taille].date_naissance.mois == 6 || T[taille].date_naissance.mois == 9 || T[taille].date_naissance.mois == 11)
        {
            jours_dans_mois = 30; // Mois avec 30 jours
        }
        else
        {
            jours_dans_mois = 31; // Mois avec 31 jours
        }

        //  le jour
        if (T[taille].date_naissance.jour < 1 || T[taille].date_naissance.jour > jours_dans_mois)
        {
            printf("Jour invalide pour ce mois. Le mois %d a %d jours.\n", T[taille].date_naissance.mois, jours_dans_mois);
            continue;
        }

        //  l'année
        if (T[taille].date_naissance.annee < 1000)
        {
            printf("Année invalide. Elle doit être supérieure à 1000.\n");
            continue;
        }

        break;

    } while (1);

    printf("Date valide : %d/%d/%d\n", T[taille].date_naissance.jour, T[taille].date_naissance.mois, T[taille].date_naissance.annee);

    taille++;
    nombre++;
}
void afficher()
{
    for (int i = 0; i < taille; i++)
    {
        printf("Le numéro de l'élève %d est : %d | ", i + 1, T[i].id);
        printf("Le nom %d est : %s | ", i + 1, T[i].nom);
        printf("Le prénom %d est : %s | ", i + 1, T[i].prenom);
        printf("Le département %d est : %s | ", i + 1, T[i].departement);
        printf("La note générale %d est : %.2f | ", i + 1, T[i].note_generale);
        printf("La date de naissance %d est : %d/%d/%d\n", i + 1, T[i].date_naissance.jour , T[i].date_naissance.mois , T[i].date_naissance.annee);
    }
}

int cherhche_elt(int indice)
{
    for (int i = 0; i < taille; i++)
    {
        if (indice == T[i].id)
        {
            return i;
        }
    }
    return -1;
}

void modifier_etud()
{
    int id_recherecher;
    char choix; // Vérifier si l'utilisateur veut changer le département
    int found;      // Indice qui retourne l'élément trouvé
    int chan;   // Le choix de nouveau département

    printf("Entrer l'ID de l'étudiant que vous voulez modifier : ");
    scanf("%d", &id_recherecher);

    found = cherhche_elt(id_recherecher); // Fonction de recherche
    if (found == -1)
    {
        printf("L'étudiant n'existe pas.\n");
    }
    else
    {
        printf("Entrer le nouveau nom : ");
        scanf("%s", T[found].nom);

        printf("Entrer le nouveau prénom : ");
        scanf("%s", T[found].prenom);

        printf("Entrer la nouvelle note générale : ");
        scanf("%f", &T[found].note_generale);

        printf("Voulez-vous changer le département ? (Y/N) : ");
        scanf(" %c", &choix); 

        if (choix == 'Y' || choix == 'y')
        {
            printf("+-------------------+-------------------+-------------------+-------------------+\n");
            printf("| 1 => math         | 2 => physique     | 3 => chimie       | 4 => informatique |\n");
            printf("+-------------------+-------------------+-------------------+-------------------+\n");
            scanf("%d", &chan);

            switch (chan)
            {
            case 1:
                strcpy(T[found].departement, "math");
                break;
            case 2:
                strcpy(T[found].departement, "physique");
                break;
            case 3:
                strcpy(T[found].departement, "chimie");
                break;
            case 4:
                strcpy(T[found].departement, "informatique");
                break;
            default:
                printf("Choix invalide pour le département.\n");
                break;
            }
        }

        // Mise à jour de la date de naissance
        printf("Entrer la nouvelle date de naissance : \n");
        printf("Entrer le jour : ");
        scanf("%d", &T[found].date_naissance.jour);
        printf("Entrer le mois : ");
        scanf("%d", &T[found].date_naissance.mois);
        printf("Entrer l'année : ");
        scanf("%d", &T[found].date_naissance.annee);
    }
}
void suprimmer(){
    int e_ID;
    int found;

    printf("entrer l'ID de l'eleve que vous voulez suprimer : ");
    scanf("%d",&e_ID);
    found=cherhche_elt(e_ID);
    if(found == -1){
        printf("l'eleve que vous voulez suprimer n'existe pas");
    }
    else{
for(int i = found ; i < taille - 1 ; i++){
   T[i] = T[i + 1];
}
taille--;
    }

}
void culcule_moy(){
    float moy_math = 0;
    float moy_phys = 0;
    float moy_chim = 0;
    float moy_info = 0;
    int m = 0 , ph = 0 , ch = 0,in = 0;
    for(int i =0 ; i < taille ; i++){
        if(strcmp(T[i].departement,"math")==0){moy_math += T[i].note_generale; m++;}
        if(strcmp(T[i].departement,"physique")==0){moy_phys += T[i].note_generale; ph++;}
        if(strcmp(T[i].departement,"chimie")==0){moy_chim += T[i].note_generale; ch++;}
        if(strcmp(T[i].departement,"informatique")==0){moy_info += T[i].note_generale ; in++;}

    }
    if (m > 0) moy_math = moy_math / m;
    if (ph > 0) moy_phys = moy_phys / ph;
    if (ch > 0) moy_chim = moy_chim / ch;
    if (in > 0) moy_info = moy_info / in;
    printf("Moyenne des notes dans le departement de math est : %.2f\n", moy_math);
    printf("Moyenne des notes dans le departement de physique : %.2f\n", moy_phys);
    printf("Moyenne des notes dans le departement de chimie : %.2f\n", moy_chim);
    printf("Moyenne des notes dans le departement de informatique : %.2f\n", moy_info);

}
int main()
{
    int choix;
    int c;
    do{
    printf("+-------------------+-------------------+-------------------+-------------------+-\n");
    printf("************************************menu******************************************\n");
    printf("+-------------------+-------------------+-------------------+--------------------+\n");
    printf("\n");
    printf("--------------------------------------------------------------------------------------");
    printf("1=>Ajouter un étudiant | 2=>Modifier ou supprimer un etudiant | 3=>Afficher les details d'un etudiant | 4=>Calculer la moyenne generale | 5=>Statistiques | 6=>Rechercher un etudiant | 7=>Trier les etudiants |8=>quitter ");
    printf("\n");
    scanf("%d",&choix);
    switch(choix){
        case 1:
        ajoute_eleve();
        break;
        case 2:
        printf("1=>Modifier un étudiant  | 2=>supprimer un étudiant  ");
        scanf("%d",&c);
        if(c == 1 ){modifier_etud();}
        else if(c == 2){suprimmer();}
        else {printf("choix entre 1 et 2 ");}
        break;
        case 3:
        afficher();
        break;
        case 4:
    }
    
    }while(choix != 8);
}
