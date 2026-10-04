#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif


#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define rrep(i,n) for(ll i = 1; i <= (n); ++i)
#define drep(i,n) for(ll i = (n)-1; i >= 0; --i)
#define nfor(i,s,n) for(ll i=s;i<n;i++)//i=s,s+1...n-1 ノーマルfor 半開区間 
#define dfor(i,s,n) for(ll i = (s)-1; i>=n;i--)//s-1スタートでnまで落ちる
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 998244353;
const ll MOD2 = 1e9 + 7;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = modint;
#define YES cout<<"Yes"<<"\n";
#define NO cout<<"No"<<"\n";
#define YN {cout<<"Yes"<<"\n";}else{cout<<"No"<<"\n";}// if(a==b)YN;
#define dame cout<<-1<<endl
//mint::set_mod(m);//main関数下で扱う用
const ll dx[8] = {1,0,-1,0,1,1,-1,-1};
const ll dy[8] = {0,1,0,-1,1,-1,-1,1};
 
 
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
 mint nCk( long long n, long long k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
 
 
 
 
 
void solve(){
 
    
 
 ll n,k;
 cin >> n >> k;
 nCkinit(n+9);
 mint ans = 0;

 mint suma = 0;
 vector<mint> A(n);
 rep(i,n) {
    ll a;
    cin >> a;
    A[i] = a;
    suma+=A[i];
 }
 rep(i,n){
    ans +=A[i]*(nCk(n-1,k-1)*A[i] + nCk(n-2,k-2)*(suma - A[i]));
 }


 cout << ans.val() << "\n";
  
 
 
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}