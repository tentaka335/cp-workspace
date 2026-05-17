#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    ll count=0,first=0,second = 0;
    
    for (ll i = 0; i<s.size();i++) {
        if(s[i] == '#') {
            if (first == 0) {
                first = i+1;
            }
            else {
                second = i + 1;
                cout << first <<"," << second << "\n";
                second = 0;
                first = 0;
            }
        }
    }
}
