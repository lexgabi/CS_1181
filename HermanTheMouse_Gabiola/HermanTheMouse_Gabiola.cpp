/* 
* Lexee Gabiola
* CS 1181 - Exercise 10
* 12/10/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

string file = "maze-v1.txt";

int** mazeCounter;
int startX, startY, bridge1X, bridge1Y, bridge2X, bridge2Y;
int starveCount = 0;
int drownCount = 0;
int escapeCount = 0;
bool drowned, starved, escaped;
bool alive = true;

int getRow(string mze) {
    int i = 0;
    string row = "";
    while (mze[i] != ' ') {
        row += mze[i];
        ++i;
    }
    int rowNum = stoi(row);
    return rowNum;
}

int getCol(string mze) {
    int j = (mze.find(" ")) + 1;
    string col = "";
    while (mze[j] != '\n') {
        col += mze[j];
        ++j;
    }
    int colNum = stoi(col);
    return colNum;
}

char** stringToArrayMaze(string mze, int row, int col) {
    int bridgeCount = 0;
    int count = (mze.find('\n')) + 1;
    char** mazeArray;
    mazeArray = new char* [row];
    mazeCounter = new int* [row];
    for (int i = 0; i < row; i++) {
        mazeArray[i] = new char[col - 1];
        mazeCounter[i] = new int[col - 1];
        for (int j = 0; j < col; j++) {
            if (mze[count] == '\n') {
                count++;
                //cout << endl;
            }
            else if (mze[count] == 'X') {
                startX = i;
                startY = j;
            }
            else if (mze[count] == '-' && (i == 0 || j == 0 || i == row - 1 || j == col - 1)) {
                bridgeCount += 1;
                if (bridgeCount == 1) {
                    bridge1X = i;
                    bridge1Y = j;
                }
                else if (bridgeCount == 2) {
                    bridge2X = i;
                    bridge2Y = j;
                }
            }
            mazeArray[i][j] = mze[count];
            if (mze[count] != '#') {
                mazeCounter[i][j] = 0;
            }
            count++;
            //cout << mazeArray[i][j];
        }
    }
    //cout << endl;
    return mazeArray;
}

string getMaze() {
    ifstream input1(file);
    string maze;
    if (input1.fail()) {
        cout << "failed to open " << file << endl;
        maze = "";
        return maze;
    }
    while (!input1.eof()) {
        maze += input1.get();
    }
    input1.close();
    return maze;
}

void printArrayCount(char** mze, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mze[i][j] == '#') {
                cout << mze[i][j];
            }
            else {
                if (mazeCounter[i][j] == 0) {
                    cout << mze[i][j];
                }
                else {
                    cout << mazeCounter[i][j];
                }
            }
        }
        cout << endl;
    }
}

void resetMaze(int row, int col) {
    alive = true;
    drowned = false;
    starved = false;
    escaped = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mazeCounter[i][j] >= 1) {
                mazeCounter[i][j] = 0;
            }
        }
    }
}

void moveHerman(char** array1, int posX, int posY) {
    mazeCounter[startX][startY] += 1;
    int count = 1;
    int move;
    while (alive) {
        move = (rand() % 4) + 1;
        if (move == 1) { // move up
            posX -= 1;
        }
        else if (move == 2) { // move down
            posX += 1;
        }
        else if (move == 3) { // move left
            posY -= 1;
        }
        else if (move == 4) { // move right
            posY += 1;
        }
        mazeCounter[posX][posY] += 1;
        if (array1[posX][posY] == '#') {
            drowned = true;
            cout << endl << "Drowned!" << endl;
            drownCount += 1;
            alive = false;
        }
        if ((posX == bridge1X && posY == bridge1Y) || (posX == bridge2X && posY == bridge2Y)) {
            escaped = true;
            cout << endl << "Escaped!" << endl;
            escapeCount += 1;
            alive = false;
        }
        if (count == 100) {
            starved = true;
            alive = false;
            cout << endl << "Starved!" << endl;
            starveCount += 1;
        }
        count++;
    }
}

int main()
{
    srand(time(NULL));
    string m = getMaze();
    int r = getRow(m);
    int c = getCol(m);
    char** mArray = stringToArrayMaze(m, r, c);
    cout << "First Bridge: " << bridge1X << ", " << bridge1Y << endl;
    cout << "Second Bridge:  " << bridge2X << ", " << bridge2Y << endl;
    cout << "Start position: " << startX << ", " << startY << endl;
    
    for (int i = 0; i < 5; i++) {
        moveHerman(mArray, startX, startY);
        printArrayCount(mArray, r, c);
        resetMaze(r, c);
    }

    cout << endl << "Escaped: " << escapeCount << ", Starved: " << starveCount << ", Drowned: " << drownCount << endl;
}