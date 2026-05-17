#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;

    string S;
    cin >> S;

    for(ll i = 0;i<n-2;i++) {
        if (S[i] == S[i+1] && S[i] == S[i+2]) {
            cout << "Yes" << "\n";
            return 0;
        }
    }
    cout << "No" << "\n";
    return 0;
}