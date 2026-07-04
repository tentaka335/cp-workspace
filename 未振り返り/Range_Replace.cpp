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
 
 
 
 
 
 
 
 
ll solve(ll n,vector<ll> A){

    decltype(A)::iterator result = unique(all(A));
    A.erase(result,A.end());

    n = A.size();
    
    ll ans = n*(n+1)/2;

    map<ll,ll> m;

    rep(i,n) {
        m[A[i]]++;
    }

    rep(i,n) {
        ans-=m[A[i]];
        m[A[i]]--;
    }
    ans++;

    return ans ;
 
 
 
 
 
 
}

ll naive(ll n,vector<ll> A) {
    
    set<vll> s;
    for(ll l = 0;l<n;l++) {
        for(ll r = l;r<n;r++) {
            auto B = A;
            for(ll i = l;i<r;i++) {
                B[i] = A[l];
            }
            s.insert(B);
        }
    }
    return s.size();
}


void generate_and_test() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int test_cases = 0;
    while(true) {
        test_cases++;
        
        // バグが起きやすいように、Qは小さめ（2〜10）に設定
        ll q = rng() % 9 + 1; 
        vector<ll> queries(q);
        
        rep(i, q) {
            queries[i] = rng() % 2 + 1; // qtは 1 か 2
            // 同じ値が複数回出現しやすいように、hの範囲をあえて極端に狭くする（1〜5）
        }

        ll ans_wrong = solve(q, queries);
        ll ans_correct = naive(q, queries);

        // 結果が一致しないケース（撃墜ケース）を発見したら出力して停止
        if (ans_wrong != ans_correct) {
            cout << "=================================\n";
            cout << "Found bug after " << test_cases << " tests!\n";
            cout << "=================================\n";
            cout << "[Test Case Input]\n";
            cout << q << "\n";
            rep(i, q) {
                cout << queries[i] << " ";
            }
            cout << "---------------------------------\n";
            
            cout << "[Expected (solve2)] ";
            cout << ans_correct;
            cout << "\n";
            
            cout << "[Output (solve)]    ";
            cout << ans_wrong ; 
            cout << "\n";
            break;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 普段は標準入力から受け取る処理を書き、
    // ランダムテストを回す時は以下の関数を呼び出す
    generate_and_test();
    
    return 0;
}


