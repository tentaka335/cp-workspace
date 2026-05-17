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
    
    ll h1,h2,h3,w1,w2,w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    ll ans = 0;
    
    vector<vector<ll>> A(3,vector<ll>(3));
    for(ll a = 1;a<=30;a++) {
        A[0][0] = a;
        for(ll b = 1;b<=30;b++) {
            A[0][1] = b;
            for(ll c = 1;c<=30;c++) {
                A[1][0] = c;
                for(ll d = 1;d<=30;d++) {
                    A[1][1] = d;
                    if(h1-A[0][0] - A[0][1]<1) {
                        continue;
                    }
                    A[0][2] = h1-A[0][0] - A[0][1];

                      if(h2-A[1][0] - A[1][1]<1) {
                        continue;
                    }
                    A[1][2] = h2-A[1][0] - A[1][1];

                     if(w1-A[0][0] - A[1][0]<1) {
                        continue;
                    }
                    A[2][0] = w1-A[1][0] - A[0][0];

                     if(w2-A[0][1] - A[1][1]<1) {
                        continue;
                    }
                    A[2][1] = w2-A[1][1] - A[0][1];

                      if(w3-A[0][2] - A[1][2]<1) {
                        continue;
                    }
                    A[2][2] = w3-A[1][2] - A[0][2];

                    if(A[2][0]+A[2][1]+A[2][2] != h3) {
                        continue;
                    }
                    ans++;
                   
                    
                }
            }
        }
    }
    cout << ans;
    return 0;
}