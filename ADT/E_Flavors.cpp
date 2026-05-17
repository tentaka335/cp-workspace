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
    
    ll n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll,ll>> F(n+1,{0,0});
    rep(i,n) {
        ll f,s;
        cin >> f >> s;
        if(F[f].first<=s) {
            F[f] = {s,F[f].first};
        }
        else if(F[f].second<=s&&s<F[f].first) {
            F[f] = {F[f].first,s};
        }
        chmax(ans,F[f].first+(F[f].second)/2);



       
    }
    vector<ll> maxf;
    for(ll i = 1;i<=n;i++) {
        maxf.push_back(F[i].first); 
    }
    sort(all(maxf));
    reverse(all(maxf));
    ll len = maxf.size();
    chmax(ans,maxf[0]+maxf[1]);
    cout << ans ;
    return 0;
}

/*
全部追加した後にsortするのが簡単でいいかも
でも計算量はO(n+n+nlogn)でこっちのが早そう
今回はフレーバがfであるアイスについて
*/