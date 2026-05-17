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
    
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    if(sy%2==0&&sx%2==1) sx--;
    if(sy%2==1&&sx%2==0) sx--;
    if(ty%2==0&&tx%2==1) tx--; 
    if(ty%2==1&&tx%2==0) tx--; 
    ll ans = 0;
    ans +=llabs(sy - ty);

    if (llabs(sx-tx)-llabs(sy-ty)<=0) {
        cout << ans;
        return 0;
    };

    ll remain = llabs(sx-tx) - llabs(sy-ty); 
    ans+=llabs(remain)/2;
    cout << ans;

    
    

    return 0;
}