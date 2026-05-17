#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    ll n,m;
    cin >> n >> m;
    string s,t,anss;
    cin >> s >> t;

    vector<ll> A(n+1,0);
    vector<ll> S(n+1,0);
    for(ll i=0;i<m;i++) {
        ll l,r;
        cin >> l >> r;
        A[l-1] ++;
        A[r]--;
    }
    for(ll i = 0;i<n;i++) {
        if(i==0) S[i] = A[i];
        else {
            S[i] = S[i-1] + A[i];
        }
    }
    for(ll i = 0;i<n;i++) {
        if(S[i]%2==0) {
            anss+=s[i];
        }
        else anss +=t[i];
    }
    cout<< anss << "\n";
}  
