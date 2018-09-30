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
	int sets;
	int row, col;
	int counter = 1;
	vector<string> original;
	vector<string> fin;
	string tempString;
	string constString;
	cin >> sets;
	for (int i = 0; i < sets; i++) {
		cin >> row >> col;
		fin.resize(row);
		for (int j = 0; j < row;j++) {
			//cin >> tempString;
			fin[j].resize(col);
			//cout << fin[j].size() << " ";
			cin >> tempString;
			original.push_back(tempString);
		}
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++){
				//cout << j << " " << k << " ";
				//cout << endl << row - 1 - j << " " << col - 1 - k << " " << endl;
				fin[row - 1 -j][col - 1 - k] = original[j][k];
			}
		}
		cout << "Test " << counter << endl;
		counter++;
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				cout << fin[j][k];
			}
			cout << endl;
		}
		original.erase(original.begin(), original.end());
		fin.erase(fin.begin(), fin.end());
	}
	return 0;
}
