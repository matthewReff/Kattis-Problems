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

int main() {
	int inputs;
	int sum = 0;
	string tempString;
	string exp;
	string base;
	cin >> inputs;

	for (int i = 0; i < inputs; i++)
	{
		cin >> tempString;
		exp = tempString.substr(0, tempString.size()-1);
		base = tempString.substr(tempString.size() - 1, tempString.size());
		//cout << exp << " " << base << "\n";
		sum += pow(atoi(exp.c_str()),  atoi(base.c_str()));
	}
	cout << sum;
	return 0;
}
