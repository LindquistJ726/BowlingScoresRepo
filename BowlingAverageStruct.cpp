//Program: Bowling Scores (With Structure)
//Programmer: Joshua Lindquist
//Description: This program will take the names of 10 bowlers, 5 of their scores, and then average them out.
//The program will put this information into a structure and then print out the bowlers name, their scores, and the average.

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cwctype>
using namespace std;

//Creating the Struct and its member variables
struct BowlersInfo
{
	string name {};
	int bowlerscores{};
	float avg{};

}BI_Names[10],BI_Scores[10][5],BI_Avg[10];

//Constant global variables
const int rows = 10, column = 5;

bool GetBowlingData(string _filename) {
	//Opening the file
	std::ifstream iFile;
    iFile.open(_filename);
	//checking the file
    if (!iFile)
    {
        std::cout << "Error with file name.." << endl;
        return false;
    }
	//Entering the data into the structure
	int rowI = 0;
	//I want to say thank you for the example after the last assignment, I struggled alot with getting the data into the array then and I understand it alot better now. 
	//The "iFile >> " command that was in the example made alot more sense than my original attempt and with it I was able to properly load it into the structure/arrays and use it in other functions this time.
	while (!iFile.eof() && rowI < rows)
	{
		iFile >> BI_Names[rowI].name;
		for (int colI = 0; colI < column; colI++)
		{
			iFile >> BI_Scores[rowI][colI].bowlerscores;
		}
		rowI++;
	}
	iFile.close();
	return true;
}
void GetAverageScore()
{
	//The loop for averaging the scores and entering them into the structure
	for (int rowI = 0; rowI < rows; rowI++)
	{
		int total = 0;
		for (int colI = 0; colI < column; colI++)
		{
			total += BI_Scores[rowI][colI].bowlerscores;
		}
		//Entering the average score into the structure
		BI_Avg[rowI].avg = (total / column);
	}
}
void PrettyPrintResults()
{
	//Loop for printing out the data
	for (int rowI = 0; rowI < rows; rowI++)
	{
		//Printing the names from the structure
		cout << "The Bowler " << BI_Names[rowI].name << " bowled five games with the scores of: ";
		for (int colI = 0; colI < column; colI++)
		{
			//Printing the scores from the structure
			cout << BI_Scores[rowI][colI].bowlerscores << " ";
		}
		//Printing the average from the structure

		cout << " with an average of: " << BI_Avg[rowI].avg << "   " << endl;
		
	}
	
	}
int main(int argc, char* argv[]) {
	if (argc < 2)
	{
		std::cout << "Error with input.." << endl;
		return 1;
	}


	//Calling functions
	if (!GetBowlingData(argv[1])) {
		cout << "Error with input.." << endl;
		return 0;
	}
	GetAverageScore();
	PrettyPrintResults();
	return 0;
}