#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int flag = 0;

    getline(cin, s);  // read whole line including empty string

    // Check length at most 2
    if (s.length() > 2) {
        flag = 1;
    }

    // Check only 'a' or 'b' characters
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;

    return 0;
}
