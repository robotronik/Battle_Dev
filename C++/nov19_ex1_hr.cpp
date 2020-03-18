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
   int min=65535, i, m,n;
   string nom, nommin;
   cin>>n;
   
   for(i=0; i<n; i++){
       cin>>nom>>m;
       if(m<min){
           min = m;
           nommin = nom;
       }
   }
   
   cout<<nommin;
	/* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}