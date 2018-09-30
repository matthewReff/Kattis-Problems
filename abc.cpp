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
	int num;
	vector<int> nums;
	string display;
	for (int i = 0; i < 3; i++){
		cin >> num;
		nums.push_back(num);
	}
	cin >> display;
	sort(nums.begin(), nums.end());
	for (unsigned int i = 0; i < 3; i++){
		if (display.at(i) == 'A'){
			cout << nums[0] << " ";
		}
		else if (display.at(i) == 'B'){
			cout << nums[1] << " ";
		}
		else{
			cout << nums[2] << " ";
		}
	}
	/*
	int nums[3];
	int numA;
	int numB;
	int numC;
	string string1;

	cin >> nums[0] >> nums[1] >> nums[2] >> string1;
	for (int i = 0; i < string1.length(); i++){
		if (string1.at(i) == 'A'){
			numA = nums[i];
		}
		else if (string1.at(i) == 'B'){
			numB = nums[i];
		}
		else{
			numC = nums[i];
		}
	}
	cout << numA << " " << numB << " " << numC;
	*/
	return 0;
}