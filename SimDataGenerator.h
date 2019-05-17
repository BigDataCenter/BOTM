void SimDataGenerator(int times, int MODNUM, int MODLINK, int VMTYPE)
{//generate modules, VM type, BW type and clouds
    vector<double>	CPU(CLOUDNUM, 0);
    vector<double> IO(CLOUDNUM, 0);
    vector<double> storage(CLOUDNUM, 0);
    vector<double> trans(CLOUDNUM, 0);

    time_t t;
    srand((unsigned) time(&t)*times);
    
	GenerateTaskGraph(MODNUM, MODLINK);
	GenerateVMTYPE(VMTYPE);
}
