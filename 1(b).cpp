// ques 1(b)
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
            if (s[i] == '0' || s[i] == '1')
                continue;
            else
            {
                count = 1;
                break;
            }
        }
        if (count == 1)
            cout << "You put wrong alphabets." << endl;
        else if (s[0] == '0' && len % 2 == 1)
            cout << "Accepted" << endl;
        else if (s[0] == '1' && len % 2 == 0)
            cout << "Accepted" << endl;
        else
            cout << "Rejected" << endl;
    }
    return 0;
}