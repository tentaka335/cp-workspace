#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k,p;
    cin >> n >> k >> p;
    vector<ll> A,B;
    rep(i,n) {
        ll a;
        cin >>a;
        if(i<n/2) A.push_back(a);
        else B.push_back(a);
    }
    
    auto f = [&](vector<ll> &V)->vector<vector<ll>> {
        ll len = V.size();
        vector<vector<ll>> res(len+1); 
        for(ll i = 0;i<(ll(1)<<len);i++) {
            ll cnt = 0;
            ll sum = 0;
            for(ll j = 0;j<len;j++) {
                if(((i>>j) & 1) == 1) {
                    cnt++;
                    sum +=V[j];
                }
            }
            res[cnt].push_back(sum);
        }
        
        for(ll i = 0;i<=len;i++) {
            if(res[i].size()>=1) sort(all(res[i]));
        }

        return res;
    };

    ll ans = 0;
    auto aa = f(A);
    auto bb = f(B);
    ll alen = aa.size();
    for(ll i = 0;i<alen;i++) {
        for(ll j = 0;j<aa[i].size();j++) {
            ll asum = aa[i][j];
            ll cnt = k - i;
            if(cnt<0||cnt>B.size()) continue;
            auto it = upper_bound(all(bb[cnt]),p-asum);
            if(it==bb[cnt].begin()) continue;
            ll pos = it - bb[cnt].begin();
            ans+=pos;
        }
    }

    cout << ans << "\n";

    return 0;
}