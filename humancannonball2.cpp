#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int trials;
	double Vo;
	double theta;
	double X1;
	double lowH;
	double highH;
	double time;
	double position;
	double radian;

	double radToDeg(double degree);
	cin >> trials;
	for (int i = 0; i < trials; i++){
		cin >> Vo >> theta >> X1 >> lowH >> highH;
		radian = radToDeg(theta);
		time = (X1 / (Vo * cos(radian)));
		position = (Vo * time * sin(radian)) - (.5 * 9.81 * pow(time, 2));
		//cout << time << " " << position;
		if ((position-1 > lowH) && (position+1 < highH)){
			cout << "Safe" << endl;
		}
		else{
			cout << "Not Safe" << endl;
		}
	}
	return 0;
}
double radToDeg(double degree){
	return (degree * (M_PI / 180.0));
}