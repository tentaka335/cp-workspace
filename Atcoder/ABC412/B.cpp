#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s,t;
    set<char> T;
    cin >> s >> t;
    for (ll i = 0;i<t.size();i++) T.insert(t[i]);
    for (ll i = 1; i<s.size();i++) {
        if (isupper(s[i])) {
            if(T.count(s[i-1]) == 0) {
                cout << "No" << "\n";
                return 0;
            }
        }
    }
    cout << "Yes" << "\n";
}
