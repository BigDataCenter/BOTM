double getThroughput(int node){
    return (V[node].FT.size() - 1) / (V[node].FT[V[node].FT.size() - 1] - V[node].FT[0]);
}

double getNodeCost(int node){
    return V[node].num * VT[ATYPE[node]].price;
}

double getAllCost(int MODNUM){
    double cost = 0;
    
    for(int i = 0; i < MODNUM; i++) cost += getNodeCost(i);
    
    return cost;
}

double getCost(int MODNUM){
    double cost = getNodeCost(0);
    
    for(int i = 1; i < MODNUM; i++){
        bool tag = false;
        
        for(auto preNode : preNodes[i]){
            if(ATYPE[preNode] == ATYPE[i] && V[preNode].num == V[i].num){
                tag = true;
                break;
            }
        }
        
        if(tag) continue;
        
        cost += getNodeCost(i);
    }
    
    return cost;
}

int getTypeNum(int MODNUM, int type){
    int num = 0;
    
    for(int i = 0; i < MODNUM; i++) num += ATYPE[i] == type ? V[i].num : 0;
    
    return num;
}

void CalculateSTD(double* A, int n, double* mean, double* std)
{
    int i;
    
    *mean = 0;
    *std = 0;
    
    for(i = 0; i < n; i++) *mean += A[i];
    
    *mean /= n;
    
    for(i = 0; i < n; i++) *std += (A[i] - *mean)*(A[i] - *mean);
    
    *std /= n - 1;
    *std = sqrt(*std);
}
