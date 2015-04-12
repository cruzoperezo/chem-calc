//BCA Table generator for two reactants


#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>


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

	string reactants1;
	int coefR1;
	string reactants2;
	int coefR2;

	string products1;
	int coefP1;
	string products2;
	int coefP2;
	
// input
	cout << "1st reactant: ";
	cin >> reactants1;
	cout << "Coefficient of "<< reactants1 << ": ";
	cin >> coefR1;

	cout << "2nd reactant: ";
	cin >> reactants2;
	cout << "Coefficient of "<< reactants2 << ": ";
	cin >> coefR2;

	cout << "1st product: ";
	cin >> products1;
	cout << "Coefficient of "<< products1 << ": ";
	cin >> coefP1;

	cout << "2nd product: ";
	cin >> products2;
	cout << "Coefficient of "<< products2 << ": ";
	cin >> coefP2;


	cout << "Moles of "<< reactants1 << ": ";
	cin >> molesR1;

	cout << "Moles of "<< reactants2 << ": ";
	cin >> molesR2;	

// determine limniting RXN
	float limitRXN;
	float limitCOEF;
	if (molesR1 / coefR1 * coefR2 < molesR2){
		limitRXN = molesR1; 
		limitCOEF = coefR1;
	}
	else {
		limitRXN = molesR2;
		limitCOEF = coefR2;
	}

// calculate values for BCA table
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

// output
	stringstream ssheader;
  	ssheader << "   " << coefR1 << reactants1 << "    +    " << coefR2 << reactants2 << "    ----->    " << coefP1 << products1 << "    +    " << coefP2 << products2;
  	string header = ssheader.str();
  	cout << header << endl;

	int lengthHeader = header.length();
	int k = 0;
	while (k < lengthHeader){
		cout << "-";
	k++;
	}
	cout << endl;

	printf("B: %-4.4f\t %-5.4f\t\t\t %-5.4f\t\t %-5.4f\n",BR1, BR2, BP1, BP2);
	printf("C: %-5.4f\t %-5.4f\t\t %-5.4f\t\t %-5.4f\n",CR1, CR2, CP1, CP2);
	printf("A: %-5.4f\t %-5.4f\t\t\t %-5.4f\t\t %-5.4f\n",AR1, AR2, AP1, AP2);
	cout << endl;
}