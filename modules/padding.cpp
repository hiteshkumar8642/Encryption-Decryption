#include <bits/stdc++.h>

using namespace std;

string padding(string &bin, int bl)
{
    /*
    This function takes a bit string 'bin' and returns a modified bit string.
    In the modified bit string, there are some random garbage bits added after
    each 'bl' bits.
    */
    string encrypted = "";
    int i = 0;
    int baseLen = bl;
    cout << "\nbaselen : " << baseLen << endl;
    while (i < bin.size() - bin.size() % baseLen)
    {
        int pad = 0;

        // Getting sum of bl consecutive bits
        for (int j = i; j < i + baseLen; j++)
        {
            encrypted += bin[j];
            pad += bin[j] - '0';
        }

        // Adding 'pad' number of random bits next to the bl bits
        while (pad)
        {
            encrypted += (char(rand() % 2) + '0');
            pad--;
        }
        i += baseLen;
    }
    while (i < bin.size())
        encrypted += bin[i++];
    return encrypted;
}

string remove_padding(string &enc, int bl)
{
    /*
    This function removes the garbage bits and returns the actual bit string.
    */
    string decrypted = "";
    int i = 0;
    int baseLen = bl;
    while (i < enc.size())
    {
        int pad = 0;
        for (int j = i; j < i + baseLen; j++)
        {
            if (j == enc.size())
                break;
            decrypted += enc[j];
            pad += enc[j] - '0';
        }
        i += baseLen + pad;
    }
    return decrypted;
}