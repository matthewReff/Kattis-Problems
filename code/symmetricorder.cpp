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
	int counter = 0;
	int data;
	string tempString;
	vector<string> strings;
	while (cin >> data && data != 0) {
		for (int i = 0; i < data; i++) {
			cin >> tempString;
			strings.push_back(tempString);
		}
		cout << "SET " << counter + 1 << endl;
		for (unsigned int i = 0; i < strings.size();i++) {
			if (i % 2 == 0) {
				cout << strings[i] << endl;
			}
		}
		if (data % 2 == 1) {
			for (unsigned int i = 0; i < strings.size();i++) {
				if (i % 2 == 1) {
					cout << strings[strings.size() - 1 - i] << endl;
				}
			}
		}
		else {
			for (unsigned int i = 0; i < strings.size();i++) {
				if (i % 2 == 1) {
					cout << strings[strings.size() - i] << endl;
				}
			}
		}
			counter++;
			strings.erase(strings.begin(),strings.end());
		}
		
	return 0;
}