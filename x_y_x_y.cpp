#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll dx[8] = {1,-1,0,0,1,-1,1,-1};
const ll dy[8] = {0,0,1,-1,-1,1,-1,1};

/*
using mint = modint998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t;
    cin >> t;
    rep(ti,t) {
        ll n,m;
        cin >> n >> m;

        vector<ll> ten(20,1);
        vector<ll> modten(20,1);
        for(ll i = 1;i<=19;i++) {
            modten[i] = (modten[i-1]*10)%m;
        }
        for(ll i = 1;i<=18;i++) {
            ten[i] = ten[i-1]*10;
        }

        mint ans = 0;
        

        for(ll y = 1;y<=19;y++) {//y桁の数
            if(ten[y-1]>n) break;
            mint ynum;
            if(y==19) ynum = 1;
            else {
            ynum = min(ten[y]-ten[y-1],n-ten[y-1]+1);
            }
             

           ll  a = (modten[y] - 1+ m)%m;
           if(a==0) ans+=ynum*(n%MOD2);
           else {
            ll seki = m/gcd(a,m);
           ans +=ynum * ((n/seki));
           }
        }

        cout << ans.val() << "\n";


    
    }


    
    return 0;
}
*/
