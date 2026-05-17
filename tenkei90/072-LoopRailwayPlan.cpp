#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;

const ll dx[] = {1,0,-1,0};
const ll dy[] = {0,1,0,-1};




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> grit(h+1,vector<char>(w+1));

    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
          
            cin >> grit[i][w];
        }
    }
    for(ll i = 1;i<=h;i++) {
        for(ll j =1;j<=w;j++) {
            if(grit[i][j]=='#') continue;
            queue<tuple<ll,ll,set<Pll>>> Q;//（x,y,d)
            set<ll,ll> A;

        }
    }
}
                




/*
*/



