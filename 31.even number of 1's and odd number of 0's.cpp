#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s); // read full input including empty string

    int count0 = 0, count1 = 0;
    int flag = 0; // flag = 1 means invalid character found

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            count0++;
        }
        else if (s[i] == '1') {
            count1++;
        }
        else {
            flag = 1; // invalid character
            break;
        }
    }

    if (flag == 1) {
        cout << "Rejected" << endl;
    }
    else if (count1 % 2 == 0 && count0 % 2 == 1) {
        cout << "Accepted" << endl;
    }
    else {
        cout << "Rejected" << endl;
    }

    return 0;
}