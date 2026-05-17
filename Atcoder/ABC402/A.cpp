#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string s;
    cin >> s;
    string ans;
    for(ll i = 0;i<s.size();i++) {
        if(isupper(s[i])) {
            ans += s[i];
        }
    }
    cout << ans << "\n";
}