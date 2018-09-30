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
	long long num;
	vector<long long> nums;
	int totalSets;
	int set;
	bool found;
	cin >> totalSets;
	for (int i = 0; i < totalSets; i++){
		cin >> set;
		for (int j = 0; j < set; j++){
			cin >> num;
			nums.push_back(num);
		}
		found = false;
		sort(nums.begin(), nums.end());
		for (int j = 0; j < nums.size() / 2; j++){
			if (nums[2 * j] != nums[2 * j + 1]){
				cout << "Case #" << i + 1 << ": " << nums[2 * j] << endl;
				found = true;
				break;
			}
		}
		if (!found){
			cout << "Case #" << i + 1 << ": " << nums[nums.size()-1] << endl;
		}
		nums.erase(nums.begin(), nums.end());
	}
	return 0;
}