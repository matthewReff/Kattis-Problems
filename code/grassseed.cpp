#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double cost;
	double length;
	double width;
	double total = 0;
	int lawns;
	
	cin >> cost >> lawns;
	for (int i = 0; i < lawns; i++) {
		cin >> length >> width;
		total += (cost * length * width);
	}
	cout << fixed << setprecision(10) << total;
	return 0;
}