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

using mint2 = modint1000000007;
#define YES cout<<"Yes"<<"\n";
#define NO cout<<"No"<<"\n";
#define YN {cout<<"Yes"<<"\n";}else{cout<<"No"<<"\n";}// if(a==b)YN;
#define dame cout<<-1<<endl

const ll dx[8] = {1,0,-1,0,1,1,-1,-1};
const ll dy[8] = {0,1,0,-1,1,-1,-1,1};
 
 
 
 
 
 
 
void solve(){
 
 string a,b;
 cin >> a  >> b;
 ll n = a.size();
 
pair<mint,mint2> ha,hb;

vector<mint> ten1(n+1);
vector<mint2> ten2(n+1);
ten1[0] = 1;
ten2[0] = 1;
nfor(i,1,n+1) {
    ten1[i] = 2*ten1[i-1];
    ten2[i] = 2*ten2[i-1];
} 
//bのハッシュ
rep(i,n) {
    hb.first +=(b[i] - '0')*ten1[i];
    hb.second +=(b[i] - '0')*ten2[i];
    ha.first +=(a[i] - '0')*ten1[i];
    ha.second +=(a[i] - '0')*ten2[i];
}
ll ans = 0;

if(ha==hb) {
    cout << ans << "\n";
    return ;
}



rep(i,n-1) {
    
    if(ha.first.val()%2==0)ha.first/=2;
    else {
        ha.first-=1;
        ha.first/=2;
    }
    ha.first+=(a[i]-'0')*ten1[n-1];
    
    if(ha.second.val()%2==0)ha.second/=2;
    else {
        ha.second-=1;
        ha.second/=2;
    }
    ha.second+=(a[i]-'0')*ten2[n-1];
    
    if(ha==hb) {
    cout << i+1 << "\n";
    return ;
}
}



dame;
return ;
 
 
 
 
}

void solve2() {
    string a,b;
    cin >> a >> b;
    ll m = ((ll)1<<61) - 1,A = 0,B = 0;
    ll n = a.size();
    rep(i,n) {
        A =( A + ((a[i] - '0')*((ll)1<<i))) %m;
        B = (B + ((b[i] - '0')*((ll)1<<i))) % m;
    }
    if(A==B) {
        cout << 0 << "\n";
        return ;
    }
    rep(i,n-1) {

        A/=2;
        A = ( A + (a[i] - '0')*((ll)1<<n-1)) % m;
        
         
        if(A==B) {
            cout << i + 1 << "\n";
            return ;
        }
    }

    dame;
    
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t;
    cin >> t;
    mint2::set_mod( 999999929);
    
 rep(ti,t)solve2();
    return 0;
}