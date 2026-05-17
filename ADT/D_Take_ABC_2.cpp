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

    string s;
    cin >>s;
    ll n = s.size();
    queue<ll> A,B,C;
    rep(i,n) {
        if(s[i]=='A') A.push(i);
        if(s[i]=='B') B.push(i);
        if(s[i]=='C') C.push(i);
    }
    if(A.empty()||B.empty()||C.empty()) {
        cout << 0;
        return 0;
    }

    ll ans = 0;
    while(true) {
        if(A.empty()||B.empty()||C.empty()) {
            cout << ans;
            return 0;
        }
        ll a = A.front();
        A.pop();
        while(a>B.front()) {
            B.pop();
            if(B.empty()) {
                cout << ans;
                return 0;
            }
        }

        ll b = B.front();
        B.pop();
         while(b>C.front()) {
            C.pop();
            if(C.empty()) {
                cout << ans;
                return 0;
            }
        }
        C.pop();
        ans++;
    }
  
    
    return 0;
}