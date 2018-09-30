#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int inputs[2][3];
	vector<int> potato;
	vector<int> tomato;
	for (int i = 0; i < 3; i++) {
		cin >> inputs[0][i] >> inputs[1][i];
		potato.push_back(inputs[0][i]);
		tomato.push_back(inputs[1][i]);
	}
	if (potato[0] == potato[1]) {
		cout << potato[2] << " ";
	}
	else if (potato[1] == potato[2]){
		cout << potato[0] << " ";
	}
	else {
		cout << potato[1] << " ";
	}
	if (tomato[0] == tomato[1]) {
		cout << tomato[2];
	}
	else if (tomato[1] == tomato[2]) {
		cout << tomato[0];
	}
	else {
		cout << tomato[1];
	}
	/*for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++){
			cout << inputs[i][j] << " ";
		}
	}*/
	return 0;
}