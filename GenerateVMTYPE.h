void GenerateVMTYPE(int numVM)
{//generate VM type
    vector<double>	CPU(numVM, 0);
    vector<double> price(numVM, 0);

	for(int i = 0; i < numVM; i ++){//generate values
		CPU[i]				= VMCPUCYCLE_LOW + (rand() / (double)RAND_MAX) * (double)VMCPUCYCLE_RANGE;
		price[i]			= VMPRICE_LOW + (rand() / (double)RAND_MAX) * (double)VMPRICE_RANGE;
	}
    
	//sort values
    sort(CPU.begin(), CPU.end());
    sort(price.begin(), price.end());

	for(int i = 0; i < numVM; i ++){
		VT[i].CPU		= CPU[i];
		VT[i].price		= price[i];
	}
}
