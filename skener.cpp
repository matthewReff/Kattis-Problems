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
	int num1, num2, num3, num4;
	vector<string> smallChar;
	vector<string> bigChar;
	string tempString;
	cin >> num1 >> num2 >> num3 >> num4;
	//cout << num1 << " " << num2 << " " << num3 << " " << num4;
	for (int i = 0; i < num1; i++) {
		cin >> tempString;
		smallChar.push_back(tempString);
	}
	tempString = "";
	//cout << smallChar[1][0];
	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++) {
			for (int k = 0; k < num4; k++){
				//cout << i << " " << j << " ";
				tempString += smallChar[i][j];
				//cout << smallChar[i][j] << " ";
			}
		}
		bigChar.push_back(tempString);
		tempString = "";
	}
	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num3; j++) {
		//for (int j = 0; j < num2; j++) {
			//cout << smallChar[i] << endl;
		//	}
		cout << bigChar[i] << endl;
		}
	}
	return 0;
}
