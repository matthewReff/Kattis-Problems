#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ll cases;

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        int caseNum;
        int maxDenom;
        double number;
        cin >> caseNum >> maxDenom >> number;

        double closestDifference = 1;
        int bestNumer;
        int bestDenom;
        for(int i = maxDenom; i > 0; i--)
        {
            double intermediate = number * i;
            double higher = ceil(intermediate) / double(i);
            double lower = floor(intermediate) / double(i);

            if(abs(higher - number) < closestDifference)
            {
                closestDifference = abs(higher - number);
                bestNumer = ceil(intermediate);
                bestDenom = i; 
            }

            if(abs(lower - number) < closestDifference)
            {
                closestDifference = abs(lower - number);
                bestNumer = floor(intermediate);
                bestDenom = i; 
            }
        }

        int divideVal = __gcd(bestNumer, bestDenom);
        cout << caseNum << " " << bestNumer / divideVal << "/" << bestDenom / divideVal << "\n";

    }
    return 0;
}