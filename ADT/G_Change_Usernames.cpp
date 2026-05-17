#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll n;
vector<string> S(100009);
map<string,ll> invS;
vector<string> T(100009);
vector<ll> changing(100009);
bool ok = true;
queue<ll> Q;

void dfs(ll pos) {
    changing[pos] = 1;
    if(!invS.count(T[pos])) {
        changing[pos] = 2;
        while(!Q.empty()) {
            changing[Q.front()] = 2;
            Q.pop();
        }
        return ;
    }
    else {
        if(changing[invS[T[pos]]]==2) {
            changing[pos] = 2;
             while(!Q.empty()) {
            changing[Q.front()] = 2;
            Q.pop();
        }
            return ;
        }
        else if(changing[invS[T[pos]]]==1) {
            ok = false;
            return ;
        }
        else {
            Q.push(pos);
            dfs(invS[T[pos]]);
        }
        
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

   
    cin >> n;
  
    rep(i,n) {
        cin >> S[i] >> T[i];
        invS[S[i]] = i;
    }
   

    rep(i,n) {
        if(changing[i]==0) {
            dfs(i);
        }
    }
    cout << (ok?"Yes":"No") << "\n";
    return 0;
}