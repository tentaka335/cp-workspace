#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    priority_queue<ll,vector<ll>,greater<ll>> A;

    for(ll i = 0;i<q;i++) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll x;
            cin >> x;
            A.push(x);
        }
        else if(qt == 2) cout << A.top() << "\n";
        else A.pop();
    }
    
}