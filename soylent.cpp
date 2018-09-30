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
	int sets;
	double tempValue;
	cin >> sets;
	for (int i = 0; i < sets; i++) {
		cin >> tempValue;
		cout << ceil(tempValue / 400) << endl;
	}
	return 0;
}
