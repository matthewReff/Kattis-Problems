#include <iostream>
#include <stdlib.h>
#include <vector>

typedef	long long ll;
using namespace std;

int main()
{
	ll i, j ,k;
	ll lowTime = 0;
	ll lowest = 0;
	ll highTime = 0;
	ll highest = 10000;
	ll cases;
	
    bool possible = true;
	cin >> cases;
	i = 0;
	while(possible && i < cases)
	{
		cin >> lowTime >> highTime;
		if (lowTime > lowest)
		{
		    lowest = lowTime;
		}		
		if (highTime < highest)
		{
		    highest = highTime;
		}
		if (lowest > highest)
		{
		    possible = false;
		}
		i++;
		   
	}
	if(possible)
	{
	    cout << "gunilla has a point\n";
	}
	else
	{
	    cout << "edward is right\n";
	}
	return 0;
}
