#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
  ll T;
  cin >> T;
  for(ll qt = 0;qt<T;qt++) {
    ll n,h;
    cin >> n >> h;
    vector<ll> U(n+1),T(n+1),L(n+1);
    for(ll i = 1;i<=n;i++) cin >> T[i] >> L[i] >> U[i];
    ll nowup = h,nowlow = h;
    bool isok = true;
    for(ll i = 0;i<=n-1;i++) {
        ll canup = nowup+T[i+1]-T[i];
        ll canlow = nowlow -T[i+1]+T[i];
        if(canlow>U[i+1]||canup<L[i+1]) {
            isok = false;
            break;
        }
        else {
            nowup = min(canup,U[i+1]);
            nowlow = max(canlow,L[i+1]);
        }
    }
     cout << (isok?"Yes":"No") << "\n";
  }
}