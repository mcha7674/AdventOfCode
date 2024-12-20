#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Helpers.h"
using namespace std;

class AOC
{
public:
	AOC() {}
	virtual ~AOC() {}

	// Function Solution for each day
	virtual bool Day1()  { return false; }
	virtual bool Day2()  { return false; }
	virtual bool Day3()  { return false; }
	virtual bool Day4()  { return false; }
	virtual bool Day5()  { return false; }
	virtual bool Day6()  { return false; }
	virtual bool Day7()  { return false; }
	virtual bool Day8()  { return false; }
	virtual bool Day9()  { return false; }
	virtual bool Day10() { return false; }
	virtual bool Day11() { return false; }
	virtual bool Day12() { return false; }
	virtual bool Day13() { return false; }
	virtual bool Day14() { return false; }
	virtual bool Day15() { return false; }
	virtual bool Day16() { return false; }
	virtual bool Day17() { return false; }
	virtual bool Day18() { return false; }
	virtual bool Day19() { return false; }
	virtual bool Day20() { return false; }
	virtual bool Day21() { return false; }
	virtual bool Day22() { return false; }
	virtual bool Day23() { return false; }
	virtual bool Day24() { return false; }
	virtual bool Day25() { return false; }
	virtual bool Day26() { return false; }
	virtual bool Day27() { return false; }
	virtual bool Day28() { return false; }
	virtual bool Day29() { return false; }
	virtual bool Day30() { return false; }
	virtual bool Day31() { return false; }

	// Helper Functions
	bool Execute_Case(int day) { return false; }

private:


};

class AOC_2024: public AOC
{
public:
	AOC_2024() {}
	virtual ~AOC_2024() {}

	virtual bool Day1() override;
	virtual bool Day2() override;
	virtual bool Day3() override;
	/*virtual bool Day4() override;
	virtual bool Day5() override;
	virtual bool Day6() override;
	virtual bool Day7() override;
	virtual bool Day8() override;
	virtual bool Day9() override;
	virtual bool Day10() override;
	virtual bool Day11() override;
	virtual bool Day12() override;
	virtual bool Day13() override;
	virtual bool Day14() override;
	virtual bool Day15() override;
	virtual bool Day16() override;
	virtual bool Day17() override;
	virtual bool Day18() override;
	virtual bool Day19() override;
	virtual bool Day20() override;
	virtual bool Day21() override;
	virtual bool Day22() override;
	virtual bool Day23() override;
	virtual bool Day24() override;
	virtual bool Day25() override;
	virtual bool Day26() override;
	virtual bool Day27() override;
	virtual bool Day28() override;
	virtual bool Day29() override;
	virtual bool Day30() override;
	virtual bool Day31() override;*/

	// Load input onto an object
	template <typename T>
	bool Load_Input(string fileName, T &input, int day)
	{
		// Load FIle
		std::ifstream file(fileName); // Replace with your file name
		std::string line;
		if (file.is_open()) {}
		else {
			std::cerr << "Error opening file." << std::endl;
			return false;
		}

		// Process File Contents
		int lineNum = 1;
		switch (day)
		{
		case 1:
			// Process Each Line in the file
			while (getline(file, line)) 
			{
				// Day 1 loads to integers side by side, seperated by a space.
				// These integers are then stored within a vector where 0 + even index 
				// represents the left coloumn of ints and all odd numbers represent right 
				// column of ints. Inputs always in pairs
				istringstream iss(line);
				int locationID;
				while (iss >> locationID) {
					input.push_back(locationID);
				}
				lineNum++;
			}
			break;
		case 3:
			while (getline(file, line)) 
			{
				// Day 3 loads in characters to analyze
				istringstream iss(line);
				char c;
				std::vector<char> line;
				while (iss.get(c)) {
					input.push_back(c);
				}
				lineNum++;
			}
		default:
			break;
		}
		file.close();

		return true;
	}

	// Load input overload with a 2d input
	template <typename T>
	bool Load_Input(string fileName, std::vector<std::vector<T>>& input, int day)
	{
		// Load FIle
		std::ifstream file(fileName); // Replace with your file name
		std::string line;
		if (file.is_open()) {}
		else {
			std::cerr << "Error opening file." << std::endl;
			return false;
		}

		// Process File Contents
		int lineNum = 1;
		switch (day)
		{
		case 2:
			while (getline(file, line))
			{
				// Day 1 loads to integers side by side, seperated by a space.
				// These integers are then stored within a vector where 0 + even index 
				// represents the left coloumn of ints and all odd numbers represent right 
				// column of ints. Inputs always in pairs
				istringstream iss(line);
				int data;
				std::vector<int> line;
				while (iss >> data) {
					line.push_back(data);
				}
				input.push_back(line);
				lineNum++;
			}
		default:
			break;
		}
		file.close();

		return true;
	}

private:

};

