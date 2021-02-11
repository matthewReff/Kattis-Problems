#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<vector<long double>> memo(101, vector<long double>(101, -1));
long double getModifier(int n, int x)
{
	
	if (x < 0 || x > n)
	{
		return 0;
	}
	else if(x == 0 || x == n)
	{
		return 1;
	}
	if (memo[n][x] != -1)
	{
		return memo[n][x];
	}
	memo[n][x] = getModifier(n-1, x-1) + getModifier(n-1, x);
	return memo[n][x];
}

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    ll cases;
    cin >> cases;
    ll N, v1, v2;
    long double W;

    for(i = 0; i < cases; i++)
    {
    	cin >> N >>  v1 >> v2 >> W;
    	ll votesLeft = N - (v1 + v2);
    	
    	// First case, impossible
    	if (v1 + votesLeft <= v2)
    	{
    		cout << "RECOUNT!\n";
    		continue;
    	}
    	else if(v2 + votesLeft < v1)
    	{
    		cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
    		continue;
    	}
    	ll toWin;
    	if (N % 2 == 0)
    	{
    		toWin = N/2 + 1;
    	}
    	else
    	{
    		toWin = ceil(N/2.0);
    	}

    	toWin -= v1;
    	//cout << "Towin:" << toWin << "\n";
    	long double totalVal = 0.0;
    	for(j = toWin; j <= votesLeft; j++)
    	{
    		long double nChooseK = getModifier(votesLeft, j);
    		//cout << nChooseK << "\n";
    		totalVal += nChooseK;
    	}
    	for(j = 0; j < votesLeft; j++)
    	{
    		W *= 2;
    	}

    	//cout << totalVal * 100.0 << " " << W << "\n";
    	if(totalVal * 100.0 > W)
    	{
    		cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
    	}
    	else
    	{
    		cout << "PATIENCE, EVERYONE!\n";
    	}
    }
    return 0;
}
