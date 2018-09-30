#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

using namespace std;

int main() 
{
	int problems, i;
	int found;
	string problem;



	cin >> problems;
	for (i = 0; i < problems; i++)
	{
		cin >> problem;
		if (problem == "P=NP")
		{
			cout << "skipped\n";
		}
		else
		{
			found = problem.find("+");
			cout << stoi(problem.substr(0,found)) + 
				stoi(problem.substr(found, int(problem.length()))) << "\n";
		}

	}
	return 0;
}


