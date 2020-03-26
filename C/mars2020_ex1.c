Non fonctionnel
/*******
 * Read input from STDIN
 * Use: printf(...) or fprintf( stdout, ...) to output your result to stdout.
 * Use: fprintf(stderr, ...);  to output debugging information to stderr.
 * ***/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libisograd.h"

struct color{
    char couleur[100];
    int compteur;
};

int main() {
   char s[1024];
   int n;
   char* trash;
   int i = 0;
   struct color tableau[1024];
   n = scanf("%d",&n);
   while (scanf("%s", &s) != EOF) {
              for(int j =0; j < 10; j ++ ){
	        if (strcmp(s,tableau[j].couleur) == 0){
	            tableau[j].compteur += 1; 
	        }
	        else{
	            trash = strcpy(tableau[i].couleur,s);
	            tableau[i].compteur = 1;
	            i+=1;
	        }
              }
  }
  int max1 = tableau[0].compteur;
  int max2 = max1;
  char couleur_1[10];
  char couleur_2[10];
  trash = strcpy(couleur_1,tableau[0].couleur);
  trash = strcpy(couleur_2,couleur_1);
  for(struct color* parcours = tableau+1; parcours < tableau + 10; parcours ++ ){
         if ((parcours->compteur) > max1){
                max2 = max1;
                trash = strcpy(couleur_2,couleur_1);
                max1 = parcours->compteur;
                trash =strcpy(couleur_1,parcours->couleur);
          }
    }	
fprintf(stderr,"%s", tableau[0].couleur);
fprintf(stdout,"%s %s", couleur_1,couleur_2 );
}
