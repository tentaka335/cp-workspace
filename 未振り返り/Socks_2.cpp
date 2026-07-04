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

 
 
 
 
 
void solve(/*ll n,ll k,vll A*/){
 ll n,k;
 cin >> n >> k;
 
 vll A(k+2);
 nfor(i,1,k+1) cin >> A[i];
 

A[0] = -1e9;
A[k+1] = 1e9;
set<ll> s;
rep(i,k) s.insert(i+1);
s.insert(0);
s.insert(k+1);

set<tuple<ll,ll,ll>> Q;

rep(i,k+1) {
    Q.insert({A[i+1] - A[i],i,i+1});
}
ll ans =  0;
ll cnt = 0;
while(cnt<k/2) {
  // キューの先頭（最小コスト）を取得して削除
    auto [c, l, r] = *Q.begin();
    Q.erase(Q.begin());

    // すでに他のペアとして使われて s から消えている要素ならスキップ（遅延削除）
    if (s.find(l) == s.end() || s.find(r) == s.end()) {
        continue;
    }

    // 有効なペアとして確定
    cnt++;
    ans += c;
    
    // s から使用済みの靴下を消去
    s.erase(l);
    s.erase(r);
    
    // 左右の隣接する靴下を探す
    auto ml = s.lower_bound(l);
    ml--;
    auto mr = s.lower_bound(r);

    // Undo用のコスト（今回結んだペアをキャンセルして、外側と結び直す差額）を計算して追加
    ll new_c = (A[l] - A[*ml]) + (A[*mr] - A[r]) - c;
    Q.insert({new_c, *ml, *mr});
}


cout << ans << "\n";
 
 
}

ll naive(ll n,ll k,vll A) {
    
}
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    /*RandomGenerator random;

    ll n = random.nextInt(1,10);
    ll k = random.nextInt(1,n);

    set<ll> s;
    while(s.size()<k) {
        ll a = random.nextInt(1,n);
        s.insert(a);
    }
    vector<ll> A(k+2);
    auto it = s.begin();
    nfor(i,1,k+1) {
     A[i] = *it;
     it++;
    }*/

    
    
    
solve();
 
    return 0;
}