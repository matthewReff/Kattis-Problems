#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double num1;
	double num2;
	double area1;
	double area2;

	cin >> num1 >> num2;
	cout << fixed << setprecision(10);
	area1 = M_PI * (num1 * num1);
	area2 = M_PI * pow((num1 - num2),2);
	cout << area2 / area1 * 100;

	return 0;
}