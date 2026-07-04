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
 
 
 
 template <typename T>
struct PrimeFact {
    vector<T> spf;
    PrimeFact(T N) { init(N); }
    void init(T N) { // 前処理。spf を求める
        spf.assign(N + 1, 0);
        for (T i = 0; i <= N; i++) spf[i] = i;
        for (T i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (T j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    map<T, T> get(T n) { // nの素因数分解を求める
        map<T, T> m;
        while (n != 1) {
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};
 
 
 
 
ll solve(ll n,vll A){
 
 
 PrimeFact pf(200009);

 map<set<ll>,ll> s;
 ll ans = 0;
 ll zero = 0;
 rep(i,n) {
    if(A[i]==0) {
        zero++;
        ans+=n - zero;
    }
    else {
        auto m = pf.get(A[i]);
        set<ll> ss;
        for(auto [p,c] :m) {
            if(c%2==1) ss.insert(p);
            
        }
        if(ss.size()==0) ss.insert(0);
        s[ss]++; 
    }
 }

 
 
 for(auto &p : s) {
    ll c = p.second;
    ans+=c*(c-1)/2;
 }


 return ans;
 
 
 
}
long long isqrt(long long n) {
    if(n<=0) return 0;
    ll m = sqrt(n);
    while((m+1)*(m+1)<=n) m++;
    while(m*m>n)m--;
    return m;
}

ll naive(ll n,vector<ll> A) {
    ll ans = 0;
    nfor(i,0,n-1) {
        nfor(j,i+1,n) {
            if(A[i]*A[j]==isqrt(A[i]*A[j])*isqrt(A[i]*A[j])) {
                ans++;
            }
        }
    }

    return ans;
}



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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    

    ll n;
    cin >> n;
    vll A(n);
    rep(i,n) cin >> A[i];
    cout << solve(n,A) << "\n";
    /*RandomGenerator random;
    
    ll n = random.nextInt(2,10000);
    vll A(n);
    rep(i,n) {
        ll a  = random.nextInt(0,100);
        A[i] = a;
    }
    rep(j,100) {
    ll ans = solve(n,A);
    ll ans2 = naive(n,A);
    if(ans!=ans2) {
        cerr << "n:" << n <<"\n";
        rep(i,n) cerr << A[i] << " ";
        cerr << "\n";
        cerr << ans <<  " " << ans2 <<  "\n";
    } else YES;
}
    */
    
 
    return 0;
}