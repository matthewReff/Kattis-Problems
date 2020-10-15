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
	int totals[5] = { 0 };
	int tempNum;
	int bestIndex;
	int best;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> tempNum;
			totals[i] += tempNum;
		}
	}
	best = totals[0];
	bestIndex = 1;
	for (int i = 1; i < 5; i++) {
		if (totals[i] > best){
			best = totals[i];
			bestIndex = i + 1;
		}
	}
	cout << bestIndex << " " << best;
	return 0;
}
