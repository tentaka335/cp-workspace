#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a,ll b,ll c) {
    ll l = 0,r=600000001;
    while(l-r>1) {
        ll mid = (r+l)/2;
        if(a*mid*mid+b*mid+c<=0) l = mid;
        else r = mid;
    }
    if (a * l * l + b * l + c == 0) return l;
    return -1;
}

int main () {
    ll n;
    cin >> n;
    for(ll d = 1;d*d*d<=n;d++) {
        if(n%d!=0) continue;
        ll m = n/d;
       ll k = solve(3,3*d,d*d-m);
       if(k>=1) {
        cout << d+k << " " << k << "\n";
        return 0;
       }
    }
    cout << -1 << "\n";
}


