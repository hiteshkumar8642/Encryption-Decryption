#include <bits/stdc++.h>

using namespace std;

string odd_even_shift(string s)
{
    /*
     This function takes the bit string and returns a rearranged string.
     The rearranged string has all the bits at odd positions moved to the left
     and the even ones are moved to the right.
     */
    string s1 = "";
    int l = s.size();
    if (l % 2 != 0)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
                s1 += s[i];
        }
        for (int i = s.size() - 2; i > 0; i--)
        {
            if (i % 2 != 0)
                s1 += s[i];
        }
        return s1;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
                s1 += s[i];
        }
        for (int i = s.size() - 1; i > 0; i--)
        {
            if (i % 2 != 0)
                s1 += s[i];
        }
        return s1;
    }
}

string even_odd_shift(string s)
{
    /*
     This function takes a previously rearranged bit string  and returns the original bit string.
     */
    int n = s.size();
    string s1 = "";

    int i = 0, j = n - 1, flag = 0;
    while (i <= j)
    {
        if (flag == 0)
        {
            s1 += s[i++];
            flag = 1;
        }
        else
        {
            s1 += s[j--];
            flag = 0;
        }
    }
    return s1;
}

string leftShift(string s, int n)
{
    /*
    It takes the bit string 's' and shifts it to the left by 'n' bits in a cyclic manner.
    (Rotates the string)
    */
    string rem = "";
    for (int i = n; i < s.length(); i++)
    {
        rem += s[i];
    }
    for (int i = 0; i < n; i++)
    {
        rem += s[i];
    }
    return rem;
}

string rightShift(string s, int n)
{
    /*
    It takes the bit string 's' and shifts it to the right by 'n' bits in a cyclic manner.
    (Rotates the string)
    */
    string rem = "";
    for (int i = s.length() - n; i < s.length(); i++)
    {
        rem += s[i];
    }
    for (int i = 0; i <= s.length() - n - 1; i++)
    {
        rem += s[i];
    }
    return rem;
}