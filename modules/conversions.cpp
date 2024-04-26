#include <bits/stdc++.h>

using namespace std;

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

string ascii_To_Binary(string s)
{
    vector<string> st;
    string k;
    int n;
    for (int i = 0; i < s.size(); i++)
    {
        n = int(s[i]);
        k = bitset<8>(n).to_string();
        st.push_back(k);
    }
    cout << endl;
    string s1;
    for (const auto &piece : st)
        s1 += piece;
    return s1;
}

string Binary_To_ascii(string str)
{

    int N = int(str.size());
    string res = "";
    for (int i = 0; i < N; i += 8)
    {
        int decimal_value = binaryToDecimal((str.substr(i, 8)));
        cout << decimal_value << " ";
        res += char(decimal_value);
    }
    cout << endl;
    return res;
}

void createMap(unordered_map<string, char> *um)
{
    (*um)["0000"] = '0';
    (*um)["0001"] = '1';
    (*um)["0010"] = '2';
    (*um)["0011"] = '3';
    (*um)["0100"] = '4';
    (*um)["0101"] = '5';
    (*um)["0110"] = '6';
    (*um)["0111"] = '7';
    (*um)["1000"] = '8';
    (*um)["1001"] = '9';
    (*um)["1010"] = 'A';
    (*um)["1011"] = 'B';
    (*um)["1100"] = 'C';
    (*um)["1101"] = 'D';
    (*um)["1110"] = 'E';
    (*um)["1111"] = 'F';
}

string convertBinToHex(string bin)
{
    int l = bin.size();
    unordered_map<string, char> bin_hex_map;
    createMap(&bin_hex_map);

    int i = 0;
    string hex = "";

    while (1)
    {
        hex += bin_hex_map[bin.substr(i, 4)];
        i += 4;
        if (i == bin.size())
            break;
    }
    return hex;
}

string HexToBin(string hexdec)
{
    long int i = 0;
    string s;
    while (hexdec[i])
    {

        switch (hexdec[i])
        {
        case '0':
            s += "0000";
            break;
        case '1':
            s += "0001";
            break;
        case '2':
            s += "0010";
            break;
        case '3':
            s += "0011";
            break;
        case '4':
            s += "0100";
            break;
        case '5':
            s += "0101";
            break;
        case '6':
            s += "0110";
            break;
        case '7':
            s += "0111";
            break;
        case '8':
            s += "1000";
            break;
        case '9':
            s += "1001";
            break;
        case 'A':
        case 'a':
            s += "1010";
            break;
        case 'B':
        case 'b':
            s += "1011";
            break;
        case 'C':
        case 'c':
            s += "1100";
            break;
        case 'D':
        case 'd':
            s += "1101";
            break;
        case 'E':
        case 'e':
            s += "1110";
            break;
        case 'F':
        case 'f':
            s += "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit " << hexdec[i];
        }
        i++;
    }
    return s;
}