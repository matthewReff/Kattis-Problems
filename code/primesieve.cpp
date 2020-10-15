#define _USE_MATH_DEFINES
#include <iostream>
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

typedef long long ll;
using namespace std;

#define EPSILON 0.000001

void primeSeive(vector<bool> & primes, ll n);
int main()
{
    ll i, j, k;
    ll n, cases, temp;
    ll total = 0;
    cin >> n >> cases;
    vector<bool> prime(n+1, true);
    
    primeSeive(prime, n+1);

    for (i = 0; i <= n; i++)
    {
        if (prime[i])
        {
            total++;
        }
    }

    cout << total << "\n";

   
    for (i = 0; i < cases; i++)
    {
        cin >> temp;
        cout << prime[temp] << "\n";
    }
    return 0;

}


void primeSeive(vector<bool> & primes, ll n)
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
