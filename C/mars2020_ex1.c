
/*******
 * Read input from STDIN
 * Use: printf(...) or fprintf( stdout, ...) to output your result to stdout.
 * Use: fprintf(stderr, ...);  to output debugging information to stderr.
 * ***/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "libisograd.h"

struct color
{
    char couleur[10];
    int compteur;
};

int main()
 {
    FILE* fichier = fopen("./choix_couleur.txt","r");
    char s[10];
    int n;
    struct color tableau[10];
    //initialisation du tableau de couleur/compteur
    for (int i =0; i<10; i++)
    {
        strcpy(tableau[i].couleur,"");
        tableau[i].compteur = 0;
    }
    if (fichier == NULL)
    {
        return 0;
        }
    fscanf(fichier,"%d",&n);
    //on parcourt le fichier
    while (fscanf(fichier,"%s", s) != EOF)
    {
        int j = 0;
        int checker = 0;
        //on parcourt le tableau jusqu'à atteindre la partie non encore remplie
        while (strcmp("",tableau[j].couleur) != 0)
        {
          //si la couleur du fichier correspond à une couleur du tableau
          if (strcmp(s,tableau[j].couleur) == 0)
            {
                tableau[j].compteur += 1;
                //confirme qu'une donnée à bien été ajoutée au tableau
                checker = 1;
            }
            j += 1;
        }
        //si aucune donnée n'a été ajouté et qu'on est arrivé au bout de la partie remplie du tableau,
        //la couleur du fichier est une nouvelle couleur : on ajoute une nouvelle colonne au tableau
        if(checker == 0){
            strcpy(tableau[j].couleur,s);
            tableau[j].compteur += 1;
        }
    }
    //le tableau est rempli, on cherche les maximum
    int max1 =0;
    int max2 =0;
    char couleur_1[10];
    char couleur_2[10];
    strcpy(couleur_1,tableau[0].couleur);
    strcpy(couleur_2,tableau[0].couleur);
    for( int j = 0; j < 10; j ++)
    {
        if (tableau[j].compteur > max1)
        {
            max1 = tableau[j].compteur;
            strcpy(couleur_1,tableau[j].couleur);
        }
    }
    for( int j = 0; j < 10; j ++)
    {
        if ( (tableau[j].compteur > max2)
          && (max1 != tableau[j].compteur) )
          {
            max2 = tableau[j].compteur;
            strcpy(couleur_2,tableau[j].couleur);
        }
    }
    fclose(fichier);
    fprintf(stdout,"%d %d\n", max1, max2 );
    fprintf(stdout,"%s %s", couleur_1,couleur_2 );
}
