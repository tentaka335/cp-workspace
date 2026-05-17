#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll k;
    string s;
    cin >> s >> k;
    sort(all(s));
    ll cnt = 0;
    do {
        cnt++;
        if(cnt==k) {
            cout << s;
            return 0;
        }

    } while(next_permutation(all(s)));
    
    return 0;
}

/*
do while文とnext_permutationを用いて、sortしたsを突っ込み、k番目に打ち切り出力するだけ。
*/