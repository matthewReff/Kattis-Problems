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
    ull i, j, k;
    vector<bool> primes(10001, true);

    ull cases;
    ll num, test;
    ll total;
    ll temp;
    string tempString;
    ll state;

    primeSeive(primes, 10001);
    vector<int> goesToOne(10001, -2); //-2 is untouced, 1 coverges to 1, -1 is inf, 0 is in current q
    stack<int> myStack;
    goesToOne[1] = 1;

    for (i = 2; i < 10001; i++)
    {
        temp = i;
        while (goesToOne[temp] == -2)
        {
            total = 0;
            myStack.push(temp);
            goesToOne[temp] = 0;
            tempString = to_string(temp);
            for (auto thing : tempString)
            {
                total += pow((thing - '0'), 2);
            }
            temp = total;
            //cout << total << "\n";
        }

        if (goesToOne[temp] == 1)
        {
            state = 1;
        }
        else
        {
            state = -1;
        }

        while (myStack.size())
        {
            goesToOne[myStack.top()] = state;
            myStack.pop();
        }
    }

    cin >> cases;

    for (i = 0; i < cases; i++)
    {
        cin >> num >> test;
        cout << num << " " << test << " ";
        if (goesToOne[test] == 1 && primes[test])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


    return 0;
}
