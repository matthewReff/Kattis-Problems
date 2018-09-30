#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <unordered_set>
using namespace std;


int main(){
	int limit;
	int sets;
	int group_size;
	int in_build = 0;
	int exced = 0;
	string leav_ent;
	cin >> limit >> sets;
	for (int i = 0; i < sets; i++){
		cin >> leav_ent >> group_size;
		if (leav_ent == "enter"){
			if ((in_build + group_size) > limit){
				exced++;
			}
			else{
				in_build += group_size;
			}
		}
		else{
			in_build -= group_size;
		}
	}
	cout << exced;
	return 0;
}