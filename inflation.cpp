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
    ull i, j, k;
    ull size;
    cin >> size;
    ld min = 1;
    ld temp;
    vector<ll> nums(size);

    for (i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());


    for (i = size; i >= 1; i--)
    {
        temp = nums[i - 1] / (ld)i;
        if (temp > 1)
        {
            cout << "impossible\n";
            return 0;
        }
        if (temp < min)
        {
            min = temp;
        }
    }

    cout << fixed << setprecision(10);
    cout << min << "\n";
    return 0;
}
