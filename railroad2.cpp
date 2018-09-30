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
	int num1, num2;
	cin >> num1 >> num2;
	if (num2 % 2 == 0)
	{
		cout << "possible";
	}
	else
	{
		cout << "impossible";
	}
	return 0;
}
