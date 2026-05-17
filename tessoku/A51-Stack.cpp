#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    stack<string> S;
    for (ll i = 0;i<q;i++) {
        ll t;
        cin >> t;
        if(t == 1) {
            string x;
            cin >> x;
            S.push(x);
        }
        if(t==2) {
            cout << S.top() << "\n";
        }
        if(t==3) {
            S.pop();
        }
    }
}