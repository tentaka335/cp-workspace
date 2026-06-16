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
    string s;
    cin >> s;
    map<Pll,ll> abc;
    map<ll,ll> ab;
    map<ll,ll> bc;
    map<ll,ll> ca;
    vll SA(n+1),SB(n+1),SC(n+1);
    rep(i,n) {
        SA[i+1] = SA[i];
        SB[i+1] = SB[i];
        SC[i+1] = SC[i];
        if(s[i]=='A') SA[i+1]++;
        else if(s[i]=='B') SB[i+1]++;
        else SC[i+1]++;
            
        abc[{SA[i+1]-SB[i+1],SC[i+1] - SA[i+1]}]++;
        ab[SA[i+1]-SB[i+1]]++;
        bc[SB[i+1]-SC[i+1]]++;
        ca[SC[i+1]-SA[i+1]]++;
    }
    abc[{0,0}]++;
    ab[0]++;
    ca[0]++;

    ll ans = n*(n+1)/2;
    ll aeb = 0;
    ll bec = 0;
    ll cea = 0;
    ll aebec = 0;

    for(ll i = 0;i<n;i++) {//左端l-1を固定したときの
        aeb+=ab[SA[i]-SB[i]]-1;
        bec+=bc[SB[i]-SC[i]]-1;
        cea+=ca[SC[i]-SA[i]]-1;
        aebec+=abc[{SA[i]-SB[i],SC[i]-SA[i]}]-1;
    }

    ans-=aeb+bec+cea-2*aebec;

    cout << ans << "\n";
    


}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}