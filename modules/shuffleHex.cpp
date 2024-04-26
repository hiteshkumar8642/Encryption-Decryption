#include <bits/stdc++.h>

using namespace std;

string encrypteqn(string s, int n)
{
    /*
    This function takes a hex string and returns a shuffled hex string
    */
    string s1 = "";
    int x = 1, ctr = 0, limit = n;
    set<int> numset;
    while (ctr < n)
    {
        x++;
        // This expression generates random indices within the range of the given limit for shuffling
        int y = (x ^ 3 + 3 * x ^ 2 + 7 * x + 9) % limit;
        if (numset.find(abs(y)) == numset.end())
        {
            // For each unique index generated, the bit at that index in the original string is copied to the new string
            numset.insert(abs(y));
            s1 += s[abs(y)];
            ctr++;
        }
    }
    return s1;
}

string decrypteqn(string s, int n)
{
    /*
    This function takes the shuffled hex string and returns a original string.
    */
    char s1[n];
    int x = 1, j = 0, ctr = 0, limit = n;
    set<int> numset;
    while (ctr < n)
    {
        x++;
        int y = (x ^ 3 + 3 * x ^ 2 + 7 * x + 9) % limit;
        if (numset.find(abs(y)) == numset.end())
        {
            numset.insert(abs(y));
            s1[abs(y)] = s[j++];
            ctr++;
        }
    }
    string s2 = "";
    for (int i = 0; i < n; i++)
    {
        s2 += s1[i];
    }
    return s2;
}