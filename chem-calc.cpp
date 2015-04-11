//BCA Table generator for two reactants


#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{

	float molesR1;
	float molesR2;

	float molesR3;
	float molesR4;


	float BR1 = 0;
	float BR2 = 0;
	float BP1 = 0;
	float BP2 = 0;

	float CR1 = 0;
	float CR2 = 0;
	float CP1 = 0;
	float CP2 = 0;

	float AR1 = 0;
	float AR2 = 0;
	float AP1 = 0;
	float AP2 = 0;


	cout << "Moles of reactant 1: ";
	cin >> molesR1;

	cout << "Moles of reactant 2: ";
	cin >> molesR2;

	string reactants1 = "C6HOCl";
	float coefR1 = 2;
	string reactants2 = "C2HLCl3";
	float coefR2 = 1;

	string products1 = "C14H9Cl5";
	float coefP1 = 0;
	string products2 = "NOH2";
	float coefP2 = 0;

// determine limniting RXN
	float limitRXN;
	float limitCOEF;
	if (molesR1 / coefR1 * coefR2 > molesR2){
		limitRXN = molesR1; 
		limitCOEF = coefR1;
	}
	else {
		limitRXN = molesR2;
		limitCOEF = coefR2;
	}

	BR1 = molesR1;
	BR2 = molesR2;

	CR1 = -1 * limitRXN / limitCOEF * coefR1;
	CR2 = -1 * limitRXN / limitCOEF * coefR2;

	CP1 = +1 * limitRXN / limitCOEF * coefP1;
	CP2 = +1 * limitRXN / limitCOEF * coefP2;


	AR1 = BR1 + CR1;
	AR2 = BR2 + CR2;	

	AP1 = BP1 + CP1;
	AP2 = BP2 + CP2;


	string balancedEquation =  reactants1 + " + " + reactants2 + " ----> " + products1 + " + " + products2 + "\n";

	int lengthBalancedEquation = balancedEquation.length();

	cout << balancedEquation;

	int k = 1;
	while (k < lengthBalancedEquation){
		cout << "-";
	k++;
	}

	printf( "BR1 :  %2.4f ",BR1);
	printf( "BR2 :  %2.4f ",BR2);
	printf( "BP1 :  %2.4f ",BP1);
	printf( "BP2 :  %2.4f ",BP2);

	cout << endl;

}