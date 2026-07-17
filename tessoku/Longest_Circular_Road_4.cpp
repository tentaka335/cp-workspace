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
 
 


 Graph G(100009);
 vvll len(100009,vll(2));
vector<bool> seen(100009);

 vll dfs(ll pos) {
    seen[pos] = true;
    vll res(2);
    nfor(i,0,G[pos].size()) {
        ll nex = G[pos][i];
        if(seen[nex]==false) {
            auto nres = dfs(nex);
            len[pos].push_back(nres[0]+1);
            sort(rall(len[pos]));
            len[pos].pop_back();
        }
    }

    res = len[pos];
    return res;
 }
 
 
 
 
 
void solve(){
 
 
 ll n;
 cin >> n;

 rep(i,n-1) {
    ll u,v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
 }


 dfs(1);


 ll ans = 0;
 nfor(i,1,n+1) {
    chmax(ans,len[i][0]+len[i][1]);
 }




 cout << ans+1 << "\n";
 

 
 
 
}

Graph G1;
vll len1;
vll len2;
vector<bool> seen1;
vector<bool> seen2;



void dfs2(ll pos,vll &len,vector<bool> &seen) {
    seen[pos] = true;
    rep(i,G1[pos].size()) {
        ll nex = G1[pos][i];
        if(seen[nex]==false) {
            len[nex] = len[pos]+1;
            dfs2(nex,len,seen);
        }
    }
}

void solve2() {
    
    ll n;
    cin >> n;
    G1 = vvll(n+9);
    len1 = vll(n+9);
    len2 = vll(n+9);
    seen1 = vector<bool> (n+9);
    seen2 = vector<bool> (n+9);

    rep(i,n-1) {
        ll u,v;
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }

    dfs2(1,len1,seen1);

    ll maxidx = max_element(all(len1)) - len1.begin();
    dfs2(maxidx,len2,seen2);
    cout << *max_element(all(len2))  + 1<< "\n";
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve2();
    return 0;
}