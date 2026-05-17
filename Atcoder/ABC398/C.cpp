#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n;
    cin >> n;
    map<ll,ll> S;
    vector<ll> A(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> A[i];
        if(!S.count(A[i])) {
            S[A[i]] = 1;
        }
        else {
            S[A[i]]++;
        }
    }
    ll maxnum = 0;
    for(auto it : S) {
        if(it.second == 1) {
            maxnum = max(maxnum,it.first);
        }
    }
    if(maxnum == 0) {
        cout << -1 << "\n";
        return 0;
    }
    for(ll i = 1;i<=n;i++) {
        if(A[i]==maxnum) {
            cout << i << "\n";
            return 0;
        }
    }

}


