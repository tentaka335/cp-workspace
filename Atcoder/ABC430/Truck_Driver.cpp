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
    ll n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
   vll SA(n+2),SB(n+2);
    rep(i,n) {
        if(s[i]=='a') {
            SA[i+1] = SA[i] +1;
            SB[i+1] = SB[i];
        }
        else {
            SA[i+1] = SA[i];
            SB[i+1] = SB[i]+1;
        }
    }
    SA[n+1] = inf;
    SB[n+1] = inf;

    s  = '1' + s;
    ll ans = 0;
    for(ll i = 1;i<=n;i++) {
        ll ang = i-1;
        ll aok = n+1;
        while(aok - ang>1) {
            ll mid = ang +(aok - ang)/2;
            if(SA[mid] - SA[i-1]>=a) aok = mid;
            else ang = mid;
        }
        if(aok ==n+1) continue;
        ll bok = i - 1;
        ll bng  = n+1;
        while(bng - bok>1) {
            ll mid = bok +(bng - bok)/2;
            if(SB[mid]-SB[i-1]<b) bok = mid;
            else bng = mid;
        }
        if(bok ==i-1) continue;
        if(bok - aok>=0) ans+=bok - aok +1; 
    }
    cout <<ans << "\n";
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}