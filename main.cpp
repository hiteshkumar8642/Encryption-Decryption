#include <bits/stdc++.h>
#include "modules/bitShift.cpp"
#include "modules/conversions.cpp"
#include "modules/flipPrimes.cpp"
#include "modules/padding.cpp"
#include "modules/shuffleHex.cpp"
#include "modules/utilities.cpp"

using namespace std;

string encryptfinal(string s)
{
    cout << "\nAscii to Binary\n";
    s = ascii_To_Binary(s);
    cout << s << endl;
    string key = "";
    int sz = 0, prev = 0, base_length, shift_len;
    set<int> rnum;
    char y, z;
    while (1)
    {
        /*
        Here, all the bit manipulation functions is executed once on the binary in a random order.
        this order of execution, along with the base_len for padding function and shift_len for shift functions
        is stored in the 'key'
        */

        int x = rand() % 4;
        rnum.insert(x);
        sz = rnum.size();
        if (sz > prev)
        {
            prev += 1;
            switch (x)
            {
            case 0:
                key += char(0 + '0');
                cout << "\n prime_encrypt();" << endl;
                s = pencrypt(s);
                //cout << s << endl;
                break;
            case 1:
                key += char(1 + '0');
                cout << "\n odd_even_shift();" << endl;
                s = odd_even_shift(s);
                //cout << s << endl;
                break;
            case 2:
                base_length = ((rand() % 4) + 5);
                y = char(base_length + '0');
                // base length is added to the key
                key += y;
                cout << "\n padding();" << endl;
                key += char(2 + '0');
                s = padding(s, base_length);
                //cout << s << endl;
                break;
            case 3:
                shift_len = (rand() % 10);
                // shift_len is added to the key
                z = char(shift_len + '0');
                key += z;
                cout << "\n left_shift();" << endl;
                key += char(3 + '0');
                s = leftShift(s, shift_len);
                //cout << s << endl;
                break;
            }
        }
        if (rnum.size() == 4)
            break;
    }

    // Some extra bits are added to the bit string if its length is not a multiple of 4 before converting it to Hex.
    int extra_bit = 0;
    cout << "\nMaking suitable\n";
    s = makesuitable(s, extra_bit);

    // The no. of extra bits added is appended to the key.
    key += char(extra_bit + '0');
    //cout << s << endl;
    cout << "\nConverting to hexadecimal\n";
    s = convertBinToHex(s);
    //cout << s << endl;

    // After hex conversion the key is attached to this string.
    s += key;
    cout << "\nHexa after adding key\n";
    //cout << s << endl;

    // This string is then shuffled to generate the final cipher text.
    s = encrypteqn(s, s.size());
    return s;
}

string decryptfinal(string s)
{
    // Recieved cipher text is first reshuffled to get the original hex string.
    s = decrypteqn(s, s.size());
    cout << "\nBack to hexa\n";
    //cout << "---" << s << "---" << endl;

    // Extracting key from the hex string
    int base_len, shift;
    char c = s[s.size() - 1];
    s.pop_back();
    string key = "";
    int n = s.size();
    for (int i = n - 1 - 5; i < n; i++)
        key += s[i];
    for (int i = n - 1 - 5; i < n; i++)
        s.pop_back();

    // The data part of the hex string is converted to binary and extra bits are removed.
    cout << "\nConverting to binary \n";
    s = HexToBin(s);
    //cout << s << endl;
    cout << "\nMaking unsuitable\n";
    int extra_bit = c - '0';
    //cout << extra_bit << endl;
    s = makeunsuitable(s, extra_bit);
    //cout << s << endl;

    while (key.size())
    {
        // Bit manipulations are reversed based on the key.
        char x = key[key.size() - 1];
        key.pop_back();
        char z, y;
        switch (x)
        {
        case '0':
            cout << "\n prime_decrypt();" << endl;
            s = pdecrypt(s);
            //cout << s << endl;
            break;
        case '1':
            cout << "\n even_shift();" << endl;
            s = even_odd_shift(s);
            //cout << s << endl;
            break;
        case '2':
            y = key[key.size() - 1];
            key.pop_back();
            base_len = y - '0';
            cout << "\n padding();" << endl;
            s = remove_padding(s, base_len);
            //cout << s << endl;
            break;
        case '3':
            z = key[key.size() - 1];
            key.pop_back();
            shift = z - '0';
            cout << "\n right_shift();" << endl;
            s = rightShift(s, shift);
            //cout << s << endl;
            break;
        }
    }
    s = Binary_To_ascii(s);
    return s;
}

int main()
{
    srand(time(NULL));
    int ch;
    string s;

    while (1)
    {
        cout << "\n1.Encrypt\n2.Decrypt\n3.Exit\nEnter choice\t";
        cin >> ch;
        cin.ignore(256, '\n');
        switch (ch)
        {
        case 1:
            cout << "\nEnter the plain string\t";
            getline(cin, s);
            s = encryptfinal(s);
            cout << "\nYour Cipher Text:\n"
                 << s << endl;
            break;
        case 2:
            cout << "\nEnter the encrypted string\t";
            getline(cin, s);
            s = decryptfinal(s);
            cout << "\nYour Plain Text:\n"
                 << s;
            break;
        case 3:
            exit(0);
        }
    }
}
