#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<ll,ll> A;
    ll asasihiki = 0;
    ll ans = 0;
    vector<ll> B(n);
    for(ll i = 0;i<n;i++) {
        if(s[i]=='A') asasihiki++;
        else if(s[i]=='B') asasihiki--;
        B[i] = asasihiki;
        A[B[i]]++;
        if(B[i]>=1) ans++;
    }
    ll acnt = 0;
    ll nowans = ans;
    for(ll i = 0;i<n-1;i++) {
        if(s[i]=='A') {
            acnt--;
            nowans-=A[(-1)*acnt];
            A[B[i]]--;
        }
        if(s[i]=='B') {
            acnt++;
            nowans
            A[B[i]]--;
        }

    }

}




/*

*/



