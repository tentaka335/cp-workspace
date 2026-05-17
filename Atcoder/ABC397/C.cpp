#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n;
    cin >> n;
    vector<ll> A(n);
    map<ll,ll> rkind;
    set<ll> lkind;
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
        if(!rkind.count(A[i])) rkind[A[i]] = 1;
        else rkind[A[i]]++;
    }
    ll ans = 0;
    for(ll i = 0;i<n-1;i++) {
        lkind.insert(A[i]);
        rkind[A[i]]--;
        if(rkind[A[i]]==0) rkind.erase(A[i]);
        ll sum = rkind.size()+lkind.size();
        ans = max(sum,ans);
    }
    cout << ans << "\n";
    return 0;
}


