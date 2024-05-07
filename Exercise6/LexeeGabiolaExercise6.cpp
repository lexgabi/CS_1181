// LexeeGabiolaExercise6.cpp : This file contains the 'main' function. Program execution begins and ends there.
// @author Lexee Gabiola
// CS 1181 - Exercise 6: Herman the Fly

#include <iostream>
#include <thread> // allows us to use sleep_for
#include <cstdlib> // allows us to use rand functions

using namespace std;

// Function to print 3D cube with location of Herman, poison and corner numbers
void printCube(string corner0, string corner1, string corner2, string corner3, string corner4, string corner5, string corner6, string corner7) {
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	cout << ("      ") << corner4 << ("--------") << corner5 << endl;
	cout << ("     /|       /|") << endl;
	cout << ("    / |      / |") << endl;
	cout << ("   ") << corner0 << ("--|-----") << corner1 << ("  |") << endl;
	cout << ("   |  ") << corner7 << ("-----|--") << corner6 << endl;
	cout << ("   | /      |  /") << endl;
	cout << ("   |/       | /") << endl;
	cout << ("   ") << corner3 << ("--------") << corner2 << endl;
}

// Return a random number from 0 to 7
int randomNum() { return rand() % 8; }

// Replace corner with Herman's location
void repositionHerman(int hermanPos, string &corner0, string &corner1, string &corner2, string &corner3, string &corner4, string &corner5, string &corner6, string &corner7) {
	if (hermanPos == 0) { corner0 = "H"; }
	else if (hermanPos == 1) { corner1 = "H"; }
	else if (hermanPos == 2) { corner2 = "H"; }
	else if (hermanPos == 3) { corner3 = "H"; }
	else if (hermanPos == 4) { corner4 = "H"; }
	else if (hermanPos == 5) { corner5 = "H"; }
	else if (hermanPos == 6) { corner6 = "H"; }
	else if (hermanPos == 7) { corner7 = "H"; }
}

// Replace corner with the poison's location
void repositionPoison(int poisonPos, string& corner0, string& corner1, string& corner2, string& corner3, string& corner4, string& corner5, string& corner6, string& corner7) {
	if (poisonPos == 0) { corner0 = "P"; }
	else if (poisonPos == 1) { corner1 = "P"; }
	else if (poisonPos == 2) { corner2 = "P"; }
	else if (poisonPos == 3) { corner3 = "P"; }
	else if (poisonPos == 4) { corner4 = "P"; }
	else if (poisonPos == 5) { corner5 = "P"; }
	else if (poisonPos == 6) { corner6 = "P"; }
	else if (poisonPos == 7) { corner7 = "P"; }
}

// Replace corner with both poison's & Herman's location, since they are the same in this case
void repositionBoth(int poisonPos, string& corner0, string& corner1, string& corner2, string& corner3, string& corner4, string& corner5, string& corner6, string& corner7) {
	if (poisonPos == 0) { corner0 = "B"; }
	else if (poisonPos == 1) { corner1 = "B"; }
	else if (poisonPos == 2) { corner2 = "B"; }
	else if (poisonPos == 3) { corner3 = "B"; }
	else if (poisonPos == 4) { corner4 = "B"; }
	else if (poisonPos == 5) { corner5 = "B"; }
	else if (poisonPos == 6) { corner6 = "B"; }
	else if (poisonPos == 7) { corner7 = "B"; }
}

//Return a random number from 0 to 2
int flipTroin() { return rand() % 3; }

// Move Herman to a new corner and replace previous corner with its number
void moveHerman(int& hermanPos, string& corner0, string& corner1, string& corner2, string& corner3, string& corner4, string& corner5, string& corner6, string& corner7) {
	int move = flipTroin();
	if (move == 0) { // move up/down
		if (hermanPos == 0) { hermanPos = 3; corner0 = "0"; }
		else if (hermanPos == 1) { hermanPos = 2; corner1 = "1"; }
		else if (hermanPos == 2) { hermanPos = 1; corner2 = "2"; }
		else if (hermanPos == 3) { hermanPos = 0; corner3 = "3"; }
		else if (hermanPos == 4) { hermanPos = 7; corner4 = "4"; }
		else if (hermanPos == 5) { hermanPos = 6; corner5 = "5"; }
		else if (hermanPos == 6) { hermanPos = 5; corner6 = "6"; }
		else if (hermanPos == 7) { hermanPos = 4; corner7 = "7"; }
	}
	else if (move == 1) { // move left
		if (hermanPos == 0) { hermanPos = 4; corner0 = "0"; }
		else if (hermanPos == 1) { hermanPos = 0; corner1 = "1"; }
		else if (hermanPos == 2) { hermanPos = 3; corner2 = "2"; }
		else if (hermanPos == 3) { hermanPos = 7; corner3 = "3"; }
		else if (hermanPos == 4) { hermanPos = 5; corner4 = "4"; }
		else if (hermanPos == 5) { hermanPos = 1; corner5 = "5"; }
		else if (hermanPos == 6) { hermanPos = 2; corner6 = "6"; }
		else if (hermanPos == 7) { hermanPos = 6; corner7 = "7"; }
	}
	else if (move == 2) { // move right
		if (hermanPos == 0) { hermanPos = 1; corner0 = "0"; }
		else if (hermanPos == 1) { hermanPos = 5; corner1 = "1"; }
		else if (hermanPos == 2) { hermanPos = 6; corner2 = "2"; }
		else if (hermanPos == 3) { hermanPos = 2; corner3 = "3"; }
		else if (hermanPos == 4) { hermanPos = 0; corner4 = "4"; }
		else if (hermanPos == 5) { hermanPos = 4; corner5 = "5"; }
		else if (hermanPos == 6) { hermanPos = 7; corner6 = "6"; }
		else if (hermanPos == 7) { hermanPos = 3; corner7 = "7"; }
	}
}

// Function to run individual Herman Simulations
int hermanSimulation() {
	int cornerCount = 0;
	string corner0 = "0", corner1 = "1", corner2 = "2", corner3 = "3", corner4 = "4", corner5 = "5", corner6 = "6", corner7 = "7";
	srand(time(0));
	int hermanPos = randomNum();
	int poisonPos = randomNum();
	cout << ("Herman's start position: ") << hermanPos << ", The poison's start position: " << poisonPos << endl;

	if (hermanPos != poisonPos) { // Prints initial location for Herman and the poison
		repositionHerman(hermanPos, corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
		repositionPoison(poisonPos, corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
		printCube(corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
		cornerCount += 1;
		cout << ("Number of Corners visited this simulation: ") << cornerCount << endl;
	}
	else { // Prints when the initial positions are equal for Herman and the poison, so Herman dies right at the start
		repositionBoth(poisonPos, corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
		printCube(corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
		cout << ("Total Number of Corners visited this simulation: ") << cornerCount << endl;
	}

	while (hermanPos != poisonPos) { // Loops to move Herman and prints each new location
		moveHerman(hermanPos, corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
		if (hermanPos == poisonPos) {
			repositionBoth(poisonPos, corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
			printCube(corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
			cout << ("Total Number of Corners visited this simulation: ") << cornerCount << endl;
		}
		else { // Prints when Herman moves to the corner with the poison and dies
			repositionHerman(hermanPos, corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
			printCube(corner0, corner1, corner2, corner3, corner4, corner5, corner6, corner7);
			cornerCount += 1;
			cout << ("Number of Corners visited this simulation: ") << cornerCount << endl;
		}
	}
	return cornerCount; // Returns how many corners were visted this simulation
}


int main() {
	int totalCorners = 0;
	printCube("0", "1", "2", "3", "4", "5", "6", "7"); // 3D Cube before fly is added
	cout << ("H = Herman, P = Poison, B = both") << endl;
	for (int i = 0; i <= 9; ++i) { // Run simulation 10 times
		totalCorners += hermanSimulation(); // Calculates the total number of corners visited during all simulations
		cout << ("Running Average Total of Corners: ") << totalCorners / (i + 1) << endl << endl; // Calulates average
	}
	cout << ("Herman The Fly's Expected Value: ") << totalCorners / 10; // Calculates total average of corners
}