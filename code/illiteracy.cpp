#include <bits/stdc++.h>

using namespace std;

char rotate(char s)
{
    return ((s-'A'+1)%('F'-'A'+1)) + 'A';//this is the only thing I changed (added 1)
}

string doA(string s, int x)
{
    if (x == 0) s[1] = rotate(s[1]);
    else if (x == 7) s[6] = rotate(s[6]);
    else
    {
        s[x-1] = rotate(s[x-1]);
        s[x+1] = rotate(s[x+1]);
    }
    return s;
}

string doB(string s, int x)
{
    if (x == 0 || x == 7) return s;
    s[x+1] = s[x-1];
    return s;
}

string doC(string s, int x)
{
    s[7-x] = rotate(s[7-x]);
    return s;
}

string doD(string s, int x)
{
    if (x == 0 || x == 7) return s;
    if (7 < 2*x)
    {
        for (int i = x+1; i <= 7; i++)
        {
            s[i] = rotate(s[i]);
        }
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            s[i] = rotate(s[i]);
        }
    }
    return s;
}

string doE(string s, int x)
{
    if (x == 0 || x == 7) return s;
    int y = min(7-x, x);
    s[x-y] = rotate(s[x-y]);
    s[x+y] = rotate(s[x+y]);
    return s;
}

string doF(string s, int x)
{
    if ((x+1)%2) s[(x+10)/2-1] = rotate(s[(x+10)/2-1]);
    else s[(x+1)/2-1] = rotate(s[(x+1)/2-1]);
    return s;
}
int main() {
    string src, target;
    cin >> src >> target;
    queue<pair<string, int>> q;
    set<string> seen;

    q.push(make_pair(src, 0));
    seen.insert(src);

    while(q.size())
    {
        pair<string, int> front = q.front();
        q.pop();
        string value = front.first;
        int moves = front.second;

        if(value == target)
        {
            cout << moves << "\n";
            return 0;
        }

        //add to queue
        string newString;
        for (int i = 0; i < 8; i++)
        {
            if (value[i] == 'A')
                newString = doA(value, i);
            else if (value[i] == 'B')
                newString = doB(value, i);
            else if (value[i] == 'C')
                newString = doC(value, i);
            else if (value[i] == 'D')
                newString = doD(value, i);
            else if (value[i] == 'E')
                newString = doE(value, i);
            else if (value[i] == 'F')
                newString = doF(value, i);
            else assert(false);

            if(seen.find(newString) == seen.end())
            {
                q.push(make_pair(newString, moves+1));
                seen.insert(newString);
            }
        }
    }
    //cout << "dropped out";
    return 0;
}
