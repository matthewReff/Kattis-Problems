#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

using namespace std;


int main()
{
	long long i, j, k;
	
	int * taskTimes;
	int tasksDone = 0;
	int taskTimeTotal = 0;
	bool notFull = true;
	int n, t;

	cin >> n >> t;

	taskTimes = new(nothrow) int[n];

	for (i = 0; i < n; i++)
	{
		cin >> taskTimes[i];
	}
	i = 0;
	while(i < n && notFull) 
	{
		if(taskTimeTotal + taskTimes[i] <= t)
		{
			tasksDone++;
			taskTimeTotal += taskTimes[i];
			
		}
		else
		{
			notFull = false;
		}
		i++;
	}
	cout << tasksDone;
	return 0;
}