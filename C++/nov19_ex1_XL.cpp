void ContestExerciseImpl::main() {
    int n;
    cin >> n;
    cin.ignore();
    
    int max = 100000000;
    string nom;
    
    for(int i=0;i<n;i++){
        string s;
        int j;
        cin >> s >> j;
        cin.ignore();
        if(j<max){
            max = j;
            nom = s;
        }
    }
    
    cout << nom;
}