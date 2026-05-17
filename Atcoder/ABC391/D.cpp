#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,w;
    cin >> n >> w;
    ll inf = 99999999999999;
    vector<ll> vt(n+1,0);//i行目が消える時刻。
    vector<vector<ll>> Y(w+1);//Y[x][i] = x の下からi個目のブロックのy;
    vector<vector<ll>> ar(w+1);//ar[x][i] xの下からi個目のブロックが最下層に到着する時刻。
    vector<ll> numtoheight(n+1);//i個目のブロックは下から何個目か。

    for(ll i = 1;i<=n;i++) {
        ll x,y;
        cin >> x >> y;
        Y[x].push_back(y);
        ar[x].push_back(inf);
        numtoheight[i] = Y[x].size()-1;
    }
    
    ll vanishborder = Y[1].size()-1;
        for(ll x = 1;x<=w;x++) {
            ll temp = Y[x].size();
            vanishborder = min(temp-1,vanishborder);
        }
    
//0-indexで行く。
if(vanishborder>=0) {
    //初期値の計算
    for(ll x = 1;x<=w;x++) {
        vt[0] = max(vt[0],Y[x][0]);
}
for(ll h = 1;h<=vanishborder;h++) {
    for(ll x = 1;x<=w;x++) {
        ar[x][h] = max(vt[h-1],Y[x][h]-1);
    }
    for(ll x = 1;x<=w;x++) {
        vt[h] = max(vt[h],ar[x][h]+1);
    }
}
}

//クエリ処理
ll q;
cin >> q;
for(ll qi = 0;qi<q;qi++) {
    ll t,a;
    cin >> t >> a;
    ll height = numtoheight[a];
    if(vanishborder>=0) {
        if(vanishborder<height) cout << "Yes" << "\n";
        else {
            if(vt[height]<=t) cout << "No" << "\n";
            else cout << "Yes" << "\n";
        }
    }
    else {
        cout << "Yes" << "\n";
    }
    
}


    
/*
下からi番目のブロック達は同じ時刻に消える。
i番目のブロックが消える時刻はi番目のブロックの中で1行目に到達する時刻の最大値　の　+ 1;
各ブロックがどの時刻で1行目に到達するかは、max(vt[i-1],y)であるから、
この２つを値を交互に求めてvt[i] を 0 ~ vanishborderまで調べておく。
クエリ処理は ブロックの番号aからそのブロックが下からi番目を獲得し、vt[i]とtを比較。
*/


    


}


