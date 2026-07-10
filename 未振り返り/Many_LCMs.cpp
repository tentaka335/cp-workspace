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
 
 
 
struct Eratosthenes {
    // テーブル
    vector<bool> isprime;
    
    // 整数 i を割り切る最小の素数
    vector<int> minfactor;

    // コンストラクタで篩を回す
    Eratosthenes(int N) : isprime(N+1, true),
                          minfactor(N+1, -1) {
        // 1 は予めふるい落としておく
        isprime[1] = false;
        minfactor[1] = 1;

        // 篩
        for (int p = 2; p <= N; ++p) {
            // すでに合成数であるものはスキップする
            if (!isprime[p]) continue;

            // p についての情報更新
            minfactor[p] = p;
            
            // p 以外の p の倍数から素数ラベルを剥奪
            for (int q = p * 2; q <= N; q += p) {
                // q は合成数なのでふるい落とす
                isprime[q] = false;
                
                // q は p で割り切れる旨を更新
                if (minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }

    // 高速素因数分解
    // pair (素因子, 指数) の vector を返す
    vector<pair<int,int>> factorize(int n) {
        vector<pair<int,int>> res;
        while (n > 1) {
            int p = minfactor[n];
            int exp = 0;

            // n で割り切れる限り割る
            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }  
};
 
 
 
 Eratosthenes er(10000009);

 int mod_pow(int n, int p, int mod){
    n = n % mod;     
    if(n < 0){
        n = n + mod;
    }
    int res = 1;
    int pw=n;
    while(p > 0){
        if(p & 1){
            res = res * pw % mod;
        }
        pw = pw * pw % mod;
        p = p >> 1;
    }
    return res;
}
 
void solve(){
 
 ll n;
 cin >> n;
 vll A(n);
 map<ll,vector<Pll>> P;
 rep(i,n) {
    cin >> A[i];
    auto v = er.factorize(A[i]);
    for(auto [p,c]:v) {
        P[p].push_back({c,i});
        sort(rall(P[p]));
        if(P[p].size()>=3) P[p].pop_back();
    }
 }

 vvll no1(n);

 mint ans = 1;
for(auto &pv:P) {
    ll p = pv.first;
    auto [c,idx] = pv.second[0];
    if(pv.second.size()>=2) {
        auto [nx,iidx] = pv.second[1];
        if(nx!=c) {
            no1[idx].push_back(p);
        }
    } else {
        no1[idx].push_back(p);
    }//no1を見つけておく処理


    //semiansの作成
    ans*=mod_pow(p,c,MOD);
}


rep(i,n) {
    if(no1[i].size()==0) {
        cout << ans.val() << " ";
    }
    else {
        mint temp = ans;
        for(auto p : no1[i]) {
            temp/=mod_pow(p,P[p][0].first,MOD);
            if(P[p].size()>=2) {
                temp*=mod_pow(p,P[p][1].first,MOD);
            }
        }
        cout << temp.val() << " ";
    }
}

cout << "\n";



 
 
 
 
 
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t;
    cin >> t;
    
    
 rep(ti,t) solve();
    return 0;
}