/*******
 * Read input from cin
 * Use cout << ... to output your result to STDOUT.
 * Use cerr << ... to output debugging information to STDERR
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
   std::string line;
   int i; // incrémant (et non pas un crémant)
   int j; // même chose mais je pouvais pas faire ce jeu de mots nul au pluriel
   
   int n,m; // comme dans l'énoncé
   cin>>n>>m;
   
   int cable_dispo[n]; // tableau de taille n dont l'indice i est vrai ssi le câble i est dispo
   for(i=0; i<n; i++) cable_dispo[i] = 1; //initialisatio,
   
   
   int attrib=1, t=0; /* attrib servira à déterminer s'il y a un pb d'attribution, t est le temps
                        (0<=t<=2500). Par défaut, pas de problème d'attribution donc attrib est à vrai*/
   
   
   
   
   /* On va créer une structure requête avec les dates de début/fin et le numéro du câble qui lui a été attribué, puis on crée un tableau contenant les m requêtes. Un requête à laquelle aucun câble n'a été attribué aura le numéro de câble -1 */
   
   struct requ { int debut; int fin; int numcable;};
  
   requ requete[m];
   for(i=0; i<m; i++){
       cin>>requete[i].debut>>requete[i].fin;
       cerr<<requete[i].debut<<" "<<requete[i].fin<<endl;
       requete[i].numcable = -1;
   }
   
   
   
   /* on fait se dérouler le temps pour voir ce qu'il se passe seconde après seconde,
   et ce tant qu'il n'y a pas de problème d'attribution de numéro  */
   while((t<=2500) && attrib){
       
       
       /* au début d'un nouvel instant, on regarde d'abord quelles requêtes se terminent,
       pour pouvoir récupérer les câbles rendus*/
       for(i=0; i<m; i++){
           /* on parcourt les requêtes et si on se trouve à l'instant de fin de la requête, 
           on "rend" le câble càd on passe la disponibilité du câble à vrai*/ 
           if( t == requete[i].fin ){
               cable_dispo[requete[i].numcable] = 1;
           }
       }
       
       
       /* Maintenant on va parcourir à nouveau les requêtes pour voir ce qu'il faut donner. 
       Si on se trouve à l'instant de début d'une requête, on parcourt la liste des câbles dispo.
        Le premier qu'on trouve, on l'attribue à la requête et on passe la disponibilité du câble
        dans le tableau à faux puis on passe attrib à vrai pour montrer qu'on a bien attribué.
        Si on ne trouve rien alors attrib ne repasse pas à vrai, et on sort de toutes les boucles. */
        
       for(i=0; i<m && attrib; i++){
           if(t == requete[i].debut ){
               attrib = 0; // on a pas encore réussi à attribuer un câble pour la requête en cours
               for(j=0; (j<n) && (!attrib) ; j++){ // on parcourt pour attribuer le premier qui vient
                   if(cable_dispo[j]){
                      requete[i].numcable = j;
                      cable_dispo[j] = 0; // plus dispo, on vient de l'attribuer
                      attrib = 1; // on a réussi à attribuer un câble
                   }
               }
           }
       }
       
       
       t++; // seconde suivante
   }
   
   
   /* Si on sort par problème d'attribution, on envoie "pas possible". Sinon, on liste les
   numéros attribués à chaque requête, dans le même ordre que les requêtes de l'entrée */
   if( !attrib ) cout<<"pas possible";
   else {
       // parcours pour affichages des numéros attribués
    	for(i=0;i<m;i++){
    	    cout<<requete[i].numcable+1;
    	    cout<<" ";
    	}
   }
	
	/*Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}
