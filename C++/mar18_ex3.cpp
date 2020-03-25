/*******
 * Read input from cin
 * Use cout << ... to output your result to STDOUT.
 * Use cerr << ... to output debugging information to STDERR
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"
#include <map>
#include <cmath>
using namespace std;
ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int mesNotes[5];
    for(int i=0;i<5;i++)
        cin>>mesNotes[i];
    int N;
    cin>>N;
    int K;
    cin>>K;
    multimap<int,int> r;
    for(int i=0;i<N;i++)
    {
        int notes[6];
        for(int x=0;x<6;x++)
            cin>>notes[x];
        int s=0;
        for(int x=0;x<5;x++)
        {
            s+=abs(notes[x]-mesNotes[x]);
        }
        r.insert(make_pair(s,notes[5]));
    }
    
    int n=0;
    int m=0;
    multimap <int, int> :: iterator itr;
    for (itr = r.begin(); itr != r.end(); ++itr)
    {
        m+=itr->second;
        n++;
        if(n==K)
            break;
        
    }
    cout<<int(floor(m/K));
   	/* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
}