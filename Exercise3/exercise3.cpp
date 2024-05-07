/*
* Roman Numeral Converter September 9th
* converts base 10 positive integer > 0 < 4000 to roman numerals
* @author Lexee Gabiola
*/

#include <iostream>

using namespace std;

int main() {
	int thousands, hundreds, tens, ones;
	int inputNum, residualNum;

	cout << "Please enter a positive integer <= 3999: ";
	cin >> inputNum;

	if (inputNum <= 0 || inputNum >= 4000) {
		cout << "That input was not correct";
	}
	else {

		// thousands digit
		residualNum = inputNum;

		thousands = residualNum / 1000;
		residualNum = residualNum % 1000;

		if (thousands == 3) {
			cout << "MMM";
		}
		else if (thousands == 2) {
			cout << "MM";
		}
		else if (thousands == 1) {
			cout << "M";
		}

		// hundreds digit
		hundreds = residualNum / 100;
		residualNum = residualNum % 100;

		if (hundreds == 1) {
			cout << "C";
		}
		else if (hundreds == 2) {
			cout << "CC";
		}
		else if (hundreds == 3) {
			cout << "CCC";
		}
		else if (hundreds == 4) {
			cout << "CD";
		}
		else if (hundreds == 5) {
			cout << "D";
		}
		else if (hundreds == 6) {
			cout << "DC";
		}
		else if (hundreds == 7) {
			cout << "DCC";
		}
		else if (hundreds == 8) {
			cout << "DCCC";
		}
		else if (hundreds == 9) {
			cout << "CM";
		}

		// tens digit
		tens = residualNum / 10;
		residualNum = residualNum % 10;

		if (tens == 1) {
			cout << "X";
		}
		else if (tens == 2) {
			cout << "XX";
		}
		else if (tens == 3) {
			cout << "XXX";
		}
		else if (tens == 4) {
			cout << "XL";
		}
		else if (tens == 5) {
			cout << "L";
		}
		else if (tens == 6) {
			cout << "LX";
		}
		else if (tens == 7) {
			cout << "LXX";
		}
		else if (tens == 8) {
			cout << "LXXX";
		}
		else if (tens == 9) {
			cout << "XC";
		}

		// ones digit
		ones = residualNum;

		if (ones == 1) {
			cout << "I";
		}
		else if (ones == 2) {
			cout << "II";
		}
		else if (ones == 3) {
			cout << "III";
		}
		else if (ones == 4) {
			cout << "IV";
		}
		else if (ones == 5) {
			cout << "V";
		}
		else if (ones == 6) {
			cout << "VI";
		}
		else if (ones == 7) {
			cout << "VII";
		}
		else if (ones == 8) {
			cout << "VIII";
		}
		else if (ones == 9) {
			cout << "IX";
		}

	}
}