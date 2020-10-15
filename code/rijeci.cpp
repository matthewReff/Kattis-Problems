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
	
	int presses;
	vector<int> fib = { 0, 1 };

	cin >> presses;

	while (fib.size() < presses + 1)
	{
		fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
	}

	cout << fib[presses - 1] << " " << fib[presses];
	return 0;
}