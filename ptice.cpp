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
	string a = "ABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABC";
	string b = "BABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABC";
	string c = "CCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABB";
	string correct;
	int answers;
	int max;
	int tempMax;
	int total[3] = {0,0,0};
	cin >> answers;
	cin >> correct;
	for (int i = 0; i < answers; i++) {
		if (correct[i] == a[i]) {
			total[0]++;
		}
		if (correct[i] == b[i]) {
			total[1]++;
		}
		if (correct[i] == c[i]) {
			total[2]++;
		}
	}
	tempMax = total[0];
	for (int i = 1; i < 3; i++) {
		if (total[i] > tempMax) {
			tempMax = total[i];
		}
	}
	max = tempMax;
	cout << max << endl;
	if (total[0] == max) {
		cout << "Adrian" << endl;
	}
	if (total[1] == max) {
		cout << "Bruno" << endl;
	}
	if (total[2] == max) {
		cout << "Goran" << endl;
	}
	return 0;
}
