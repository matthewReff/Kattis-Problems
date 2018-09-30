#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
	vector<int> potato;
	int num1, num2, num3, num4;
	cin >> num1 >> num2 >> num3 >> num4;
	potato.push_back(num1);
	potato.push_back(num2);
	potato.push_back(num3);
	potato.push_back(num4);
	sort(potato.begin(),potato.end());
	cout << potato[0] * potato[2];
	return 0;
}