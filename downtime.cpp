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
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ll requests;
    double loadPerServer;
    queue<ll> threads;
    ll timeStamp;
    ll mostActivethreads = 0;
    ll currentUsedThreads;

    cin >> requests;
    cin >> loadPerServer;

    for(i = 0; i < requests; i++)
    {
    	cin >> timeStamp;
    	currentUsedThreads = 0;
     	while(threads.size() != 0 && threads.front() + 1000 <= timeStamp)
    	{
    		threads.pop();
    	}
    	threads.push(timeStamp);
    	if(threads.size() > mostActivethreads)
    	{
    		mostActivethreads = threads.size();
    	}    	
    }
    cout << ceil(mostActivethreads/loadPerServer);
    return 0;
}
