#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int countA = 0;
    int flag = 0; // 0 = valid, 1 = invalid

    getline(cin,s);

    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'a') {
            countA++;
        }
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1; // Invalid character
            break;
        }
    }

    if (flag == 0 && countA % 2!=0)
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;

    return 0;
}