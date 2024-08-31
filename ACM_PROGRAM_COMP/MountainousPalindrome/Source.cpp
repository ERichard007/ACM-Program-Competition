#include <iostream>
using namespace std;

int main() {
	int lengthOfArray;
	cin >> lengthOfArray;

	int myArray[10000];
	int c = 0;

	for (int i = 0;i < lengthOfArray;i++) {
		int numToAdd;
		cin >> numToAdd;
		myArray[i] = numToAdd;
	}

	int longestMountainSubArray = 0;

	bool mountainStart = false;
	bool mountainPeak = false;
	bool mountainEnd = false;

	int randomEmptyArray[10];

	int mountainEndIndex = -1;

	for (int i = 0;i < lengthOfArray;i++) { //* 1 2 3 2 1 7 8

		if (myArray[i + 1] == randomEmptyArray[0]) {
			//cout << "NEXT IS EMPTY! at " << i+1 << endl;

			if (mountainStart == true && mountainPeak == true) {
				break;
			}
			
			if (mountainEndIndex < i) { 
				for (int i = mountainEndIndex + 1; i < lengthOfArray; i++) {
					myArray[i] = -9876;
				}
			}
			break;
		}

		if (myArray[i] < myArray[i + 1]) {
			if (mountainStart == true && mountainPeak == false) {
				continue;
			}
			else if (mountainStart == true && mountainPeak == true && mountainEnd == false){
				mountainEnd = true;

				mountainStart = false;
				mountainPeak = false;
				mountainEnd = false;

				mountainEndIndex = i; 

				continue;
			}
			else {
				mountainStart = true;
				continue;
			}
		}

		if (myArray[i] > myArray[i + 1]) {
			if (mountainStart == true && mountainPeak == true && mountainEnd == false) {
				continue;
			} 
			else if (mountainStart == true && mountainPeak == false) {
				mountainPeak = true; 
				continue;
			}
		}

		myArray[i] = -9876;
		mountainStart = false; 
		mountainPeak = false;
		mountainEnd = false;
	}

	//cout << "********" << endl;

	/*for (int i = 0;i < lengthOfArray;i++) {
		cout << myArray[i] << endl;
	}*/

	//find mountains
	int startIndex = -1;
	int endIndex = -1;
	int count = 0;

	bool mount = false;
	for (int i = 0; i < lengthOfArray;i++) { 

		if (myArray[i] != -9876) {
			startIndex = (startIndex < 1) ? i : startIndex;
			count++;
		}

		else {
			endIndex = i;
			int newArray[10000];

			for (int i = endIndex;i > startIndex;i--) {
				newArray[i] = myArray[i];
			}

			
			for (int i = startIndex; i < endIndex;i++) {
				if (newArray[i] != myArray[i]) {
					mount = false;
					break;
				}
				else {
					mount = true;
				}
			}

			if (mount == true) {
				if (count > longestMountainSubArray) {
					longestMountainSubArray = count; 
				}
			}

			startIndex = -1;  
			endIndex = -1; 
			mount = false;

		}

	}

	if (longestMountainSubArray > 0) {
		cout << longestMountainSubArray;
	}

	else {
		cout << -1;
	}

	return 0;
}