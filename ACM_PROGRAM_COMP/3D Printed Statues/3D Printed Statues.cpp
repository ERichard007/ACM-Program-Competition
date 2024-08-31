#include <iostream>
using namespace std;

int main()
{
	int n; // statues I need to print;
	cin >> n;

	int day = 1;
	int printers = 1;

	while (printers < n) {
		day++;
		printers = 2 * printers;
	}

	cout << (day);
	return 0;
}

