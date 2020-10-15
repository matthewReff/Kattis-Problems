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
	double num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	if (num1 + num2 == num3)
	{
		cout << num1 << "+" << num2 << "=" << num3 << "\n";
		return 0;
	}
	if (num1 - num2 == num3)
	{
		cout << num1 << "-" << num2 << "=" << num3 << "\n";
		return 0;
	}
	if (num1 * num2 == num3)
	{
		cout << num1 << "*" << num2 << "=" << num3 << "\n";
		return 0;
	}
	if (num1 / num2 == num3)
	{
		cout << num1 << "/" << num2 << "=" << num3 << "\n";
		return 0;
	}
	if (num1 == num2 + num3)
	{
		cout << num1 << "=" << num2 << "+" << num3 << "\n";
		return 0;
	}
	if (num1 == num2 - num3)
	{
		cout << num1 << "=" << num2 << "-" << num3 << "\n";
		return 0;
	}
	if (num1 == num2 * num3)
	{
		cout << num1 << "=" << num2 << "*" << num3 << "\n";
		return 0;
	}
	if (num1 == num2 / num3)
	{
		cout << num1 << "=" << num2 << "/" << num3 << "\n";
		return 0;
	}
	return 0;
}
