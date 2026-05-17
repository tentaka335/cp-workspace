#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> V;
    for(ll i = 0;i<n;i++) {
        ll a,b;
        cin >> a >> b;
        V.push_back(b);
        V.push_back(a-b);
    }
    sort(V.rbegin(),V.rend());
    ll ans = 0;
    for(ll i = 0;i<k;i++) {
        ans+=V[i];
    }
    cout << ans << "\n";
}

/*
一分でできることは
1,ある問題の部分点Bを取る
2,すでに部分点を取った問題を解き進め追加でA-B点を取る。

*/