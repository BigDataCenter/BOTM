#include "stdafx.h"
#include "Includes.h"
#include "Defines.h"
#include "GlobalValue.h"
#include "Structure.h"
#include "Functions.h"

int main() {
    int MODNUM  = 5;
    int MODLINK = 7;
    int VMTYPE  = 10;
    
    SimDataGenerator(100, MODNUM, MODLINK, VMTYPE);    //generate data
        
    Initial(MODNUM, MODLINK, VMTYPE);
        
    double BUDGET = VT[VMTYPE - 1].price;
        
    cout << MyAlgorithm(MODNUM, BUDGET, VMTYPE) << endl;
    
	return 0;
}
