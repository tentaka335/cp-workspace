#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >>  h >> w;
    vector<vector<ll>> P(h,vector<ll>(w));
    
    for(ll i = 0;i<h;i++) {
        for(ll j = 0;j<w;j++) {
            cin >> P[i][j];
        }
    }

    ll ans  = 0;
    for(ll i = 0;i<(1<<h);i++) {
        map<ll,ll> A;
        ll gyou = 0;
        for(ll j = 0;j<h;j++) {
            if((i>>j) & 1) {
                gyou++;
            }
        }

       

     
        for(ll wi = 0;wi<w;wi++) {
               ll temp;
        bool notfoundfirst = true;
            bool ok = true;
          for(ll j = 0;j<h;j++) {
            if((i>>j) & 1) {
                if(notfoundfirst==true) {
                    temp = P[j][wi];
                    notfoundfirst = false;
                } else {
                    if(temp!=P[j][wi]) {
                        ok = false ;
                        break;
                    } 
                }

            }
        }
        if(ok == true) {
            A[temp]++;
        ans = max(ans,gyou*A[temp]);
        } 
    }
    }
    cout << ans << "\n";
}



/*
今回の鍵はH<=8とあまりにもHが小さいこと。
どの行を選ぶかは2^h<=2^8=64通りしかなくビット全探索可能。
各探索については、0~w-1の列を順にみていき、
各列について、ビットが立っているどの行も
同じ数字が書いてあるなら、その列に書いてある数字をmapに追加し、
ビットが立っている行数*その数字が書いてある列数を最大値更新していくことで答えが求まる。
*/



