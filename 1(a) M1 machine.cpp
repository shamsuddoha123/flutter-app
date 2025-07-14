// ques 1(a)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    while (1)
    {
        string s;
        cout << "Enter the string : ";
        getline(cin, s);
        int i, count = 0;
        int len = s.length();
        for (i = 0; i < len; i++)
        {
            if (s[i] != 'a' && s[i] != 'b')
            {
                count = 1; // Invalid character
                break;
            }
        }
        int flag = 0;
        for (i = 0; i < len; i++)
        {
            if (flag == 0)
            {
                if (s[i] == 'a')
                    flag = 1;
                else if (s[i] == 'b')
                    flag = 0;
            }
            else if (flag == 1)
            {
                if (s[i] == 'a')
                    flag = 2;
                else if (s[i] == 'b')
                    flag = 2;
            }
            else if (flag == 2)
            {
                if (s[i] == 'a')
                    flag = 1;
                else if (s[i] == 'b')
                    flag = 0;
            }
        }
        if (count == 1)
            cout << "You put wrong alphabets." << endl;
        else if (flag == 1)
            cout << "Accepted" << endl;
        else
            cout << "Rejected" << endl;
    }
    return 0;
}