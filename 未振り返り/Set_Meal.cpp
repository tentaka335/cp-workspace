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
 
 
 ll n,m,l;
 cin >> n >> m >> l;
 vector<Pll> a(n),b(m);
 rep(i,n) {
    ll A;
    cin >> A;
    a[i] = {A,i};
 }
 rep(i,m) {
   ll B;
   cin >> B;
   b[i] = {B,i};
 }
 sort(rall(a));
 sort(rall(b));
 priority_queue<tuple<ll,ll,ll>> Q;
 set<Pll> cant;
 set<Pll> seen;
 rep(i,l) {
    ll c,d;
    cin >> c >> d;
    c--;d--;
    cant.insert({c,d});
 }
 

 Q.push({a[0].first+b[0].first,0,0});
 seen.insert({0,0});
while(!Q.empty()) {
    auto [c,x,y]  = Q.top();
    Q.pop();
    
    if(!cant.count({a[x].second,b[y].second})) {
        cout << c << "\n";
        return ;
    }
    
    if(x+1<n) {
        if(!seen.count({x+1,y})) {
            Q.push({a[x+1].first+b[y].first,x+1,y});
            seen.insert({x+1,y});
        }
    }
    if(y+1<m) {
        if(!seen.count({x,y+1})) {
            Q.push({a[x].first+b[y+1].first,x,y+1});
            seen.insert({x,y+1});
        }
    }
    

    

    
}
 

 
 
 
}


ll f(ll a,ll b) {
    return max(a,b);
}
ll e() {
    return -inf;
}
void solve2() {
    ll n,m ,l;
    cin >> n >> m >> l;
    vll A(n+1);
    vll B(m+1);
    segtree<ll,f,e> seg(m+1);
    rep(i,n) {
        cin >> A[i+1];
    }
    rep(i,m) {
        cin >> B[i+1];
        seg.set(i+1,B[i+1]);
    }
    vvll C(n+1);
    rep(i,l) {
        ll c,d;
        cin >> c >> d;
        C[c].push_back(d);
    }

    ll ans = 0;

    nfor(i,1,n+1) {
        ll len = C[i].size();
        rep(j,len) {
            seg.set(C[i][j],-inf);
        }
        ll temp = seg.all_prod();
        chmax(ans,temp+A[i]);
        rep(j,len) {
            seg.set(C[i][j],B[C[i][j]]);
        }
        
    }

    cout << ans << "\n";
    return ;
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve2();
    return 0;
}