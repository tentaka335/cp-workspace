#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    queue<string> Q;

    for(ll i = 0;i<q;i++) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            string s;
            cin >> s;
            Q.push(s);
        }
        else if(qt == 2) cout << Q.front() << "\n";
        if(qt == 3) Q.pop();
    }
}