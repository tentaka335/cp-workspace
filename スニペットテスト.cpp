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
 ll MOD ;
const ll MOD2 = 998244353;
const ll dx[8] = {1,-1,0,0,1,-1,1,-1};
const ll dx[8] = {0,0,1,-1,-1,1,-1,1};


//---前計算O(n) クエリ(1)  --- 0<=n<=10^7程度まで可能

vector<long long> fac,finv,inv;//fac[i] = i!,finv[i] = (i)!^-1,inv[i] = i^-1

//二項係数の前計算
//n:=二項係数xCyを求める時の最大のx
void nCkinit( long long n) {
    fac.resize(n+1);
    finv.resize(n+1);
    inv.resize(n+1);
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for( long long i = 2;i<=n;i++) {
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;//aの逆元はa^p-2であることを用いていない。 p = p/a * a+p%a,0≡p/a*a + p%a 0≡p/a +(p%a)*a^-1 よってa^-1 ≡ -(p/a)/(p%a) この割り算は切り捨てではないので、逆元をかける;
         //mod%iの値はi未満なのでinv[i]を求める時点で、inv[MOD%i]はすでに求まっている。
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

// 二項係数の演算
 long long nCk( long long n, long long k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}


// ---前計算o(1) クエリO(k)-----
//固定のnに対し高速化できるようにしたい

vector<long long> finv2,inv2;

//クエリ中のnCkのうち最大のkで初期化
void nCk2init( long long k) {
    finv2.resize(k+1);
    inv2.resize(k+1);
    finv2[0] = finv2[1] = 1;
    inv2[1] = 1;
    for( long long i = 2;i<=k;i++) {
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
         finv2[i]=finv2[i-1]*inv2[i]%MOD;
    }
    return ;
}

 long long nCk2( long long n, long long k) {
    
    if(n<k||n<0||k<0) return 0;


    long long res = 1;
    
    for(long long i = n;i>= n - k+1;i--) {
        res = res*i%MOD;
    }
    
    return res*finv2[k] % MOD;

}
//-------------------------------------



int main () {
    ll t;
    cin >> t >> MOD;
    nCkinit(10000009);
    rep(ti,t) {
        ll n,k;
        cin >> n >> k;
        cout << nCk(n,k) << "\n";
    }
}


