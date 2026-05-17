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
    
    ll n,q;
    cin >> n >> q;

    vector<ll> A(2*n);
    rep(i,n) {
        A[i] = i+1;
        A[i+n] = i+1;
    }

    ll sumk = 0;
    
    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll p,x;
            cin >> p >>x;
            A[sumk+p-1] = x;
            A[(sumk+p-1 + n)%(2*n)] = x;
        }
        else if(qt==2) {
            ll p;
            cin >> p;
            cout << A[sumk + p-1]<< "\n";
        } else {
            ll k;
            cin >> k;
            sumk = (sumk + k)%n;
        }
    }
    
    return 0;
}