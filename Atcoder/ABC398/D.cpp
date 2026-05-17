#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,r,c;
    cin >> n >> r >> c;
    string s;
    cin >> s;
    set<pair<ll,ll>> smoke;
    ll dx = 0;
    ll dy = 0;
    for(ll i = 0;i<n;i++) {
        smoke.insert(make_pair(dx,dy));
        if(s[i]=='N') dx++;
        if(s[i]=='S') dx--;
        if(s[i]=='W') dy++;
        if(s[i]=='E') dy--;
        if(smoke.count({r+dx,c+dy})) {
            cout << 1 ;
        }
        else {
            cout << 0;
        }
    }
}


