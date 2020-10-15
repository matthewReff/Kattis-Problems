#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int num1;
	int expected[6] {1, 1, 2, 2, 2, 8};
	for (int i = 0; i < 6; i++){
		cin >> num1;
		cout << expected[i] - num1 << " ";
	}
	
	return 0;
}