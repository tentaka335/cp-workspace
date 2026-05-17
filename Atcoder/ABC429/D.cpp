#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m,c;
    cin >> n >> m >> c;
    map <ll,ll> A;
    vector<ll> B,C;
    ll ans = 0;
    for (ll i = 0; i<n;i++) {
        ll y;
        cin >> y;
        if (!A.count(y)) A[y] = 1;
        else A[y] += 1;
    }

    for (auto p : A) {
    ll point = p.first;
    ll pop = p.second;
    B.push_back(point);
    C.push_back(pop);
    }
    ll b = B.size();
    for (ll i = 0; i<b-1;i++) {
        ll presentpoint = B[i];
        ll nextpoint = B[i+1];
        ll x = 0;
        ll j = i;
        while (x<c) {
         j++;
        ll nextpop = B[j];
        x += nextpop;
        }
        ans += x*(nextpoint - presentpoint);
    }
    cout << ans << "\n";
}