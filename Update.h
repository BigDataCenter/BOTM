int GCD(int a, int b) {
    if(b) while((a %= b) && (b %= a));
    return a + b;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

bool allPreUpdated(int node, unordered_set<int>& updated){
    for(auto n : preNodes[node])
        if(updated.find(n) == updated.end()) return false;
    
    return true;
}

void update(int node){
    int M = V[node].num + 1;
    
    for(auto n : preNodes[node]) M = LCM(M, V[n].num + 1);
    
    vector<vector<double>> FTs;
    
    for(auto n : preNodes[node]){
        vector<double> v;
        double during = V[n].FT[V[n].FT.size() - 1] - V[0].FT[0];

        for(int i = 0; i < M; i++){
            int size = V[n].num + 1;
            int num = i / size;
            
            v.push_back(num * during + V[n].FT[i % size]);
        }
        
        FTs.push_back(v);
    }
    
    vector<double> preFT;
    
    for(int i = 0; i < M; i++){
        double latest = 0;
        
        for(int j = 0; j < FTs.size(); j++) latest = max(FTs[j][i], latest);
        
        preFT.push_back(latest);
    }
    
    double T = V[node].complexity / VT[ATYPE[node]].CPU;
    
    V[node].FT.clear();
    
    for(int i = 0; i < M; i++){
        if(i < V[node].num) V[node].FT.push_back(preFT[i] + T);
            
        else V[node].FT.push_back(max(preFT[i], V[node].FT[i - V[node].num]) + T);
    }
}

void updateAll(int MODNUM){
    unordered_set<int> updated;
    
    updated.insert(0);
    
    while(updated.size() != MODNUM){
        for(int i = 1; i < MODNUM; i++)
            if(updated.find(i) == updated.end() && allPreUpdated(i, updated)){
                update(i);
                updated.insert(i);
            }
    }
}
