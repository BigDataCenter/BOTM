int RandNumGivenRange(int iStartNum, int iEndNum)
{//get a random number between iStartNum and iEndNum
    return iStartNum + rand() % (iEndNum - iStartNum + 1);
}

void GenerateTaskGraph(int numMods, int numModLinks) // DAG generator
{//generate module graph
	for(int i = 0; i < numMods; i ++) V[i].complexity = MODCOMPLEXITY_LOW + (rand() / (double)RAND_MAX) * (double)MODCOMPLEXITY_RANGE;
	
    vector<vector<double>> ppOutput(numMods, vector<double>(numMods, 0.00));
	int iNextRandModID				= RandNumGivenRange(1, (numMods - 1));  // first module
    int iTimes = 0;
    
	ppOutput[0][iNextRandModID]		= MODOUTPUTSIZE_LOW + (rand() / (double)RAND_MAX) * (double)MODOUTPUTSIZE_RANGE;
	E[iTimes].from					= 0;
	E[iTimes++].to					= iNextRandModID;

	for(int i = 1; i < numMods - 1; i++){
        int k = 0;
        
		for(; k < i; k++)
			if(ppOutput[k][i] != 0.00) break;
		
		if(k == i){
			int iPreRandModID			= RandNumGivenRange(0, (i - 1));
            
 			ppOutput[iPreRandModID][i]	= MODOUTPUTSIZE_LOW + (rand() / (double)RAND_MAX) * (double)MODOUTPUTSIZE_RANGE;
			E[iTimes].from				= iPreRandModID;
			E[iTimes++].to				= i;
		}

		iNextRandModID					= RandNumGivenRange((i + 1), (numMods - 1));
		ppOutput[i][iNextRandModID]		= MODOUTPUTSIZE_LOW + (rand() / (double)RAND_MAX) * (double)MODOUTPUTSIZE_RANGE;
		E[iTimes].from					= i;
		E[iTimes++].to					= iNextRandModID;
	}

    for(int i = 0; i < numModLinks - iTimes;){
		int iCurRandModID	= rand() % (numMods - 1);
        
		iNextRandModID      = (iCurRandModID + 1) + rand() % (numMods - 1 - iCurRandModID);
        
		if(ppOutput[iCurRandModID][iNextRandModID] == 0.00){
			ppOutput[iCurRandModID][iNextRandModID] = MODOUTPUTSIZE_LOW + (rand() / (double)RAND_MAX) * (double)MODOUTPUTSIZE_RANGE;
			E[iTimes+i].from						= iCurRandModID;
			E[iTimes+i++].to						= iNextRandModID;
		}
	}
    
    for(int i = 0; i < numModLinks; i++) preNodes[E[i].to].push_back(E[i].from);
    
    //for(int i = 0; i < numModLinks; i++) postNodes[E[i].from].push_back(E[i].to);
}
