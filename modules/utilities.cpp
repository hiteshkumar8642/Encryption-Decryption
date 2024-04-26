#include <bits/stdc++.h>

using namespace std;

string makesuitable(string s, int &n)
{
    while (s.size() % 4 != 0)
    {
        s += "0";
        n++;
    }
    return s;
}

string makeunsuitable(string s, int n)
{
    while (n != 0)
    {
        s.pop_back();
        n--;
    }
    return s;
}