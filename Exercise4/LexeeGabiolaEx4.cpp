#include <iostream>
using namespace std;

int main() {
	int i, integer, sum1 = 1, n1 = 1, n2 = 1, temp;
	cout << ("Please enter a positive integer: ");
	cin >> integer;
	if (integer < 0) {
		cout << ("Error: invald integer entered");
	}

	for (i = 2; i <= integer; i++) {
		sum1 += n2;
		temp = n1 + n2;
		n1 = n2;
		n2 = temp;
	}
	cout << "Fibonacci Sequence sum: " << sum1 << endl;

	int j = 0, sum2 = 0;
	while (j <= integer) {
		int k = 0;
		while (k <= integer) {
			sum2 += k + j;
			k++;
		}
		j++;
	}
	cout << "Double Nested sum: " << sum2 << endl;
	cout << endl;

	int n = 5, col_lim = 1;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < col_lim; col++) {
			cout << "*";
		}
		cout << endl;
		col_lim += 1;
	}
	cout << endl;

	int dash_lim = 4, splat_lim = 1;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < dash_lim; col++) {
			cout << "-";
		}
		for (int col = 0; col < splat_lim; col++) {
			cout << "*";
		}
		splat_lim += 1;
		dash_lim -= 1;
		cout << endl;
	}
	
	cout << endl;

	int new_n;
	cout << ("Please enter another positive integer: ") << endl;
	cin >> new_n;
	if (new_n < 0 || new_n > 26) {
		cout << ("Error: invald integer entered");
	}
	else {
		cout << "Alphabet string: ";
		for (i = 0; i < new_n; i++) {
			cout << (char)((int)'a' + i);
		}
	}

}
