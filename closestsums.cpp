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
typedef long double ld;
#define endl '\n'
#define pb push_back
#define EPSILON 0.000001

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

bool mySort(pair<int, int> a, pair<int, int>b) {
    return a.first < b.first;
}

int main()
{
    fastIO();

    ll i, j, k;
    ll cases, queries, temp;
    ll caseNum = 0;
    ll closest;
    while (cin >> cases)
    {
        caseNum++;
        cout << "Case " << caseNum << ":\n";
        vector<ll> nums;
        for (i = 0; i < cases; i++)
        {
            cin >> temp;
            nums.push_back(temp);
        }
        cin >> queries;
        for (i = 0; i < queries; i++)
        {
            cin >> temp;
            closest = 1000000000;
            for (j = 0; j < cases; j++)
            {
                for (k = j + 1; k < cases; k++)
                {
                    if ( abs((nums[j] + nums[k]) - temp) < abs(closest - temp))
                    {
                        closest = nums[k] + nums[j];
                    }
                }
            }
            cout << "Closest sum to " << temp << " is " << closest << ".\n";
        }
        
    }
    return 0;
}


