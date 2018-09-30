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
	int cases, i, j, k;
	int beats;
	double time;

	cin >> cases;
	for (i = 0; i < cases; i++)
	{
		cin >> beats >> time;
		cout << fixed << setprecision(4);
		cout << ((beats - 1) / time)*60 << " " 
			<< (beats / time)*60 << " " 
			<< ((beats + 1) / time)*60 << "\n";
	}
	return 0;
}


