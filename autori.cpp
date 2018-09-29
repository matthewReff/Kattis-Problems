#include <iostream>
#include <string>
using namespace std;

int main(){
	string initials = "";
	string rawString = "";
	int stringLength;
	cin >> rawString;
	stringLength = rawString.length();
	for (int i = 0; i < stringLength; i++){
		if (isupper(rawString.at(i))){
			initials += rawString.at(i);
		}

	}
	cout << initials;
	return 0;
}