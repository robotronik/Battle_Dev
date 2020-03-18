void ContestExerciseImpl::main() {
    int planche[4];
    cin >> planche[0];
    cin >> planche[1];
    cin >> planche[2];
    cin >> planche[3];
    
    int petit = min(min(planche[0],planche[1]),min(planche[2],planche[3]));
    int res = 0;
    for(int i = 0; i<4;i++){
        res += planche[i] - petit;
    }
    
    cout << res;
}