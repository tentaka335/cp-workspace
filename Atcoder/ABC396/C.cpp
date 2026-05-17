#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,m;
    cin >> n >> m;
    vector<ll> B(n),W(m),SB(n),SW(m),SBW(min(n,m));
    for(ll i = 0 ;i<n;i++) {
        cin >> B[i];
    }
    for(ll i = 0;i<m;i++) {
        cin >> W[i];
    }
    sort(B.rbegin(),B.rend());
    sort(W.rbegin(),W.rend());
    ll maxb=0,maxw=0,maxbw=0,mbindex=0,mwindex=0;
    for(ll i = 0;i<n;i++) {
        if(i==0) {
        SB[0] = B[0];
        }
        else SB[i] = SB[i-1] + B[i];
        maxb = max(maxb,SB[i]);
        if(maxb==SB[i]) mbindex = i;
    }
    for(ll i = 0;i<m;i++) {
        if(i==0) SW[0] = W[0];
        else SW[i] = SW[i-1] + W[i];
        maxw = max(maxw,SW[i]);
        if(maxw==SW[i]) mwindex = i;
    }
    for(ll i = 0;i<min(n,m);i++) {
        SBW[i] = SB[i] + SW[i];
        maxbw = max(SBW[i],maxbw);
    }
    if(mbindex>=mwindex) cout << maxb+maxw << "\n";
    else cout << maxbw << "\n";
}


