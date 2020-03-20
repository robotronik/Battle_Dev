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
   
   int n;
   cin>>n;
   int f[n+1]; // la liste des valeurs de f
   int s=0, fk, fkp1; // on aura besoin de la somme des occurrences totales, et également de deux termes consécutifs
   cin>>fkp1; //comme on décale d'un rang au début de la boucle, on le met en position f_k+1 pour le décalage
   for(int i=0; i<n; i++){
       fk = fkp1;
       cin>>fkp1;
       
       /*premier test : si on se trouve à N/2 et qu'il y a deux entiers identiques qui se suivent, alors on envoie INF car tous les décimaux
       entre k et k+1 auront comme valeur associée N/2, or il y a une infinité de décimaux sur le segment [k,k+1] */
       if(fk==n/2.0 && fk==fkp1){
           cout<<"INF";
           exit(0); //on quitte le programme parce que ça ne sert à rien d'aller plus loin
       }
       
       //second test : il y a passage strict par N/2 dans un sens ou dans l'autre
       if(fk<n/2.0 && fkp1>n/2.0 || fk>n/2.0 && fkp1<n/2.0){
           s++;
       }
       
        // troisième test : si fk vaut N/2. On ne teste pas fk+1 car sinon à l'étape suivant on le conterait une seconde fois  
       if(fk == n/2.0) s++;
   }
   
   
   // on a pas testé pour voir si le dernier valait N/2, il faut le tester !
   if(fkp1==n/2.0) s++;
   
   cout<<s;
}
