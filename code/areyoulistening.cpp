#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    struct device
    {
        ll xCoord, yCoord, radius;  
    };
    
    ll myX, myY, numDevices;
    ll devicesInRange = 0;
    ll testRadius = -1;
    ll lastWorkingRadius = 0;
    cin >> myX >> myY >> numDevices;
    vector<device> listeningDevices(numDevices);
    for(i = 0; i < numDevices; i++)
    {
        cin >> listeningDevices[i].xCoord >> listeningDevices[i].yCoord >> listeningDevices[i].radius;
    }
    
    while(devicesInRange < 3)
    {
        testRadius++;
        devicesInRange = 0;
        for(i = 0; i < numDevices; i++)
        {
            //compare point's distance to combined radius
            if( sqrt((ld)(listeningDevices[i].xCoord - myX) * (listeningDevices[i].xCoord - myX) + 
            (listeningDevices[i].yCoord - myY) * (listeningDevices[i].yCoord - myY)) < 
            listeningDevices[i].radius + testRadius)
            {
                devicesInRange++;
            }
        }
        if(devicesInRange < 3)
        {
            lastWorkingRadius = testRadius;
        }  
    }
    
    cout << lastWorkingRadius << "\n";
    return 0;
}
