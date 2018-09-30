#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int dataSets;
	int prevInput;
	int input;
	cin >> dataSets;
	for (int i = 0; i < dataSets; i++){
		int imports = 0;
		input = 1;
		prevInput = 1;
		while (cin >> input && input != 0){
			if ((prevInput * 2) < input){
				imports += input - (prevInput * 2);
			}
			prevInput = input;
		}
		cout << imports << endl;
	}
	return 0;
}