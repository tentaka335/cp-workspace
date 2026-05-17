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
    
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = -1;
    ll osum = 0;
    bool headfind = false;
    rep(i,n) {
        if(s[i]=='-') {
            headfind = true;
            osum = 0;
        }
        if(s[i]=='o') {
            osum++;
            if(headfind==true) {
                chmax(ans,osum);
            }
        }
    }
    reverse(all(s));
    headfind = false;
    osum = 0;
        rep(i,n) {
        if(s[i]=='-') {
            headfind = true;
            osum = 0;
        }
        if(s[i]=='o') {
            osum++;
            if(headfind==true) {
                chmax(ans,osum);
            }
        }
    }
    cout << ans;
    
    return 0;
}


/*
sを順に前から見ていって-をみつけたら連続するoの数を数え、-1に初期化しておいたansを更新する
これにより-oooのパターンを発見することができる。
sを反転させて同様のアルゴリズムを動かすことで、ooo-のパターンも見つけることができる。
*/