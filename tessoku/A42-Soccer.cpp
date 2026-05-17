#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n),B(n);
    vector<vector<ll>> ans(109,vector<ll>(109,0));
    for(ll i = 0;i<n;i++) cin >> A[i] >> B[i];
    //参加する人の体力、気力の下限に注目(a,b) = (1,1)~(100,100)の一万通りしかないぞ！
    ll answer = 1;
    for(ll a = 1;a<=100;a++) {
        for(ll b = 1;b <=100;b++) {
        for(ll i = 0;i<n;i++) {
        if(a<=A[i] && A[i] <= a+k && b<=B[i] && B[i] <=b+k) {
            ans[a][b]++;
        }
        }
         answer = max(answer,ans[a][b]);
        }
}
cout << answer << "\n";
}