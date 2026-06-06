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
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
//using mint = modint998244353;
using mint = modint1000000007;
//using mint = modint;
#define YES cout<<"Yes"<<"\n";
#define NO cout<<"No"<<"\n";
#define YN {cout<<"Yes"<<"\n";}else{cout<<"No"<<"\n";}// if(a==b)YN;
#define dame cout<<-1<<endl
//mint::set_mod(m);//main関数下で扱う用
const ll dx[8] = {1,0,-1,0,1,1,-1,-1};
const ll dy[8] = {0,1,0,-1,1,-1,-1,1};

vector<bool> seen(100009);
Graph G(100009);
vector<ll> in(100009);
vector<vector<mint>> dp(100009,vector<mint>(3)); //dp[i][j] :=頂点iとする部分木において、iを含まない部分木の連結成分はa,bもふくむ(この先連結してa,bを新しく追加することができないから自己完結していないといけない)かつiを含む連結成分の状態がj(j=0,aのみ、j=1,bのみ、j = 2、a,b両方)のパターン　答えはdp[1][2]
vector<char> c(100009);


void dfs(ll pos,ll pre) {//木はpreを持つとよい。seenがいらない// a　bは対称　,処理も対称になるはず。
    
    mint val1 = 1,val2 = 1;
    rep(i,G[pos].size()) {
         ll nex = G[pos][i];
        if(nex==pre) continue;
        dfs(nex,pos);
        if(c[pos] == 'a') {
            val1 *= dp[nex][0] + dp[nex][2];
        }
        else {
             val1 *= dp[nex][1] + dp[nex][2];
        }
        
        val2*=dp[nex][0]+dp[nex][1] + 2*dp[nex][2];//2倍なのは、nexとの辺を切らない場合はnexの部分木はposの連結成分がa,b両方含むから度のパターンでも大丈夫で、切る場合はnexの部分木がa,b両方含んでいないといけないから、dp[nex][2]のみok
    }


    
    if(c[pos]=='a') {
        dp[pos][0] = val1;
    }
    else {
        dp[pos][1] = val1;
    }

    dp[pos][2] = val2 - val1;

    return ;
    
}


void solve(){

    ll n;
    cin >> n;
    for(ll i = 1;i<=n;i++) cin >> c[i];

    rep(i,n-1) {
        ll a,b;

        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1,-1);

    
    cout << dp[1][2].val() << "\n";



    

}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}