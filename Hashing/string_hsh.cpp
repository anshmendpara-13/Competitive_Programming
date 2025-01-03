#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string s;
    cin >> s;

    int hsh[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        hsh[s[i] - 'a']++;
    }

    int q;
    cin >> q;

    while (q--) {
        char c;
        cin >> c;

        if (c >= 'a' && c <= 'z') {
            cout << hsh[c - 'a'] << endl;
        } else {
            cout << "Invalid query!" << endl;
        }
    }

    return 0;
}
