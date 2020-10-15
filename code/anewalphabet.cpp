#include <string>
#include <iostream>
using namespace std;

int main(){
	string translation[26] = {"@","8","(","|)","3","#","6","[-]",
	"|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|Z","$","']['",
	"|_|","\\/","\\/\\/","}{","`/","2"};
	string output = "";
	string input;
	getline(cin, input);
	for (int i = 0; i < input.length(); i++){
		input.at(i) = tolower(input.at(i));
		if (isalpha(input.at(i))){
			cout << translation[input.at(i)-'a'];
		}
		else{
			cout << input.at(i);
		}
	}
	cout << output;
	return 0;
}