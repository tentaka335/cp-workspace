#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,m,q;
    cin >> n >> m >>q;
    vector<set<ll>> problems(n+1);
    vector<bool> admin(n+1);
    for(ll i = 0;i<q;i++) {
        ll qt;
        cin >> qt;
        if(qt == 1) {
            ll x,y;
            cin >> x >> y;
            problems[x].insert(y);
        }
        else if(qt == 2) {
            ll x;
            cin >> x;
            admin[x] = true;
        }
        else if(qt == 3) {
            ll x,y;
            cin >> x >> y;
            if(admin[x] == true || problems[x].count(y)) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
    }
}