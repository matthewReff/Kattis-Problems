#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int numbers;
	long long total = 0;
	vector<int> nums;
	int num;
	cin >> numbers;
	for (int i = 0; i < numbers; i++) {
		cin >> num;
		nums.push_back(num);
	}

	sort(nums.rbegin(), nums.rend());

	for (int i = 1; i <= nums.size();i++) {
		if (!(i % 3 == 0)) {
			total += nums[i - 1];
		}
	}
	//for (int i = 0; i < nums.size(); i++){
		//cout << nums[i] << " ";
	//}
	cout << total;
	return 0;
}