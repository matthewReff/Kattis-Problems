#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int num1;
	int wins = 0;
	string tempString;
	cin >> num1;
	for (int i = 0; i < num1; i++){
		cin >> tempString;
		for (int j = 1; j < tempString.length(); j++){
			if (tempString.at(j) == 'D' && tempString.at(j - 1) == 'C'){
				wins -= 1;
				break;
			}
			
		}
	}
	cout << num1+wins;
	

	return 0;
}