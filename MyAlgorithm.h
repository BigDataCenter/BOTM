int getMinThroughputNode(int MODNUM){
    double minThroughput = INT_MAX;
    int targetNode = -1;
    
    for(int i = 1; i < MODNUM; i++){
        double throughput = getThroughput(i);
        
        if(throughput < minThroughput){
            minThroughput = throughput;
            targetNode = i;
        }
    }
    
    return targetNode;
}

double getMinThroughput(int MODNUM){
    double minThroughput = INT_MAX;
    
    for(int i = 1; i < MODNUM; i++) minThroughput = min(minThroughput, getThroughput(i));
    
    return minThroughput;
}

int getMostCostEffective(int MODNUM, int node, int VMTYPE, double BUDGET){
    int targetType = -1;
    int targetNum = 0;
    int curType = ATYPE[node];
    int curNum = V[node].num;
    double curThroughput = getMinThroughput(MODNUM);
    
    for(int t = curType; t < VMTYPE; t++){
        //        if(t == curType){
        //            if(V[node].num != VMNUM_MAX) V[node].num++;
        //
        //            updateAll(MODNUM);
        //
        //            double cost = getCost(MODNUM);
        //
        //            if(cost <= BUDGET){
        //                targetType = t;
        //                targetNum = V[node].num;
        //                maxCE = getMinThroughput(MODNUM) / cost;
        //            }
        //        }else{
        ATYPE[node] = t;
        
        if(t == curType){
            if(getTypeNum(MODNUM, t) < VMNUM_MAX) V[node].num = curNum + 1;
            
            else continue;
        }else V[node].num = curNum;
        
        updateAll(MODNUM);
        
        double th = getMinThroughput(MODNUM);
        
        while(V[node].num > 0){
            double cost = getCost(MODNUM);
            double th = getMinThroughput(MODNUM);
            
            if(cost <= BUDGET && th > curThroughput){
                targetType = t;
                targetNum = V[node].num;
                curThroughput = th;
            }
            
            V[node].num--;
            updateAll(MODNUM);
        }
        //        }
    }
    
    if(targetType != -1){
        ATYPE[node] = targetType;
        V[node].num = targetNum;
    }else{
        ATYPE[node] = curType;
        V[node].num = curNum;
    }
    
    return targetType;
}

double MyAlgorithm(int MODNUM, double BUDEGT, int VMTYPE){
    double ans = 0;
    
    while(getCost(MODNUM) <= BUDEGT){
        updateAll(MODNUM);
        ans = max(ans, getMinThroughput(MODNUM));
        
        //get min throughput node
        int targetNode = getMinThroughputNode(MODNUM);
        //get the most cost effective VM type for target node to update
        int targetType = getMostCostEffective(MODNUM, targetNode, VMTYPE, BUDEGT);
        //if there is no update works for the node, then jump out
        if(targetType == -1) break;
    }
    
    return ans;
}
