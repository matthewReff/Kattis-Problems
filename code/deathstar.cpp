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

typedef long long ll;
using namespace std;

int main()
{

    ll i, j, k;
   
    ll n, bottom;

    vector<vector<ll>> matrix;
    vector<ll> code;
    cin >> n;

    matrix.resize(n);
    for (i = 0; i < n; i++)
    {
        matrix[i].resize(n);
        code.push_back(0);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    bottom = 1;

    for (i = 0; i < n; i++)
    {
        for (j = bottom; j < n; j++)
        {
            code[i] |= matrix[i][j];
            code[j] |= matrix[i][j];
        }
        bottom++;
    }

    for (auto num : code)
    {
        cout << num << " ";
    }
    return 0;
}