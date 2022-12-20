#include <iostream>

// #include "nutri.h"
#include "formula.h"
#include "fertilizer.h"



int main()
{
	using namespace std;

	int i;

	char * gf;
	int  *  n;

    char formula[100];
    int   numbers[17];

    gf = get_formula();
	for(i=0;i<100;i++) formula[i] = * (gf + i);

	cout<< "Trying to caculate..."<<endl;
	
    n = count_formula(formula);
    for(i=0;i<17;i++)  numbers[i] = * ( n + i);

    for(i=0;i<17;i++) {cout<< numbers[i] << "\n" ;}

    return 0;
};