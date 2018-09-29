#include <iostream>
using namespace std;

int main(){
	int lenTable, row;
	int speed, time, previousTime, totalMiles;

	while (cin >> lenTable && lenTable != -1){
		previousTime = 0;
		totalMiles = 0; 
		for (row = 0; row < lenTable; row++){
			cin >> speed >> time;
			totalMiles += ((time - previousTime) * speed);
			previousTime = time;
		}
		cout << totalMiles << " miles" << endl;


	}
	return 0;
}