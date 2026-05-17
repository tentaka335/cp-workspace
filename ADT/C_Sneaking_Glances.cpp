#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll ans = 0;
ll n;

vector<ll> L(20);

void dfs(double pos,ll m,ll pass) {
    if(m>=n) {
        return ;
    }
    else {
        if((pos<0&&pos+L[m]>0)||(pos>0&&pos+L[m]<0)) {
            chmax(ans,pass+1);
            dfs(pos+L[m],m+1,pass+1);
        }
        else {
            dfs(pos+L[m],m+1,pass);
        }
         if((pos<0&&pos-L[m]>0)||(pos>0&&pos-L[m]<0)) {
            chmax(ans,pass+1);
            dfs(pos-L[m],m+1,pass+1);
        }
        else {
            dfs(pos-L[m],m+1,pass);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    rep(i,n) {
        cin >> L[i];
    }
    dfs(0.5,0,0);

    cout << ans;
    
    return 0;
}