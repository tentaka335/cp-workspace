#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll l,r,d,u;
    cin >> l >> r >> d >> u;
    ll maxk = max({llabs(l),llabs(r),llabs(d),llabs(u)});
    ll ans = 0;
    for(ll i = l;i<=r;i++) {
        if(llabs(i)%2==1) continue;
        ll k = llabs(i);
        if(k<d||u<-k) continue;
        if(u<=k&&-k<=d) ans+= u - d + 1;
        else ans += min(k,u) - max(-k,d) +  1;
    }

      for(ll i = d;i<=u;i++) {
        if(llabs(i)%2==1) continue;
        ll k = llabs(i);
        if(k<l||r<-k) continue;
        if(r<=k&&-k<=l) ans+= r - l  + 1;
        else ans += min(k,r) - max(-k,l) +  1;
    }
    
    
    for(ll i = 2;i<=maxk;i++) {
        if(i%2==1) continue;
        if(d<=i&&i<=u&&l<=i&&i<=r) ans--;
        if(d<=i&&i<=u&&l<=-i&&-i<=r) ans--;
        if(d<=-i&&-i<=u&&l<=i&&i<=r) ans--;
        if(d<=-i&&-i<=u&&l<=-i&&-i<=r) ans--;
    }
    if(d<=0&&0<=u&&l<=0&&0<=r) ans--;
    cout << ans;

    return 0;
}