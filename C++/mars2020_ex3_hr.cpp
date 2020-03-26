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
#include <iterator>

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}


int heure(int h){
    return (int)(h/100);
}

int min(int h){
    return h-100*heure(h);
}


int add(int h){
    if( min(h) > 0) h = 100*(heure(h)+1)+((min(h)+59)%60);
    else return h+59;
}

void ContestExerciseImpl::main() {
    
    int n;
    cin>>n;
    
    multimap<int,int> m[7];
    int jour,a,b,c,d;
    
    for(int i=0; i<7; i++){
        m[i].insert(make_pair(799,800));
        m[i].insert(make_pair(1800,1800));
    }
    
    for(int i=0; i<n; i++){
        cin>>jour;
        cin>>a>>b;
        m[jour-1].insert(make_pair(100*a+b,100*a+b+60));
        cin>>a>>b;
        m[jour-1].insert(make_pair(100*a+b,100*a+b+60));
    }
    for(int i=0;i<7;i++){
        for(int j=800; j<1700; j++){
            cerr<<"j = "<<j<<endl;
            if(m[i].find(j) == m[i].end()){
                m[i].insert(make_pair(j,add(j)));
                cerr<<add(j)<<" "<<m[i].upper_bound(j)->first<<endl;
                if(add(j) < m[i].upper_bound(j)->first){
                    cout<<(i+1)<<" "<<heure(j)<<":"<<min(j)<<"-"<<heure(add(j))<<":"<<min(add(j));
                    exit(0);
                }
                m[i].erase(m[i].find(j));
            }
        }
        /*
        for(auto it = m[i].begin(); it != m[i].end(); ++it){
            if( min(it->second) > 0) c=100*(heure(it->second)+1)+((it->second+59)%60);
            if( m[i].upper_bound(it->second) != m[i].end() && c < (m[i].upper_bound(it->second))->first){
                
                
                
                cout<<(i+1)<<" "<<heure(it->second)<<":"<<min(it->second)<<"-"<<heure(c)<<":"<<min(c);
                exit(0);
                
            }
        }
        */
    }
    
    
    
    
    
}
