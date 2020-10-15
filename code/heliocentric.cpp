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

    ll earthDay, marsDay, answer;
    i = 1;
    answer = 0;
    while (cin >> earthDay)
    {
        cin >> marsDay;
        answer = 0;
        while (earthDay != 0 || marsDay != 0)
        {
            earthDay++;
            marsDay++;
            answer++;
            earthDay = earthDay % 365;
            marsDay = marsDay % 687;
        }
        cout << "Case " << i << ": " << answer << "\n";
        i++;
    }

    return 0;
}