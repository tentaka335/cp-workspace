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



struct RandomGenerator {
    std::mt19937_64 rng;

    // デフォルトコンストラクタ: 実行ごとに異なる乱数シードを使用
    RandomGenerator() {
        std::random_device rd;
        rng.seed(rd());
    }

    // シード指定コンストラクタ: テストの再現性（デバッグ）のために固定シードを使用
    explicit RandomGenerator(uint64_t seed) {
        rng.seed(seed);
    }

    // 指定範囲 [min, max] の整数を生成 (閉区間)
    long long nextInt(long long min, long long max) {
        std::uniform_int_distribution<long long> dist(min, max);
        return dist(rng);
    }

    // 指定範囲 [min, max) の実数を生成 (半開区間)
    double nextDouble(double min, double max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rng);
    }

    // 指定した確率で true を返す真偽値を生成 (デフォルトは50%)
    bool nextBool(double true_probability = 0.5) {
        std::bernoulli_distribution dist(true_probability);
        return dist(rng);
    }

    // ランダムな文字列を生成 (デフォルトは英数字)
    std::string nextString(size_t length, const std::string& charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
        std::string result;
        result.reserve(length);
        std::uniform_int_distribution<int> dist(0, charset.length() - 1);
        for (size_t i = 0; i < length; ++i) {
            result += charset[dist(rng)];
        }
        return result;
    }

    // ランダムな整数の配列(vector)を生成
    std::vector<long long> nextIntVector(size_t size, long long min, long long max) {
        std::vector<long long> res(size);
        for (size_t i = 0; i < size; ++i) {
            res[i] = nextInt(min, max);
        }
        return res;
    }
};
 
 
 
 
 
 
 
 
ll solve(ll n,ll l,ll k,vll A){
 
    ll ok = 0;
    ll ng = l;

    while(abs(ok - ng)>1) {
        ll mid = ok +(ng - ok)/2;
        ll nowlen = 0;
        ll cnt = 0;
        bool can = false;
      nfor(i,0,n) {
        if(i>=1) nowlen+=A[i] - A[i-1];
        else nowlen+=A[i];
        if(nowlen>=mid) {
            cnt++;
            nowlen = 0;
            if(cnt>=k&& A[n-1] - A[i]>=mid) {
                can = true;
                break;
            }
        }
      }
      if(can) ok = mid;
      else  ng = mid;
    }
 

    return ok;
 
 
 
}

ll naive(ll n,ll l ,ll k,vll A) {

    ll ans = 0;
    for(ll bit = 0;bit<((ll)1<<n);bit++) {
        ll cut = 0;
        ll cnt = 0;
        ll minlen = inf;
        rep(i,n) {
            
            if((bit>>i)&1==1) {
                cnt++;
                chmin(minlen,A[i]-cut);
                cut = A[i];
            }
        } 
        chmin(minlen,l - cut);

        if(cnt==k) chmax(ans,minlen);
    }

    return ans;
    
}



int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    RandomGenerator random;
    

   nfor(i,1,100) {
    
    ll n = random.nextInt(1,4);
    ll l = random.nextInt(10,40);
    ll k = random.nextInt(1,n);
    set<ll> s;
    while(s.size()<n) {
        s.insert(random.nextInt(0,l-1));
    }

    vll A;
    auto it = s.begin();
    while(it!=s.end()) {
        A.push_back(*it);
        it++;
    }



    ll ans = solve(n,l,k,A);
    ll ans2 = naive(n,l,k,A);


    if(ans!= ans2) {
        NO;
        cout << "n:" << n <<"l:" << l << "k:" << k << "\n";
        rep(j,n) cout << A[j] <<" ";
        cout << "\n";
        cout << ans << " " << ans2 << "\n";
        
    }
    else cout << "match" << "\n";
}

 
    return 0;
}