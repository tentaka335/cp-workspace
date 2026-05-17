#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;
    vector<ll> pc(n+1,1);
    pc[0] =0;
    ll o =1;
    while(q--) {
        ll x,y;
        cin >> x >> y;
        ll res = 0;
        while(o<=x) {
            res +=pc[o];
            pc[y] +=pc[o];
            o++;
        }
        cout << res << "\n";
    } 
    

}