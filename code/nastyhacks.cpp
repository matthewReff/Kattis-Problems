#include <iostream>
#include <string>
using namespace std;

int main(){
	int dataSets = 0;
	int rev, exp, adv;
	cin >> dataSets;
	for (int i = 0; i < dataSets; i++){
		cin >> rev >> exp >> adv;
		if (rev > (exp - adv)){
			cout << "do not advertise\n";
		}
		else if (rev == (exp - adv)){
			cout << "does not matter\n";
		}
		else{
			cout << "advertise\n";
		}

	}
	return 0;
}