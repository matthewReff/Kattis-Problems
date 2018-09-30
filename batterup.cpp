#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {
	int bats;
	int legitBats;
	int score;
	int total = 0;
	double avg;
	cin >> bats;
	legitBats = bats;
	for (int i = 0; i < bats; i++) {
		cin >> score;
		if (score >= 0) {
			total += score;
		}
		else {
			legitBats--;
		}
	}
	cout << total / double(legitBats);
	return 0;
}