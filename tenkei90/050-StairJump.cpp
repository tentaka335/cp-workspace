#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll n,l;
ll ans = 0;
ll pow9p7 = 1000000007;






int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> l;
    vector<ll> DP(n+1);//DP[i] :=i番目の段に到達する方法の数

    DP[0] = 1;

    for(ll i = 1;i<=n;i++) {
    if(0<=i-1&&i-1<n&&0<=i-l&&i-l<=n) DP[i] = (DP[i-1] + DP[i-l])%pow9p7;
    else if(0<=i-1&&i-1<=n) DP[i] = (DP[i-1])%pow9p7;
}
cout << DP[n]%pow9p7 << "\n";
}



/*
A,B,Cに含まれる数をそれぞれ46で割った余りによって分類。（mapを用いる）
余りはA,B,Cごとに高々46通りだから、3種の余りを全探索する。
*/



