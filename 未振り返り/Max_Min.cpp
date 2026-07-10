# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")

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
 vll A(n);
rep(i,n) cin >> A[i];
 sort(all(A));
ll ans = 0;
ll semians = 0;
rep(i,n-1) {
    if(i>=1&&A[i]==A[i-1]) {
        semians--;
        ans+=semians;
        continue;
    }
    ll div = A[i+1]/A[i];
    semians = 0;
    ll ok = i;
    while(ok<n-1) {
        ll before = ok;
        ok++;
        div = A[ok]/A[i];
    ll ng = n;
    while(abs(ok - ng)>1) {
        ll mid = ok +(ng - ok)/2;
        if(A[mid]<A[i]*(div+1)) ok = mid;
        else ng = mid;
    }
    ans+=div*(ok - before);
    semians+=div*(ok - before);
}
}

cout << ans << "\n";
 
 
}

void solve2() {
    ll n;
    cin >> n;
    vll A(n);
    rep(i,n) {
        cin >> A[i];
    }
    ll ans = 0;
    nfor(i,0,n-1) {
        nfor(j,i+1,n) {
            ans+=max(A[i],A[j])/min(A[i],A[j]);
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