#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    if (n<=2) {
        cout << "No" << "\n";
        return 0;
    }
    string s;
    cin >> s;

    if (s.substr(n-3,3) == "tea") cout << "Yes" << "\n";
    else cout << "No" << "\n";

    
}
