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
int taille = 10;
int nombre = 11;
void ajouter_elt_tableau()
{
    T[0].id = 1; // eleve numero 1
    strcpy(T[0].nom, "hatim");
    strcpy(T[0].prenom, "belghiti");
    strcpy(T[0].departement, "physique");
    T[0].note_generale = 14.48;
    T[0].date_naissance.jour = 18;
    T[0].date_naissance.mois = 10;
    T[0].date_naissance.annee = 2001;
    T[1].id = 2; // eleve numero 2
    strcpy(T[1].nom, "khaled");
    strcpy(T[1].prenom, "hanafi");
    strcpy(T[1].departement, "informatique");
    T[1].note_generale = 16.30;
    T[1].date_naissance.jour = 12;
    T[1].date_naissance.mois = 9;
    T[1].date_naissance.annee = 2003;
    T[2].id = 3; // eleve numero 3
    strcpy(T[2].nom, "mohammed");
    strcpy(T[2].prenom, "ouali");
    strcpy(T[2].departement, "math");
    T[2].note_generale = 10.01;
    T[2].date_naissance.jour = 16;
    T[2].date_naissance.mois = 11;
    T[2].date_naissance.annee = 2006;
    T[3].id = 4; // eleve numero 4
    strcpy(T[3].nom, "karim");
    strcpy(T[3].prenom, "lkhair");
    strcpy(T[3].departement, "chimie");
    T[3].note_generale = 7.23;
    T[3].date_naissance.jour = 30;
    T[3].date_naissance.mois = 7;
    T[3].date_naissance.annee = 1998;
    T[4].id = 5; // eleve numero 5
    strcpy(T[4].nom, "achraf");
    strcpy(T[4].prenom, "kabir");
    strcpy(T[4].departement, "math");
    T[4].note_generale = 13.25;
    T[4].date_naissance.jour = 23;
    T[4].date_naissance.mois = 8;
    T[4].date_naissance.annee = 1996;
    T[5].id = 6; // eleve numero 6
    strcpy(T[5].nom, "bachir");
    strcpy(T[5].prenom, "lkhair");
    strcpy(T[5].departement, "informatique");
    T[5].note_generale = 8.50;
    T[5].date_naissance.jour = 2;
    T[5].date_naissance.mois = 7;
    T[5].date_naissance.annee = 1998;
    T[6].id = 7; // eleve numero 7
    strcpy(T[6].nom, "ismail");
    strcpy(T[6].prenom, "baoud");
    strcpy(T[6].departement, "informatique");
    T[6].note_generale = 19.5;
    T[6].date_naissance.jour = 20;
    T[6].date_naissance.mois = 10;
    T[6].date_naissance.annee = 2004;
    T[7].id = 8; // eleve numero 8
    strcpy(T[7].nom, "hamza");
    strcpy(T[7].prenom, "lhadouchi");
    strcpy(T[7].departement, "physique");
    T[7].note_generale = 8.5;
    T[7].date_naissance.jour = 2;
    T[7].date_naissance.mois = 4;
    T[7].date_naissance.annee = 2002;
    T[8].id = 9; // eleve numero 1
    strcpy(T[8].nom, "ayoub");
    strcpy(T[8].prenom, "lhnanawi");
    strcpy(T[8].departement, "physique");
    T[8].note_generale = 14.48;
    T[8].date_naissance.jour = 8;
    T[8].date_naissance.mois = 12;
    T[8].date_naissance.annee = 2003;
    T[9].id = 10; // eleve numero 1
    strcpy(T[9].nom, "achraf");
    strcpy(T[9].prenom, "chahboun");
    strcpy(T[9].departement, "chimie");
    T[9].note_generale = 6.8;
    T[9].date_naissance.jour = 13;
    T[9].date_naissance.mois = 9;
    T[9].date_naissance.annee = 2008;
}

void ajoute_eleve()
{
    int choix;
    int jours_dans_mois;
    printf("-------------------------------------departement--------------------------------\n");
    printf("+-------------------+-------------------+-------------------+-------------------+\n");
    printf("| 1 => math         | 2 => physique     | 3 => chimie       | 4 => informatique |\n");
    printf("+-------------------+-------------------+-------------------+-------------------+\n");
    printf("entrer le departement de l'eleve : ");
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
    printf("entrer votre date de naissance : \n");

    do
    {
        printf("Entrer le jour : ");
        scanf("%d", &T[taille].date_naissance.jour);
        printf("Entrer le mois : ");
        scanf("%d", &T[taille].date_naissance.mois);
        printf("Entrer l'annee : ");
        scanf("%d", &T[taille].date_naissance.annee);

        //  le mois
        if (T[taille].date_naissance.mois < 1 || T[taille].date_naissance.mois > 12)
        {
            printf("mois invalide. il doit etre entre 1 et 12.\n");
            continue;
        }

        // jour de  le mois
        if (T[taille].date_naissance.mois == 2)
        {
            if ((T[taille].date_naissance.annee % 4 == 0 && T[taille].date_naissance.annee % 100 != 0) || (T[taille].date_naissance.annee % 400 == 0))
            {
                jours_dans_mois = 29; // annee bissextile
            }
            else
            {
                jours_dans_mois = 28; // annee non bissextile
            }
        }
        else if (T[taille].date_naissance.mois == 4 || T[taille].date_naissance.mois == 6 || T[taille].date_naissance.mois == 9 || T[taille].date_naissance.mois == 11)
        {
            jours_dans_mois = 30; // mois avec 30 jours
        }
        else
        {
            jours_dans_mois = 31; // mois avec 31 jours
        }

        //  jour
        if (T[taille].date_naissance.jour < 1 || T[taille].date_naissance.jour > jours_dans_mois)
        {
            printf("jour invalide pour ce mois. Le mois %d a %d jours.\n", T[taille].date_naissance.mois, jours_dans_mois);
            continue;
        }

        //  l'annee
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
        printf("L'ID de l'eleve %d est : %d | ", i + 1, T[i].id);
        printf("Le nom %d est : %s | ", i + 1, T[i].nom);
        printf("Le prenom %d est : %s | ", i + 1, T[i].prenom);
        printf("Le departement %d est : %s | ", i + 1, T[i].departement);
        printf("La note generale %d est : %.2f | ", i + 1, T[i].note_generale);
        printf("La date de naissance %d est : %d/%d/%d\n", i + 1, T[i].date_naissance.jour, T[i].date_naissance.mois, T[i].date_naissance.annee);
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
    int found;  // Indice qui retourne l'élément trouvé
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
        printf("entrer le nouveau nom : ");
        scanf("%s", T[found].nom);

        printf("entrer le nouveau prenom : ");
        scanf("%s", T[found].prenom);

        printf("entrer la nouvelle note generale : ");
        scanf("%f", &T[found].note_generale);

        printf("voulez vous changer le departement ? (Y/N) : ");
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
        printf("entrer la nouvelle date de naissance : \n");
        printf("entrer le jour : ");
        scanf("%d", &T[found].date_naissance.jour);
        printf("entrer le mois : ");
        scanf("%d", &T[found].date_naissance.mois);
        printf("entrer l'année : ");
        scanf("%d", &T[found].date_naissance.annee);
    }
}
void suprimmer()
{
    int e_ID;
    int found;

    printf("entrer l'ID de l'eleve que vous voulez suprimer : ");
    scanf("%d", &e_ID);
    found = cherhche_elt(e_ID);
    if (found == -1)
    {
        printf("l'eleve que vous voulez suprimer n'existe pas");
    }
    else
    {
        for (int i = found; i < taille - 1; i++)
        {
            T[i] = T[i + 1];
        }
        taille--;
    }
}
void culcule_moy()
{
    float moy_math = 0;
    float moy_phys = 0;
    float moy_chim = 0;
    float moy_info = 0;
    int m = 0, ph = 0, ch = 0, in = 0;

    for (int i = 0; i < taille; i++)
    {
        if (strcmp(T[i].departement, "math") == 0)
        {
            moy_math += T[i].note_generale;
            m++;
        }
        if (strcmp(T[i].departement, "physique") == 0)
        {
            moy_phys += T[i].note_generale;
            ph++;
        }
        if (strcmp(T[i].departement, "chimie") == 0)
        {
            moy_chim += T[i].note_generale;
            ch++;
        }
        if (strcmp(T[i].departement, "informatique") == 0)
        {
            moy_info += T[i].note_generale;
            in++;
        }
    }
    if (m > 0)
        moy_math = moy_math / m;
    if (ph > 0)
        moy_phys = moy_phys / ph;
    if (ch > 0)
        moy_chim = moy_chim / ch;
    if (in > 0)
        moy_info = moy_info / in;

    printf("Moyenne des notes dans le departement de math est : %.2f \n", moy_math);

    printf("Moyenne des notes dans le departement de physique : %.2f\n", moy_phys);

    printf("Moyenne des notes dans le departement de chimie : %.2f\n", moy_chim);

    printf("Moyenne des notes dans le departement de informatique : %.2f\n", moy_info);

    printf("Moyenne des notes de tous les estudiants est : %.2f\n", (moy_math + moy_phys + moy_chim + moy_info) / 4);
}
void statique()
{
    etudiant T_cpy[100];
    etudiant temp;
    int choix;
    int i, j;
    int nb_math = 0, nb_physique = 0, nb_chimie = 0, nb_informatique = 0;
    float seuil;
    printf("|1=>afficher le nombre total d'etudiants inscrits                                      |\n");
    printf("|2=>afficher le nombre d'etudiants dans chaque departement                             |\n");
    printf("|3=>afficher les etudiants ayant une moyenne generale superieure a un certain seuil    |\n");
    printf("|4=>afficher les 3 etudiants ayant les meilleures notes                                |\n");
    printf("|5=>afficher le nombre d'etudiants ayant reussi dans chaque departement                |\n");
    printf("\n");
    printf("entrer votre choix : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("le nombre totale des etudiants inscris est : %d ", taille);
        break;
    case 2:
        for (i = 0; i < taille; i++)
        {
            if (strcmp(T[i].departement, "math") == 0)
            {
                nb_math++;
            }
            if (strcmp(T[i].departement, "physique") == 0)
            {
                nb_physique++;
            }
            if (strcmp(T[i].departement, "chimie") == 0)
            {
                nb_chimie++;
            }
            if (strcmp(T[i].departement, "informatique") == 0)
            {
                nb_informatique++;
            }
        }
        printf("le nombre totale des etudiants de departement math est : %d \n", nb_math);
        printf("le nombre totale des etudiants de departement physique est : %d \n", nb_physique);
        printf("le nombre totale des etudiants de departement chimie est : %d \n", nb_chimie);
        printf("le nombre totale des etudiants de departement informatique est : %d \n", nb_informatique);
        break;
    case 3:
        printf("entrer le seuil entre 1 et 20 : ");
        scanf("%f", &seuil);
        printf("les notes sont : \n");
        for (int i = 0; i < taille; i++)
        {
            if (T[i].note_generale >= seuil)
            {
                printf("l'etudiant d'ID %d et nom %s : \n", T[i].id, T[i].nom);
                break;
            }
        }
        
    case 4:
        for (i = 0; i < 3; i++)
        {
            for ( i = 0; i < taille; i++)
            {
                T_cpy[i] = T[i];
            }

            for (i = 0; i < taille - 1; i++)
            {
                for (j = 0; j < taille - i - 1; j++)
                {
                    if (T_cpy[j].note_generale > T_cpy[j + 1].note_generale)
                    {
                        temp = T_cpy[j];
                        T_cpy[j] = T_cpy[j + 1];
                        T_cpy[j + 1] = temp;
                    }
                }
            }
            printf(" les 3 etudiants ayant les meilleures notes sont : \n");
            for (i = 0; i < 3; i++)
            {
                printf("| eleve %d est du nom %s et prenom %s \n|", i + 1, T_cpy[i].nom, T_cpy[i].prenom);
            }}
            break;

    case 5:
            for (int i = 0; i < taille; i++)
            {
                if (T[i].note_generale >= 10)
                {
                    if (strcmp(T[i].departement, "math") == 0)
                        nb_math++;
                    if (strcmp(T[i].departement, "physique") == 0)
                        nb_physique++;
                    if (strcmp(T[i].departement, "chimie") == 0)
                        nb_chimie++;
                    if (strcmp(T[i].departement, "informatique") == 0)
                        nb_informatique++;
                   
                }
            }
             printf("le nombre d'etudiant ayant reussi dans le departement math : %d                             |\n", nb_math);
                    printf("| le nombre d'etudiant ayant reussi dans le departement physique : %d                |\n", nb_physique);
                    printf("| le nombre d'etudiant ayant reussi dans le departement chimie : %d                  |\n", nb_chimie);
                    printf("| le nombre d'etudiant ayant reussi dans le departement informatique : %d            |\n", nb_informatique);
            break;
        }
    }

void recherche()
{
    int choix;
    char name[20];
    int found = 0;
    printf("| 1=>recherche par nom d'etudiant  | 2=>Afficher la liste des etudiants inscrits |\n");
    printf("entrer votre choix : ");
    scanf("%d", &choix);
    if (choix == 1)
    {
        printf("Entrer le nom de l'etudiant que vous voulez chercher : ");
scanf("%s", name);

for (int i = 0; i < taille; i++) {
    if (strcmp(T[i].nom, name) == 0) {
        printf("l'eleve que vous avez chercher est : \n");
        printf("le nom est %s \n", T[i].nom);
        printf("le prenom est %s \n", T[i].prenom);
        printf("le departement est %s \n", T[i].departement);
        printf("le numero unique de l'eleve est : %d \n", T[i].id);
        printf("la note generale est : %.2f \n", T[i].note_generale);
        found = 1;  // Set found flag to true
        break;
    }
}

// If the student was not found
if (!found) {
    printf("eleve non trouver\n");
}

        }

    else if (choix == 2)
    {
        int choice;
        int nb_math = 0, nb_physique = 0, nb_chimie = 0, nb_informatique = 0;
        printf("-------------------------------------departement--------------------------------\n");
        printf("+-------------------+-------------------+-------------------+-------------------+\n");
        printf("| 1 => math         | 2 => physique     | 3 => chimie       | 4 => informatique |\n");
        printf("+-------------------+-------------------+-------------------+-------------------+\n");
        printf("entrer le departement de l'eleve : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (int i = 0; i < taille; i++)
            {
                if (strcmp(T[i].departement, "math") == 0)
                    nb_math++;
            }
            printf("le nombre d'etudiant dans le departement math est : %d \n", nb_math);
            break;
        case 2:
            for (int i = 0; i < taille; i++)
            {
                if (strcmp(T[i].departement, "physique") == 0)
                    nb_physique++;
            }
            printf("le nombre d'etudiant dans le departement physique est : %d \n", nb_physique);
            break;
        case 3:
            for (int i = 0; i < taille; i++)
            {
                if (strcmp(T[i].departement, "chimie") == 0)
                    nb_chimie++;
            }
             printf("le nombre d'etudiant dans le departement chime est : %d \n", nb_chimie);
            break;

        case 4:
            for (int i = 0; i < taille; i++)
            {
                if (strcmp(T[i].departement, "informatique") == 0)
                    nb_informatique++;
            }
            printf("le nombre d'etudiant dans le departement informatique est : %d \n", nb_informatique);
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }




    }
}

void trier()
{
    int choix;
    etudiant temp;
    etudiant t1[100], t2[100];
    int i, j;
    int taille1 = 0, taille2 = 0; // tableau pour les admis et non admis
    printf("| 1=>trier par ordre alphabetique     \n| 2=>Tri des etudiants par moyenne generale \n| 3=>Tri des étudiants selon leur statut de réussite \n|");
    scanf("%d", &choix);
    switch (choix)
    {
        int choice;
    case 1:
        printf("1=>A to Z | 2=>Z to A  : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            for (int i = 0; i < taille; i++)
            {
                for (int j = 0; j < taille - i - 1; j++)
                {
                    if (strcmp(T[j].nom, T[j + 1].nom) > 0)
                    {
                        temp = T[j];
                        T[j] = T[j + 1];
                        T[j + 1] = temp;
                    }
                }
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < taille; i++)
            {
                for (int j = 0; j < taille - i - 1; j++)
                {
                    if (strcmp(T[j].nom, T[j + 1].nom) < 0)
                    {
                        temp = T[j];
                        T[j] = T[j + 1];
                        T[j + 1] = temp;
                    }
                }
            }
        }
        else
            printf("choix invalide");
        break;
    case 2:

            for (i = 0; i < taille - 1; i++) {
        int min = i;
        etudiant temp;

        for (j = i + 1; j < taille; j++) {
        if (T[j].note_generale < T[min].note_generale) {
        min = j;
        }
    }


        if (min != i) {
           temp = T[i];
           T[i] = T[min];
           T[min] = temp;
         }
         }
        break;
    case 3:
        for (i = 0; i < taille; i++)
        {
            if (T[i].note_generale >= 10)
            {
                t1[taille1] = T[i];
                taille1++;
            }
            else if (T[i].note_generale < 10)
            {
                t2[taille2] = T[i];
                taille2++;
            }
        }
        printf("les persones admis sont : \n");
        for (i = 0; i < taille1; i++)
        {
            printf("| le nom %d est %s \n", i + 1, t1[i].nom);
            printf("le prenom %d est %s \n", i + 1, t1[i].prenom);
            printf("le departementde %d est %s \n", i + 1, t1[i].departement);
            printf("le numero unique de l'eleve %d est : %d \n", i + 1, t1[i].id);
            printf("la note generale de %d est : %.2f \n", i + 1, t1[i].note_generale);
        }
        
        }
    }


int main()
{
    int choix;
    int c;
    ajouter_elt_tableau();
    do
    {
        printf("+-------------------+-------------------+-------------------+-------------------+-\n");
        printf("************************************menu******************************************\n");
        printf("+-------------------+-------------------+-------------------+--------------------+\n");
        printf("\n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("| 1=>Ajouter un etudiant \n| 2=>Modifier ou supprimer un etudiant \n| 3=>Afficher les details d'un etudiant \n| 4=>Calculer la moyenne generale \n| 5=>Statistiques \n| 6=>Rechercher un etudiant \n| 7=>Trier les etudiants \n| 8=>quitter  \n");
        printf("\n");
        printf("entrer votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            ajoute_eleve();
            break;
        case 2:
            printf("| 1=>Modifier un etudiant  | 2=>supprimer un etudiant  |");
            scanf("%d", &c);
            if (c == 1)
            {
                modifier_etud();
            }
            else if (c == 2)
            {
                suprimmer();
            }
            else
            {
                printf("choix entre 1 et 2 ");
            }
            break;
        case 3:
            afficher();
            break;
        case 4:
            culcule_moy();
            break;
        case 5:
            statique();
            break;
        case 6:
            recherche();
            break;
        case 7:
            trier();
            break;
        case 8:
            printf("fin de programme");
            break;
        default:
            printf("choix incorrecte");
        }

    } while (choix != 8);
}
