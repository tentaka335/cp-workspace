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

/*
ll n,k;

vector<ll> A(200009);
vector<bool> seen(200009);
vector<bool> seen2(200009);
scc_graph scc(200009);


ll ans = 0;
ll ame = 0;

ll ame2 = 0;


void dfs2(ll pos,ll c) {
    ans+=A[pos];
    ame2 = (ame2 +A[pos])%n;

    if(c==1) return ;

    dfs2(ame2,c-1);
    
    
}


void dfs(ll pos,ll c) {
    
    seen[pos] = true;
    ame = (ame + A[pos])%n;
    if(ame == pos) {
        ans+=c*A[pos];
        return ;
    }
    ans+=A[pos];

    scc.add_edge(pos,ame);

    if(c==1) return ;

    if(seen[ame] == false) {
        dfs(ame,c-1);
    }
    else {
        auto g = scc.scc();
        ll remain = c - 1;
        rep(i,g.size()) {
            if(g[i].size()>=2) {
                auto cycle = g[i];
                ll amari = (remain)%cycle.size();
            
               if(amari>=1) {
                ame2 = ame;
                dfs2(ame,amari);
               }
                rep(j,cycle.size()) {
                    ans+= (remain/(cycle.size()))*A[cycle[j]];
                }
                break;
            }
        }
        return;
    }


    

    


    

}






   


void solve(){


    cin >> n >> k;

    rep(i,n) cin >> A[i];

    dfs(0,k);


    cout << ans << "\n";



    
    
   

    

}
*/


void solve2() {//nxt[i][j] : アメの余りが $j$ の状態から、$2^i$ 回操作した後の「アメの余り（次の頂点）」sum_add[i][j] : 
    //アメの余りが $j$ の状態から、$2^i$ 回操作する間に「追加されるアメの合計個数」

ll n,k;
cin >> n >> k;
vll A(n);
rep(i,n) cin >> A[i];
vvll nxt(50,vll(n+9));
vvll sum_add(50,vll(n+9));

rep(j,n) {
    nxt[0][j] = (j+A[j])%n;
    sum_add[0][j] = A[j];
}

for(ll i = 1;i<50;i++) {
    rep(j,n) {
        nxt[i][j] = nxt[i-1][nxt[i-1][j]];
        sum_add[i][j] = sum_add[i-1][j] + sum_add[i-1][nxt[i-1][j]];
    }
}

ll pos = 0;

ll ans = 0;




for(ll i = 0;i<41;i++) {
    if((k>>i)&1) {
        ans += sum_add[i][pos];
        pos = ans%n;
    }
}

cout << ans << "\n";




}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve2();
    return 0;
}