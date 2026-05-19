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
    
    ll n;
    cin >> n;
    vector<ll> A;
    rep(i,n) {
        ll a;
        cin >> a;
        A.push_back(a);
        while(true) {
            ll len = A.size();
            if(len<=1) break;
            
            if(A[len-1]!=A[len-2]) break;
            else {
                ll temp = A[len - 1];
                A.pop_back();
                A.pop_back();
                A.push_back(temp+1);
            }
        }
        


        
    
    }
    
    cout << A.size() << "\n";
    return 0;
}