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
	long long i, j, k;
	int currentPlayer;
	int questions;
	int time;
	int currentTime = 0;
	int explodeTime = 210;
	string answer;
	bool exploded = false;
	cin >> currentPlayer >> questions;

	currentPlayer--;
	i = 0;
	while(i < questions && !exploded)
	{
		cin >> time >> answer;
		currentTime += time;
		if (currentTime >= explodeTime)
		{
			cout << ((currentPlayer % 8) + 1 );
			exploded = true;
		}
		if (answer == "T")
		{
			currentPlayer++;
		}
		i++;
	}
	return 0;
}