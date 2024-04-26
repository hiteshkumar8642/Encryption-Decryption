#include <bits/stdc++.h>

using namespace std;

char flip(char c)
{
    return (c == '0') ? '1' : '0';
}

/*
This function complements the bits at the prime indices of the given strings.
*/

string pencrypt(string s)
{
    int k = 0;
    string s1 = "";
    for (int j = 0; j < s.size(); j++)
    {
        int i, n;
        bool is_prime = true;
        // 0 and 1 are not prime numbers
        if (j == 0 || j == 1)
        {
            is_prime = false;
        }

        // loop to check if n is prime
        for (i = 2; i <= sqrt(j); ++i)
        {
            if (j % i == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            s1 += s[k++];
        else
            s1 += flip(s[k++]);
    }

    return s1;
}

string pdecrypt(string s)
{

    int k = 0;
    string s2 = "";
    for (int j = 0; j < s.size(); j++)
    {
        int i, n;
        bool is_prime = true;
        // 0 and 1 are not prime numbers
        if (j == 0 || j == 1)
        {
            is_prime = false;
        }

        // loop to check if n is prime
        for (i = 2; i <= sqrt(j); ++i)
        {
            if (j % i == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            s2 += s[k++];
        else
            s2 += flip(s[k++]);
    }

    return s2;
}