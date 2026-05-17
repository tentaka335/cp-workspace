#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
    ll a = 0;
    a+= x%10;
    if (x>=10) a+= (x%100-x%10)/10;
    if (x>=100) a+= (x%1000-x%100-x%10)/100;
    if (x>=1000) a+= (x%10000-x%1000-x%100-x%10)/1000;
    if (x>=10000) a+= (x%100000-x%10000-x%1000-x%100-x%10)/10000;
    if (x>=100000) a+= (x%1000000-x%100000-x%10000-x%1000-x%100-x%10)/100000;
    return a;
    }


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll ans =1;
    for (ll i=1; i<n; i++) {
        ans+=f(ans);
    }
    cout << ans << endl;
}