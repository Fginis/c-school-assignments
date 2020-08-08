
//SPRING 2019
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

 const unsigned int whiteball_MAX = 69;
const unsigned int powerball_MAX = 26;
int displayball[6];
int whiteballarr[whiteball_MAX];
int powerballarr[powerball_MAX];
// fills array with whiteball and powerball values
void fillarr();
//swaps array values with  random values.
void swapball();
//displays the values 
void generatedisplayballs();
void bubblesort(int a[], int n);
int main() {
	int x;
	srand(time(NULL));
	cout << "Please enter the number of games played:";
	cin >> x;
	for (int j = 0; j < x; j++) {
		fillarr();
		generatedisplayballs();
		swapball();
		bubblesort(displayball, 5);
		cout << "whiteballs: " <<"\t" << displayball[0] << "\t" << displayball[1] << "\t" << displayball[2] << "\t" << displayball[3] <<
			"\t" << displayball[4] <<"\t"<< "powerball: " << displayball[5];
		cout << "\n";
	}
	return 0;
}

	void fillarr() {
		for (int i = 0; i < whiteball_MAX; i++) {
			whiteballarr[i] = i + 1;
		}
		for (int i = 0; i < powerball_MAX; i++) {
			powerballarr[i] = i + 1;
		}
	}

	void swapball() {
		for (int i = 0; i < whiteball_MAX; i++) {
			int temp = whiteballarr[i];
			int randball = rand() % whiteball_MAX;

			whiteballarr[i] = whiteballarr[randball];
			whiteballarr[randball] = temp;
		}
		for (int i = 0; i < powerball_MAX; i++) {
			int temp = powerballarr[i];
			int randball = rand() % powerball_MAX;

			powerballarr[i] = powerballarr[randball];
			powerballarr[randball] = temp;
		}
	}

	void generatedisplayballs() {
		swapball();
		for (int i = 0; i < 5; i++) {
			displayball[i] = whiteballarr[i];

		}
		displayball[5] = powerballarr[1];
	}

	void bubblesort(int a[], int n) {
		int k, i, temp, flag;
		for (k = 1; k < n; k++) {
			flag = 0;
			for (i = 0; i < n - k; i++) {
				if (a[i] > a[i + 1]) {

					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
					flag = 1;
				}

			}
			if (flag == 0)
				break;
		}
	}
	
