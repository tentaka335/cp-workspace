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
    
    ll n,m,c;
    cin >> n >> m >> c;
    map<ll,ll> B;

    rep(i,n) {
        ll a;
        cin >> a;
        B[a]++;
        B[a+m]++;
    }
    ll ans = 0;
  
    vector<Pll> A;
    
    for(auto p : B) {
        if(A.size()==0) A.push_back({p.second,p.first});
        else {
            ll len = A.size();
            A.push_back({A[len-1].first+p.second,p.first});     
           }
    }
    ll len = A.size();
    ll left = 0;
    rep(i,len) {
        if(A[i].second>=m) break;
       while(left<2*len) {
        if(A[left].first - A[i].first<c) {
            left++;
        }
        else break;
       }
       ans+=(A[i+1].second - A[i].second)*(A[left].first - A[i].first);
    }

    cout << ans << "\n";
    return 0;
}