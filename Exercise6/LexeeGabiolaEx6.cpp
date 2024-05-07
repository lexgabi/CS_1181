#include <iostream>
#include <thread>

using std::cout;
using std::flush;

/*int main()
{
	for (int i = 0; i < 10; i++) {
		cout << "X" << flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}*/

int main() {

	cout << ("   4--------5");
	cout << ("  /|       /|");
	cout << (" / |      / |");
	cout << ("0--|-----1  |");
	cout << ("|  7-----|--6");
	cout << ("| /      |  /");
	cout << ("|/       | /");
	cout << ("3--------2");
}