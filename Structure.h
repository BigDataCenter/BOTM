struct Fvertex
{//define data structure and declare global variable for modules' nodes
    int num;            //number of VT used on the module
	double complexity;  //time complexity of the module
    vector<double> FT;  //finishing time of each tuple in one cycle
}V[MODNUM_MAX];

struct Fedge
{//define data structure and declare global variable for modules' edges
	int from;
	int to;
}E[MODLINK_MAX];

struct VTY
{//define data structure and declare global variable for VM type
	double CPU;
	double price;
}VT[VMTYPE_MAX];
