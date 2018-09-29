#include <iostream>
using namespace std;

int main(){

	int num1;
	int num2;
	int highNum;
	cin >> num1 >> num2;
	if (num1 == 0 && num2 == 0) {
		cout << "Not a moose";
	}
	else if (num1 == num2) {
		cout << "Even " << num1 * 2;
	}
	
	else {
		if (num1 > num2) {
			cout << "Odd " << num1 * 2;
		}
		else {
			cout << "Odd " << num2 * 2;
		}
	}
    return 0;
}

