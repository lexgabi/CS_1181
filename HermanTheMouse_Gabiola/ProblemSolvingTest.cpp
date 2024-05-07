#include <iostream>

using namespace std;

int main() {

	int n = 10;
	cout << n < endl;
	int m = n % 3;
	cout << m < endl;
	n = m / 5;
	m = n * n;
	m = m + m;
	m = n - m;
	cout << n < endl;
	cout << m < endl;
}
