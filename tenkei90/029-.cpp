#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll w,n;
    cin >> w >> n;
    vector<ll> L(n);
    vector<ll> R(n);
    vector<ll> compcor;

    for(ll i = 0;i<n;i++) {
        cin >> L[i] >> R[i];
        compcor.push_back(L[i]);
        compcor.push_back(R[i]);
    }

    sort(compcor.begin(),compcor.end());
    for(ll i = 0;i<n;i++) {
        ll lpos = lower_bound(compcor.begin(),compcor.end(),L[i])-compcor.begin();
        ll rpos = lower_bound(compcor.begin(),compcor.end(),R[i])-compcor.begin();
        L[i] = lpos;
        R[i] = rpos;
    }
    vector<ll> H(2*n);
  for(ll i = 0;i<n;i++) {
    ll maxh = 0;
    for(ll j = L[i];j<=R[i];j++) {
        maxh = max(maxh,H[j]);
     }
      for(ll j = L[i];j<=R[i];j++) {
        H[j] = maxh + 1;
     }
    
     cout << maxh + 1 << "\n";
    
  }
}

/*
座圧を理解した。これはある数字の列を昇順に並び変えて、その番号を与えるという手法である。
今回は座圧を行ってもどのレンガの上にどのレンガが乗るのかは変わらないため。座圧を行い、wを2nに圧縮する。

*/
