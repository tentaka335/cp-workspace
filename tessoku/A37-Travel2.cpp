#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m,b,asum=0,csum=0;
    cin >> n >> m >> b;
    for(ll i = 0;i<n;i++) {
        ll a;
        cin >> a;
        asum +=a;
    }
        for(ll i = 0;i<m;i++) {
        ll c;
        cin >> c;
        csum +=c;
    }
    cout << m*asum+n*m*b+n*csum << "\n";
}