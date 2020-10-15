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
    ll n;
    ll num1, num2;
    string command;
    while (cin >> n && n != 0)
    {
        string bits = "????????????????????????????????";
        for (i = 0; i < n; i++)
        {
            cin >> command;
            if (command == "SET")
            {
                cin >> num1;
                bits[31 - num1] = '1';
            }
            else if (command == "CLEAR")
            {
                cin >> num1;
                bits[31 - num1] = '0';
            }
            else if (command == "AND")
            {
                cin >> num1 >> num2;
                if (bits[31 - num1] == '0' || bits[31 - num2] == '0')
                {
                    bits[31 - num1] = '0';
                }
                else if (bits[31 - num1] == '1' && bits[31 - num2] == '1')
                {
                    bits[31 - num1] = '1';
                }
                else
                {
                    bits[31 - num1] = '?';
                }
            }
            else if (command == "OR")
            {
                cin >> num1 >> num2;
                if (bits[31 - num1] == '1' || bits[31 - num2] == '1')
                {
                    bits[31 - num1] = '1';
                }
                else if (bits[31 - num1] == '0' && bits[31 - num2] == '0')
                {
                    bits[31 - num1] = '0';
                }
                else
                {
                    bits[31 - num1] = '?';
                }
            }
        }
        for (i = 0; i < bits.size(); i++)
        {
            cout << bits[i];
        }
        cout << "\n";
    }
    return 0;
}


