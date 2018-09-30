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

    
    ll cases;
    ll keyStrokes[4];

    ll matchIndex;
    string mainWord;
    string typeWord;
    string suggest1, suggest2, suggest3;

    cin >> cases;

    for (i = 0; i < cases; i++)
    {
        cin >> mainWord >> typeWord >> suggest1 >> suggest2 >> suggest3;

        matchIndex = 0;
        while (matchIndex < max(typeWord.size(),mainWord.size()) && typeWord[matchIndex] == mainWord[matchIndex])
        {
            matchIndex++;
        }

        keyStrokes[0] = typeWord.size() - matchIndex //backspace times
            + mainWord.size() - matchIndex; //type remaining word

            matchIndex = 0;
            while (matchIndex < max(suggest1.size(), mainWord.size()) && suggest1[matchIndex] == mainWord[matchIndex])
            {
                matchIndex++;
            }
            //cout << matchIndex << "\n";

            keyStrokes[1] = 1 // take suggestion
                + suggest1.size() - matchIndex //backspace times
                + mainWord.size() - matchIndex; //type remaining word


            matchIndex = 0;
            while (matchIndex < max(suggest2.size(), mainWord.size()) && suggest2[matchIndex] == mainWord[matchIndex])
            {
                matchIndex++;
            }
            //cout << matchIndex << "\n";

            keyStrokes[2] = 1 // take suggestion
                + suggest2.size() - matchIndex //backspace times
                + mainWord.size() - matchIndex; //type remaining word

            matchIndex = 0;
            while (matchIndex < max(suggest3.size(), mainWord.size()) &&  suggest3[matchIndex] == mainWord[matchIndex])
            {
                matchIndex++;
            }
            //cout << matchIndex << "\n";

            keyStrokes[3] = 1 // take suggestion
                + suggest3.size() - matchIndex //backspace times
                + mainWord.size() - matchIndex; //type remaining word

            sort(keyStrokes, keyStrokes + 4);
            cout << keyStrokes[0] << "\n";
    }
    return 0;
}