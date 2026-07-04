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
#define YES cout<<"Yes"<<"\n";
#define NO cout<<"No"<<"\n";
#define YN {cout<<"Yes"<<"\n";}else{cout<<"No"<<"\n";}
#define dame cout<<-1<<endl
const ll dx[8] = {1,0,-1,0,1,1,-1,-1};
const ll dy[8] = {0,1,0,-1,1,-1,-1,1};

// --------------------------------------------------------
// 1. テストしたいコード（元の solve 関数）
// cin/cout の代わりに、引数でクエリを受け取り、毎回の答えを vector で返す
// --------------------------------------------------------
vll solve_wrong(ll q, const vector<Pll>& queries) {
    vll ans;
    set<ll> s;
    rep(qi, q) {
        ll qt = queries[qi].first;
        ll h = queries[qi].second;
        if(qt == 1) {
            s.insert(h);
        }
        else {
            while(!s.empty() && *s.begin() <= h) {
                s.erase(*s.begin());
            }
        }
        ans.push_back(s.size()); // 比較のためにサイズを記録
    }
    return ans;
}

// --------------------------------------------------------
// 2. 正解の愚直解・想定解（元の solve2 関数）
// --------------------------------------------------------
vll solve_correct(ll q, const vector<Pll>& queries) {
    vll ans;
    priority_queue<ll, vll, greater<ll>> Q;
    rep(qi, q) {
        ll qt = queries[qi].first;
        ll h = queries[qi].second;
        if(qt == 1) {
            Q.push(h);
        }
        else {
            while(!Q.empty()) {
                if(Q.top() <= h) Q.pop();
                else break;
            }
        }
        ans.push_back(Q.size());
    }
    return ans;
}

// --------------------------------------------------------
// 3. ランダムケース生成とテスト実行
// --------------------------------------------------------
void generate_and_test() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int test_cases = 0;
    while(true) {
        test_cases++;
        
        // バグが起きやすいように、Qは小さめ（2〜10）に設定
        ll q = rng() % 9 + 2; 
        vector<Pll> queries(q);
        
        rep(i, q) {
            queries[i].first = rng() % 2 + 1; // qtは 1 か 2
            // 同じ値が複数回出現しやすいように、hの範囲をあえて極端に狭くする（1〜5）
            queries[i].second = rng() % 5 + 1; 
        }

        vll ans_wrong = solve_wrong(q, queries);
        vll ans_correct = solve_correct(q, queries);

        // 結果が一致しないケース（撃墜ケース）を発見したら出力して停止
        if (ans_wrong != ans_correct) {
            cout << "=================================\n";
            cout << "Found bug after " << test_cases << " tests!\n";
            cout << "=================================\n";
            cout << "[Test Case Input]\n";
            cout << q << "\n";
            rep(i, q) {
                cout << queries[i].first << " " << queries[i].second << "\n";
            }
            cout << "---------------------------------\n";
            
            cout << "[Expected (solve2)] ";
            for(auto x : ans_correct) cout << x << " "; 
            cout << "\n";
            
            cout << "[Output (solve)]    ";
            for(auto x : ans_wrong) cout << x << " "; 
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