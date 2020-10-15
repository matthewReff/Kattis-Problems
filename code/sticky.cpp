//Solved by https://open.kattis.com/users/vedang-gaonkar
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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<ull> a;
    int n;

    cin>>n;

    for(int i=0; i<n; i++)
    {
	ull x;
	cin>>x;
	a.push_back(x);
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n-2; i++)
    {
	if(a[i] + a[i+1] > a[i+2])
	{
	    cout<<"possible"<<endl;
	    return 0;
	}
    }

    cout<<"impossible"<<endl;

    
    return 0;
}
