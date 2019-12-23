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

void primeSeive(vector<bool> & primes, long long n)
{
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            for (int j = 0; j < n / i; j++)
            {
                if (i < 10000 && (i*i) + (i * j) < n)
                {
                    primes[(i*i) + (i * j)] = false;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //vector<bool> primes(1000000001, false);
    
    //primeSeive(primes, 1000000001);
    ll factors = 0;
    ll num;
    cin >> num;
    for(int k = 2; k < sqrt(1000000001)+1; k++) 
    {
    	//cout << k << "\n";
    	//cout << num << " " << k << " " << num % k << "\n";
    	while(num % k == 0)
    	{
    		factors++;
    		//cout << k << "\n";
    		num /= k;
    	}
    	if(num == 1)
    	{
    		cout << factors << "\n";
    		return 0;
    	}
    }
    cout << factors + 1 << "\n";
    return 0;
}


