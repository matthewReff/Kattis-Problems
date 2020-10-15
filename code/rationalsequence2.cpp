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

void boardRecurse(ll ** matrix, vector<bool>&  used, vector<ll> &mins, ll n)
{
    for (int i = 0; i < n; i++)
    {

    }
}
int main()
{
    fastIO();

    ll i, j, k;
    
    ll cases, garb, num1, num2, num;
    char garbChar;
    string navigate;
    cin >> cases;
    for (i = 0; i < cases; i++)
    {
        cin >> garb >> num1 >> garbChar >> num2;
        navigate = "";
        while (num1 != 1 || num2 != 1)
        {
            if (num1 > num2)
            {
                navigate += "R";
                num1 -= num2;
            }
            else
            {
                navigate += "L";
                num2 -= num1;
            }
        }
        reverse(navigate.begin(), navigate.end());
        num = 1;
        for (auto myChar : navigate)
        {
            if (myChar == 'L')
            {
                num *= 2;
            }
            else
            {
                num *= 2;
                num += 1;
            }
        }
        cout << i+1 << " " <<  num << "\n";
    }
    return 0;
}


