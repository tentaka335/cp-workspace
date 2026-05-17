#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    map<ll,ll> A;
    for(ll i = 0;i<n;i++) {
        ll a;
        cin >> a;
        if(A.count(a)) A[a] +=1;
        else A[a] = 1;
    }
    ll ans = 0;
    for(auto &a:A) {
        ll stick = a.second;
        if(stick>=3) {
            ans += ((stick)*(stick-1)*(stick-2))/6;
        }
    }
    cout << ans << "\n";
}