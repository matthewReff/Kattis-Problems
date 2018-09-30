#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
	ll i, j, k, l;
	
	int trackNum = 1;
	int num1 = 0;
	int maxSoFar;
	int minSoFar;
	int num2;
	while (cin >> num1) {
		maxSoFar = -10000000;
		minSoFar = 10000000;
		for (int i = 0; i < num1; i++) {
			cin >> num2;
			if (num2 > maxSoFar) {
				maxSoFar = num2;
			}
			if (num2 < minSoFar) {
				minSoFar = num2;
			}
		}
		cout << "Case " << trackNum << ": " <<	minSoFar << " " << maxSoFar << " " << (maxSoFar - minSoFar) << endl;
		trackNum++;
	}
	
	return 0;
}