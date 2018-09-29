#include <iostream>
using namespace std;

int main(){
	int num1;
	int num2;
	cin >> num1 >> num2;
	if (num1 > 0 && num2 > 0){
		cout << "1";
	}
	else if (num1 < 0 && num2 > 0){
		cout << "2";
	}
	else if (num1 < 0 && num2 < 0){
		cout << "3";
	}
	else{
		cout << "4";
	}
	return 0;
}