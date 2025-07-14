#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    string s;
    getline(cin, s);
    int count = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] != 'a' && s[i] != 'b')
        {
            count = 1;
            break;
        }
    }
    int flag = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (flag == 0)
        {
            if (s[i] == 'a')
            {
                flag = 0;
            }
            else if (s[i] == 'b')
            {
                flag = 1;
            }
        }
        else if (flag == 1)
        {
            if (s[i] == 'a')
            {
                flag = 3;
            }
            else if (s[i] == 'b')
            {
                flag = 2;
            }
        }
        else if (flag == 2)
        {
            if (s[i] == 'a')
            {
                flag = 3;
            }
            else if (s[i] == 'b')
            {
                flag = 2;
            }
        }
        else if (flag == 3)
        {
            if (s[i] == 'a')
            {
                flag = 1;
            }
            else if (s[i] == 'b')
            {
                flag = 0;
            }
        }
    }

    if (count == 1)
    {
        cout << "put wrong alphabet" << endl;
    }
    else if (flag == 0 || flag == 2)
    {
        cout << "Accept" << endl;
    }
    else
    {
        cout << "Reject" << endl;
    }
    return 0;
}