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
const ll dx[8] = {0,0,1,-1,-1,1,-1,1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
    return 0;
}

//前計算O(n) クエリ(1)

vector<ll> fac,finv,inv;

//二項係数の前計算
//n:=二項係数xCyを求める時の最大のx
void COMinit(ll n) {
    fac.resize(n+1);
    finv.resize(n+1);
    inv.resize(n+1);
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(ll i = 2;i<=n;i++) {
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

// 二項係数の演算
ll COM(ll n,ll k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}