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
void solve(){
    ll n;
    cin >> n;
    ll ans = 2000*2000;
    vvll sum(2009,vll(2009));
    vll U(n),D(n),L(n),R(n);
    rep(i,n) {
        ll u,d,l,r;
        cin >> u >> d >> l >> r;
        U[i] = u;
        D[i] = d;
        L[i] = l;
        R[i] = r;
        sum[u][l]++;
        sum[d+1][l]--;
        sum[u][r+1]--;
        sum[d+1][r+1]++;
    }
    for(ll i = 1;i<=2000;i++) {
        for(ll j = 1;j<=2000;j++) {
            sum[i][j] +=sum[i][j-1];
        }
    }
    for(ll i = 1;i<=2000;i++) {
        for(ll j = 1;j<=2000;j++) {
            sum[i][j]+=sum[i-1][j];
        }
    }
    
    vvll one(2009,vll(2009));
    for(ll i = 1;i<=2000;i++) {
        for(ll j = 1;j<=2000;j++) {
            if(sum[i][j]!=0) ans--;
            if(sum[i][j]==1) one[i][j]++;
        }
    }
    vvll onesum(2009,vll(2009));
    for(ll i = 1;i<=2000;i++) {
        for(ll j = 1;j<=2000;j++) {
            onesum[i][j] +=onesum[i][j-1]+one[i][j];
        }
    }
    for(ll i = 1;i<=2000;i++) {
        for(ll j = 1;j<=2000;j++) {
            onesum[i][j] +=onesum[i-1][j];
        }
    }




    rep(i,n) {
        ll u = U[i];
        ll d = D[i];
        ll l = L[i];
        ll r = R[i];
        ll onenum = 
        onenum = onesum[d][r] - onesum[u-1][r] - onesum[d][l-1] + onesum[u-1][l-1];
        cout << ans+onenum << "\n";
    }

    
    //考察2分　実装13分
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}