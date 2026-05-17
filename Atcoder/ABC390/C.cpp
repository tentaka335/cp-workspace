#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    ll xmin = h,xmax = 0,ymin = w,ymax = 0;

    vector<string> S(h);
    for(ll i = 0;i<h;i++) cin >> S[i];

    for(ll i = 0;i<h;i++) {
        for(ll j = 0;j<w;j++) {
            if(S[i][j]=='#') {
                xmax = max(xmax,i);
                xmin = min(xmin,i);
                ymax = max(ymax,j);
                ymin = min(ymin ,j);
            }
        }
    }
    bool ok = true;
    for(ll i = xmin;i<=xmax;i++) {
        for(ll j = ymin;j<=ymax;j++) {
            if(S[i][j]=='.') {
                ok = false;
                break;
            }
        }
    }
    
cout << (ok?"Yes":"No") << "\n";

}

/*

黒が塗られているマスのxmax,xmin,ymin,ymaxを考えると、
xmin<=x<=xmax,ymin<=y<=ymaxの
範囲のマスを黒色に塗ることができれば必要十分。
この範囲のマスを探索し、白色のマスが一つでもあれば
黒色に塗ることは不可能


*/


