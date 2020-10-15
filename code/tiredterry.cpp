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

    ll seqLen, queryLen, minSleep;

    cin >> seqLen >> queryLen >> minSleep;
    string seq;
    cin >> seq;
    vector<ll> wake(1+seqLen*2);
    vector<ll> sleep(1+seqLen*2);

    wake[0] = 0;
    sleep[0] = 0;
    for(i = 1; i <= seqLen; i++)
    {
        if (seq[i-1] == 'W')
        {
                wake[i] = wake[i-1] + 1;
                sleep[i] = sleep[i-1];
        }
        else
        {
                wake[i] = wake[i-1];
                sleep[i] = sleep[i-1] + 1;
        }
    }

    for(i = 1+seqLen; i <= seqLen*2; i++)
    {
        if (seq[i-1-seqLen] == 'W')
        {
                wake[i] = wake[i-1] + 1;
                sleep[i] = sleep[i-1];
        }
        else
        {
                wake[i] = wake[i-1];
                sleep[i] = sleep[i-1] + 1;
        }
    }

    ll total = 0;

    for(i = seqLen+1; i <= seqLen + seqLen; i++)
    {
        //cout << sleep[i]-sleep[i-queryLen] << ": " << i << "\n";
        if(sleep[i]-sleep[i-queryLen] < minSleep)
        {
            total++;
        }
    }

        cout << total << "\n";
     
     /*   
    for(auto val : wake)
    {
        cout << val << " ";
    }
    cout << "\n";
    for(auto val : sleep)
    {
        cout << val << " ";
    }
    */
    return 0;
}