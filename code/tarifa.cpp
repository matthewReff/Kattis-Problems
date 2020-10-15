#include <iostream>
using namespace std;

int main(){
	int num1;
	int num2;
	int num3 = 0;
	int num4;
	cin >> num1;
	cin >> num2;
	
	for (int i = 0; i < num2; i++){
		cin >> num4;
		num3 += (num1-num4);
		
	}
	cout << num3 + num1;
	return 0;
}