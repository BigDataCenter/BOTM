void Initial(int MODNUM, int MODLINK, int VMTYPE)
{//initial all the global variables
    /*
    //test case
    V[1].complexity = 1;
    V[2].complexity = 2;
    V[3].complexity = 3;
    V[4].complexity = 2;
    
    VT[0].CPU = 1;
    VT[1].CPU = 2;
    VT[2].CPU = 4;
    VT[3].CPU = 8;
    VT[4].CPU = 16;
    
    VT[0].price = 1;
    VT[1].price = 2;
    VT[2].price = 3;
    VT[3].price = 4;
    VT[4].price = 5;
    */
    for(int i = 0; i < MODNUM; i++){
        ATYPE[i] = 0;
        V[i].num = 1;
        V[i].FT.clear();
    }
    
    double minComp = INT_MAX;
    
    for(int i = 1; i < MODNUM; i++) minComp = min(minComp, V[i].complexity);
    
    double emitGap = minComp / VT[VMTYPE - 1].CPU / 10; //use the one tenth of the shortest execution time to initialize the time gap of spout emit each tuple
    
    V[0].FT.push_back(0);
    V[0].FT.push_back(emitGap);
    updateAll(MODNUM);
}
