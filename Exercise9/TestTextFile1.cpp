
#include <iostream>
#include "TextFile1.h"
#include "TextFile1.cpp"
#include "LexeeGabiolaEx9.cpp"

using std::cout;
using std::endl;

int main() {
	TextFile1 *tf1 = new TextFile1("TextFile1.txt");
	tf1->fileString = "this is a test. This is only a test.";
	tf1->writeTextFileString();
    delete tf1;

	MagicDecoderRing ring1;
	char currentChar = ring1.encodeChar('x', '1');

	char currentCodedChar = ring1.decodeChar(currentChar, '1');

	string encodedString = ring1.encodeString("TextFile1.txt", "KeyText.txt");

	string decodedString = ring1.decodeString(encodedString, keyString);

	TextFile1 *tf = new TextFile1("KeyText.txt");
	int x = tf->getTextFileString();
	cout << "return code: " << x << endl;
	cout << tf->fileString << endl;
	delete tf;
}
