#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <unordered_set>
using namespace std;

int main(){
	double rad;
	cin >> rad;
	cout << fixed << setprecision(10);
	cout << M_PI * pow(rad, 2) << endl;
	cout << 2 * pow(rad, 2);
	return 0;
}