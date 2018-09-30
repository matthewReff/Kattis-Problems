#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
	vector<double> prices;
	int p, a, b, c, d, n;
	//double temp;
	cin >> p >> a >> b >> c >> d >> n;
	for (int i = 1; i <= n; i++) {
		prices.push_back(p*(sin(a * i + b) + cos(c * i + d) + 2));
	}
	double bigSoFar = prices[0];
	double smallSoFar = prices[0];
	double bigDiff = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > bigSoFar) {
			bigSoFar = prices[i];
			smallSoFar = prices[i];
		}
		else if(prices[i] > smallSoFar){
		}
		else {
			smallSoFar = prices[i];
			if ((bigSoFar - smallSoFar) > bigDiff) {
				bigDiff = bigSoFar - smallSoFar;
			}
		}
		
		//cout << prices[i] << " ";
		//cout << bigDiff << endl;
	}
	cout << fixed << setprecision(10);
	cout << bigDiff << endl;
	//for (int i = 0; i < prices.size(); i++) {
	//	cout << prices[i] << " ";
//	}
	//cout <<  *max_element(prices.begin(), prices.end()) - *min_element(prices.begin(), prices.end());
	return 0;
}