/*
* Exercise 5: Functions, Parameters, Strings
* Answers questions 3 - 9 for Exercise 5
* @author Lexee Gabiola
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
* Positive Sum function - Question 3
* This function returns the sum of positive integers from 0 to given number
* @author Lexee Gabiola
* 9/30/2022
*/
int sum = 0, n1;

int positiveSum(int n1) {
	if (n1 < 0) {
		sum = -1;
	}
	else {
		for (int i = 0; i <= n1; ++i) {
			sum += i;
		}
	}
	return sum;
}

/*
* Is Prime function - Question 4
* This function returns whether a positive long number is prime
* @author Lexee Gabiola
* 9/30/2022
*/  
long positiveNum;
bool is_prime = true;

bool isPrime(long positiveNum) {
	if (positiveNum <= 1) {
		return is_prime = false;
	}	
	else {
		for (int i = 2; i <= positiveNum / 2; ++i) {
			if (positiveNum % i == 0) {
				return is_prime = false;
				break;
			}
		}
	}
}

/*
* Count Chars function - Question 5
* This function counts the number of times a given character appears in a given string
* @author Lexee Gabiola
* 9/30/2022
*/
string s;
char c;
int char_count = 0;

int countChars(string s, char c) {
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == c) {
			char_count += 1;
		}
	}
	return char_count;
}

/*
* Sum Digits function - Question 6
* This function returns the sum of the digits in a given integer
* @author Lexee Gabiola
* 9/30/2022
*/
int n2, num_of_digits = 0, digit_sum = 0;

int sumDigits(int n2) {
	int n2_copy = n2;
	int leftover = n2;
	int current_digit;

	while (n2_copy != 0) {
		n2_copy /= 10;
		num_of_digits++;
	}

	for (int i = num_of_digits - 1; i >= 0; --i) {
		int digit_place = pow(10, i);
		current_digit = leftover / digit_place;
		leftover = leftover % digit_place;
		digit_sum += current_digit;
	}
	return digit_sum;
}

/*
* Sum Chars function - Question 7
* This function returns the sum of the ascii values of the characters between two given characters
* @author Lexee Gabiola
* 9/30/2022
*/
int char_sum = 0, current_char;
char c1, c2;

int sumChars(char c1, char c2) {
	int charToInt1 = (int)c1;
	int charToInt2 = (int)c2;
	if (charToInt1 > charToInt2) {
		current_char = charToInt2 + 1;
		while (charToInt2 < current_char && current_char < charToInt1) {
			char_sum += current_char;
			++current_char;
		}
	}
	else if (charToInt1 == charToInt2) {
		char_sum = 0;
	}
	else {
		current_char = charToInt1 + 1;
		while (charToInt1 < current_char && current_char < charToInt2) {
			char_sum += current_char;
			++current_char;
		}
	}
	return char_sum;
}

/*
* Is Leap Year function - Question 8
* This function returns whether a given year is leap year
* @author Lexee Gabiola
* 10/3/2022
*/
int year;
bool isLeapYear(int year) {
	return year % 4 == 0 && ((year % 400 == 0) || (year % 100 != 0));
}

/*
* Days In Month function - Question 9
* This function returns the number of days in a given month of a given year
* @author Lexee Gabiola
* 10/3/2022
*/
int year2, monthNum;
int daysInMonth(int year2, int monthNum) {
	switch (monthNum) {
	case 1:
		return 31;
	case 2:
		if (isLeapYear(year2)) {
			return 29;
		}
		else {
			return 28;
		}
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		return 31;
	default:
		return 0;
	}

}

/*
* Main function
* This function calls all of the above functions
* @author Lexee Gabiola
* 9/30/2022
*/

int main() {
	cout << ("Please enter an integer: ");
	cin >> n1;
	cout << ("The sum of previous integers including this number is ") << positiveSum(n1) << endl;

	cout << ("Please enter a possible prime number: ");
	cin >> positiveNum;
	isPrime(positiveNum);
	cout << ("Is it prime? ") << is_prime << endl;

	cout << ("Please enter a string: ");
	getline(cin >> ws, s);
	cout << ("Please enter a character: ");
	cin >> c;
	cout << ("The character appears in the string ") << countChars(s, c) << (" times") << endl;

	cout << ("Please enter another integer: ");
	cin >> n2;
	cout << ("The sum of the digits in the integer is ") << sumDigits(n2) << endl;

	cout << ("Please enter the first character: ");
	cin >> c1;
	cout << ("Please enter the second character: ");
	cin >> c2;
	cout << ("The sum of characters between these two characters is ") << sumChars(c1, c2) << endl;

	cout << ("Please enter a year: ");
	cin >> year;
	cout << ("Is it a leap year? ") << isLeapYear(year) << endl;

	cout << ("Please enter another year: ");
	cin >> year2;
	cout << ("Please enter a month as an integer: ");
	cin >> monthNum;
	cout << ("There are ") << daysInMonth(year2, monthNum) << (" days in this month");

	return 0;

}