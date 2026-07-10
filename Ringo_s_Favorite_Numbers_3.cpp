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
const ll inf = 1e12;
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
 
 
 


 ll mypow(long long a, long long n) {
    if (n == 0) return 1;
    if (n == 1) return a ;

    long long ret = mypow(a, n / 2);
    (ret *= ret) ;
    if (n % 2 == 1) {
        (ret *= a) ;
    }
    return ret;
}
 
 
 
 
void solve(){
 

 
ll q;
cin >> q;

vll prime;

vector<bool> isp(1000009,true);

for(ll i = 2;i<=1000000;i++) {
    if(isp[i]) {
        for(ll j = 2;j*i<=1000000;j++) {
            isp[i*j] = false;
        }
        prime.push_back(i);
    }
}

vll ans;

ll n = prime.size();
ll cnt = 0;
for(ll ai = 0;ai<n&&prime[ai]<=1000;ai++) {
    for(ll bi = ai+1;bi<n&&prime[bi]<=1000000;bi++) {
        for(ll ap = 1;ap<20;ap++) {
            for(ll bp = 1;bp<13;bp++) {
                
                if((llll)mypow(prime[ai],2*ap)*(llll)mypow(prime[bi],2*bp)<=(llll)inf) {
                    ans.push_back(mypow(prime[ai],2*ap)*mypow(prime[bi],2*bp));
                    cnt++;
                    cerr << cnt << ":" << prime[ai] <<":" << ap<< ":" << prime[bi] << ":" <<bp << ":" ;
                    cerr << mypow(prime[ai],2*ap)*mypow(prime[bi],2*bp) << "\n";
                    
                }
                else break;
            }
        }
    }
}

sort(all(ans));
cout << ans.size() << " ";
rep(qi,q) {
    ll a;
    cin >> a;
    ll len = ans.size();
    ll ok = -1;
    ll ng = len;
    while(ng - ok>1) {
        ll mid = ok +(ng - ok)/2;
        if(ans[mid]<=a) ok = mid;
        else ng = mid;
    }

    cout << ans[ok] << "\n";
}
 
 
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    
    
 solve();
    return 0;
}