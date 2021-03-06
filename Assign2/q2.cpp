#include <iostream>

using namespace std;

// Two functions used to compute change and display number of coins
void computeCoin(int coinValue, int& number, int& amountLeft);
void printOutput(int coinValue, int number);

int main() {
	// initialize variables needed for calculations
	char compute_again = 'N';
	int number = 0,
	    amountLeft = 0;
	
	// prompt user to input change, check validity, and they display coins.
	// Uses a do while loop to allow multiple change calculations
	do {
		cout << "Enter the amount of change:";
		cin  >> amountLeft;
		while (amountLeft < 1 || amountLeft > 99) {
			cout << "Enter a value between 1 and 99:";
			cin  >> amountLeft;
		}

		cout << "Change can be given as:" << endl;
		computeCoin(25,number,amountLeft);
		printOutput(25,number);
		computeCoin(10,number,amountLeft);
		printOutput(10,number);
		computeCoin(1,number,amountLeft);
		printOutput(1,number);

		cout << "Do you want to make change again?" << endl
		     << "Enter Y to convert again and any other key to exit:";
		cin  >> compute_again;

	} while(compute_again == 'Y' || compute_again == 'y');


	return 0;
}

void computeCoin(int coinValue, int& number, int& amountLeft) {
	number = amountLeft/coinValue;
	amountLeft = amountLeft%coinValue;
}

void printOutput(int coinValue, int number) {
	cout << number;
	switch (coinValue)
	{
	case 25:
		cout << " Quarters\n";
		break;
	case 10:
		cout << " Dimes\n";
		break;
	case 1:
		cout << " Pennies\n";
	default:
		break;
	};
}
