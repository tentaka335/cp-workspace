#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<ll,ll>> time;
    for(ll i = 1;i<=n;i++) {
        ll t;
        cin >> t;
        time.push_back(make_pair(t,i));
    }
    sort(time.begin(),time.end());
    for(ll i = 0;i<=2;i++) cout << time[i].second << " ";
}