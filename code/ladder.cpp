#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	double height;
	double degrees;
	double radians;
	cin >> height >> degrees;
	radians = (M_PI / 180) * degrees;
	cout << ceil(height / sin(radians));
	return 0;
}