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
    
    ll t;
    cin >> t;
    rep(ti,t) {
        ll n,a,b;
        cin >> n >> a >> b;
        a--;b--;
        if(n%2||(a+b)==0) {
            cout << "No\n";
            continue;
        }
        else {
            cout << "Yes\n";
            ll h = n,w = n;
            string s,t;
            while(true) {
                if(a>=2) {
                    s+=string(w-1,'R') + 'D';
                    s+=string(w-1,'L') + 'D';
                    a-=2;h-=2;
                }
                else if(h - a >2) {
                    t+=string(w-1,'R') + 'D';
                    t+=string(w-1,'L') + 'D';
                    h-=2;
                }
                else if(b>=2) {
                    s+=string(h-1,'D') + 'R';
                    s+=string(h-1,'U') + 'R';
                    w-=2;b-=2;
                }
                else if(w-b>2) {
                    t+=string(h-1,'D') + 'R';
                    t+=string(h-1,'U') + 'R';
                    w-=2;
                }
                else {
                    if(a==0) s+="DR";
                    else s+="RD";
                    break;
                }
            }
            reverse(all(t));
            s+=t;
            cout << s << "\n";
         }
    }
    
    return 0;
}
