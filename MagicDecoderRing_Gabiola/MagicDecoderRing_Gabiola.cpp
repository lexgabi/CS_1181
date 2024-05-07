/*
* Lexee Gabiola
* CS 1181 - Exercise 9
* 11/29/2022
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MagicDecoderRing {
public:
    string keyString;
    string clearText;

    // This function encodes a single character
    char encodeChar(char clear, char key) {
        char coded = (clear - key + 256) % 256;
        return coded;
    }

    // This function decodes a single character
    char decodeChar(char key, char code) {
        char decoded = (key + code) % 256;
        return decoded;
    }

    // This function calls a function to encode an entire string by iterating through characters
    string encodeStr(string sA, string sB) {
        string encoded = "";
        for (int i = 0; i < sA.length() && i < sB.length(); ++i) {
            encoded += encodeChar(sA.at(i), sB.at(i));
        }
        ofstream EncodedFile("EncodedFile.txt");
        EncodedFile << encoded;
        EncodedFile.close();

        return encoded;
    }

    // This function calls a function to decode an entire string by iterating through characters
    string decodeStr(string sA, string sB) {
        string decoded = "";
        for (int i = 0; i < sA.length() && i < sB.length(); ++i) {
            decoded += decodeChar(sA.at(i), sB.at(i));
        }
        return decoded;
    }

    // This function reads a file in order to convert it to a usable string
    string getClearText() {
        ifstream input1("ClearText.txt");
        if (input1.fail()) {
            std::cout << "failed to open " << "ClearText.txt" << std::endl;
            clearText = "";
            return clearText;
        }
        while (!input1.eof())
            clearText += input1.get();
        input1.close();
        return clearText;
    }

    // This function reads a different file in order to convert it to a usable string
    string getKeyString() {
        ifstream input1("KeyText.txt");
        if (input1.fail()) {
            std::cout << "failed to open " << "KeyText.txt" << std::endl;
            keyString = "";
            return keyString;
        }
        while (!input1.eof())
            keyString += input1.get();
        input1.close();
        return keyString;
    }
};

// This function shows that the above class functions work
int main()
{
    MagicDecoderRing ring;

    string s1 = ring.getClearText();
    string s2 = ring.getKeyString();
    string s3 = ring.encodeStr(s1, s2);
    cout << s1 << endl << endl;
    cout << s2 << endl << endl;
    cout << s3 << endl << endl;

    cout << ring.decodeStr(s2, s3) << endl;

    return 0;
}