#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	int inputs;
	char message[100][100];
	char outMessage[100][100];
	int bounds;
	string inputString;
	cin >> inputs;
	for (int i = 0; i < inputs; i++){
		cin >> inputString;
		for (int j = 0; j < 100; j++){
			for (int k = 0; k < 100; k++){
				message[j][k] = '*';
			}
		}
		bounds = ceil(sqrt(inputString.length()));

		int index = 0;
		for (int j = 0; j < bounds; j++){
			for (int k = 0; k < bounds; k++){
				if (index < inputString.length()){
					message[j][k] = inputString.at(index);
					index++;
				}
			}
		}
		for (int j = 0; j < bounds; j++){
			for (int k = 0; k < bounds; k++){
				outMessage[j][k] = message[bounds - 1 - k][j];
			}
		}
		for (int j = 0; j < bounds; j++){
			for (int k = 0; k < bounds; k++){
				if (outMessage[j][k] != '*'){
					cout << outMessage[j][k];
				}
			}
		}
		cout << endl;
	}
	return 0;
}