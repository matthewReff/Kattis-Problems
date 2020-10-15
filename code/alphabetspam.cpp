#include <iomanip>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main(){
	char tempChar;
	int charWhite = 0;
	int charUpper = 0;
	int charLower = 0;
	int charSymbol = 0;
	int stringLength;
	string tempString;

	cin >> tempString;

	stringLength = tempString.length();
	for (int i = stringLength; i > 0; i--){
		tempChar= tempString.at(i - 1);
		if (tempChar == '_'){
			charWhite++;
		}
		else if (isupper(tempChar)){
			charUpper++;
		}
		else if (islower(tempChar)){
			charLower++;
		}
		else{
			charSymbol++;
		}
	}
	cout << setprecision(8);
	cout << (double(charWhite) / stringLength) << "\n";
	cout << (double(charLower) / stringLength) << "\n";
	cout << (double(charUpper) / stringLength) << "\n";
	cout << (double(charSymbol) / stringLength) << "\n";
	return 0;
}
