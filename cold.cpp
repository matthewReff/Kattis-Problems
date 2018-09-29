#include <iostream>
using namespace std;

int main(){
	int num1;
	int num2;
	int num3 = 0;
	cin >> num1;
	for (int i = 0; i < num1; i++){
		cin >> num2;
		if (num2 < 0){
			num3++;
		}
	}
	cout << num3;
	return 0;
}