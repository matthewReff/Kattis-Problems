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

    string in;
    int orig;
    bool found = false;
    cin >> in;
    orig = stoi(in, NULL, 10);

    sort(in.begin(), in.end());

    do
    {
        if (stoi(in, NULL, 10) > orig)
        {
            found = true;
        }
    } while (!found && next_permutation(in.begin(), in.end()));

    if (found)
    {
        for (i = 0; i < in.size(); i++)
        {
            cout << in[i];
        }
        cout << "\n";

    }
    else
    {
        cout << "0";
    }
    return 0;
}