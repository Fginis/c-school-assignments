#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	int sumofR, point;
	int d1, d2;
	int rolls;
	int winsamt, loseamt;
	//constants
	const int rollsamt = 1000;
	const int min_value = 1; //minimum die value
	const int max_value = 6; // max

	unsigned seed = time(0);
	srand(seed);
	winsamt = 0;
	loseamt = 0;
	
	cout << "rolling the dice..\n";

	for (rolls = 0; rolls < rollsamt; rolls++) {
		d1 = (rand() % (max_value - min_value + 1)) + min_value;
		d2 = (rand() % (max_value - min_value + 1)) + min_value;
		sumofR = d1 + d2;
	
		if (sumofR == 7 || sumofR == 11) {

			winsamt = winsamt + 1;
		}
		else  if (sumofR == 2 || sumofR == 3 || sumofR == 12) {

			loseamt = loseamt + 1;
		}
		else {
			point = sumofR;
			while (point != 7 && sumofR != point) {
				d1 = (rand() % (max_value - min_value + 1)) + min_value;
				d2 = (rand() % (max_value - min_value + 1)) + min_value;
			
			}
			if (sumofR= point) {
				winsamt = winsamt + 1;
			}
			else
				loseamt = loseamt + 1;
		}
	}

	cout << "Wins" << "\t" << "Losses" << "\t" << "Win percentage";

	cout << "\n" << winsamt << "\t";
	cout << loseamt << "\t";

	return 0;
}