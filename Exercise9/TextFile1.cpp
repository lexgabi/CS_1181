
#include <string>
#include <fstream>
#include <iostream>
#include "TextFile1.h"


int TextFile1::getTextFileString() {
        std::ifstream input1("TextFile1.txt");
        if (input1.fail()) {
                std::cout << "failed to open " << "TextFile1.txt" << std::endl;
                fileString = "";
                return -1;
        }
        while (!input1.eof())
                fileString += input1.get();
        input1.close();
        return 0;
}

int TextFile1::writeTextFileString() {
        std::ofstream output2(fileName, std::ios::app);
        if (output2.fail()) {
                std::cout << "Failed to write to " << fileName << std::endl;
                return -1;
        }
        for (unsigned int i = 0; i < fileString.length(); i++)
                output2.put(fileString.at(i));
        output2.close();
        return 0;
}
