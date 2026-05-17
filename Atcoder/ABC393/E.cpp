#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main () {
   cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n);
vector<vector<ll>> eachdivi(n);//iの約数の集合
vector<ll> divi(1000000,0);//div[i]== iを約数に持つ数の個数
    for(ll index = 0;index<n;index++){
        cin >> A[index];
         ll a = A[index];
    for(ll i = 1;i*i<=a;i++) {
        if(a%i==0) {
            if(i*i==a) {
                divi[i]++;
                eachdivi[index].push_back(i);
            }
            else {
                divi[i]++;
                eachdivi[index].push_back(i);
                divi[a/i]++;
                eachdivi[index].push_back(a/i);
            }
        }
    }
    }
    for(ll i = 0;i<n;i++) {
        ll ans = 1;
        for(ll j = 0;j<eachdivi[i].size();j++) {
            if(divi[eachdivi[i][j]]>=k) ans = max(ans,eachdivi[i][j]);
        }
        cout << ans << "\n";
    }
}


