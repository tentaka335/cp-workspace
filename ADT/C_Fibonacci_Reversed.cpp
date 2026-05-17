#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;



ll x,y;

ll f(ll k ) {
    string s = to_string(k);
    reverse(all(s));
    return stol(s);
}

ll a (ll k) {
    if(k == 1) return x;
    if(k == 2) return y;

    return  f(a(k-1)+a(k-2));


}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> x >> y;
    
    cout << a(10);
    
    return 0;
}