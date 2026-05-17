#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(3);
    for(ll i = 0;i<3;i++) cin >> A[i];
    sort(A.begin(),A.end());
    ll ans = 9999;
    for(ll x = 0;x<=9999;x++) {
        for(ll y = 0;y<=9999-x;y++) {
            if((n+(A[2]-A[1])*x+(A[2]-A[0])*y)%A[2]==0) {
                ans = min(ans,(n+(A[2]-A[1])*x+(A[2]-A[0])*y)/A[2]);
            }
        }
    }
    cout << ans << "\n";
}