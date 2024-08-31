#include <iostream>
using namespace std;

void printBoard(char myBoard[][24], int n) {

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << myBoard[i][j];
		}
		cout << endl;
	}
}

int main()
{
	char myBoard[24][24];
	
	int n;
	cin >> n; 

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> myBoard[i][j];
		}
	}

	//printBoard(myBoard, n);

	int numOfWhite = 0;
	int numOfBlack = 0;
	
	char lastColor = 'C';
	int cons = 0;

	//rows
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++){
			if (myBoard[i][j] == 'B') {
				cons = (lastColor == 'B') ? (cons + 1) : 1;
				lastColor = 'B';
				numOfBlack++;
			}
			else {
				cons = (lastColor == 'W') ? (cons + 1) : 1;
				lastColor = 'W';
				numOfWhite++;
			}

			if (cons >= 3) {
				cout << "0";
				return 0;
			}
		}
		if (numOfWhite != numOfBlack || cons >= 3) {
			cout << "0";
			return 0;
		}
		else {
			lastColor = 'C';
			cons = 0;
			numOfBlack = 0;
			numOfWhite = 0;
		}
	}

	lastColor = 'C';
	cons = 0;
	numOfBlack = 0;
	numOfWhite = 0;


	//columns
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++) {
			if (myBoard[j][i] == 'B') { 
				cons = (lastColor == 'B') ? (cons + 1) : 1; 
				lastColor = 'B'; 
				numOfBlack++;
			}
			else {
				cons = (lastColor == 'W') ? (cons + 1) : 1;
				lastColor = 'W';
				numOfWhite++;
			}

			if (cons >= 3) {
				cout << "0";
				return 0;
			}
		}
		if (numOfWhite != numOfBlack) {
			cout << "0";
			return 0;
		}
		else {
			lastColor = 'C'; 
			cons = 0;
			numOfBlack = 0;
			numOfWhite = 0;
		}
	}

	cout << 1;

	return 0;
	
	



}

