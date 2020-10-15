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
#include <stack>
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
    ll i, j, k;
    

    ll words, numTranslations;
    ll rightTranslations, wrongTranslations, tempRight, tempWrong;

    string dutchWord, englishWord, correctness;
    map<string, int> corrects;
    map<string, int> incorrects;
    map<string, string> translation;
    
    cin >> words;
        vector<string> sentence(words);
    for(i = 0; i < words; i++)
    {
        cin >> sentence[i];
    }
    cin >> numTranslations;
    for(i = 0; i < numTranslations; i++)
    {
        cin >> dutchWord >> englishWord >> correctness;
        if(correctness == "correct")
        {
            corrects[dutchWord]++;
        }
        else
        {
            incorrects[dutchWord]++;
        }
        translation[dutchWord] = englishWord;
    }
    
    
    rightTranslations = corrects[sentence[0]];
    wrongTranslations = incorrects[sentence[0]];
    for(i = 1; i < words; i++)
    {
        tempRight = rightTranslations;
        tempWrong = wrongTranslations;
        rightTranslations = tempRight * corrects[sentence[i]];
        wrongTranslations = tempRight * incorrects[sentence[i]];
        wrongTranslations += tempWrong * corrects[sentence[i]] + tempWrong * incorrects[sentence[i]];
    }
    
    if(rightTranslations == 1 ^ wrongTranslations == 1)
    {
        for(auto part : sentence)
        {
            cout << translation[part] << " ";
        }
        cout << "\n";
        if(rightTranslations)
        {
            cout << "correct\n";
        }
        else
        {
            cout << "incorrect\n";
        }
    }
    else
    {
        cout << rightTranslations << " correct\n";
        cout << wrongTranslations << " incorrect\n";
    }
    return 0;
}


