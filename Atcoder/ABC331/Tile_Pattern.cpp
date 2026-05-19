#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q;
    cin >> n >> q;

    vector<vector<char>> P(n,vector<char>(n));

    vector<vector<ll>> S(n,vector<ll>(n));
    rep(i,n)rep(j,n) {
        cin >> P[i][j];
    }
    rep(i,n) {
        if(P[0][i]=='B') {
           if(i>=1) S[0][i] = S[0][i-1] + 1;
           else S[0][i] = 1;
        }
        if(P[0][i]=='W') {
           if(i>=1) S[0][i] = S[0][i-1];
           else S[0][i] = 0;
        }
    } 
    
    for(ll i = 1;i<n;i++) {
        for(ll j = 0;j<n;j++) {
              if(P[i][j]=='B') {
           if(j>=1) S[i][j] = S[i][j-1] + 1;
           else S[i][j] = 1;
        }
        if(P[i][j]=='W') {
           if(j>=1) S[i][j] = S[i][j-1];
           else S[i][j] = 0;
        }
        }
    }
    
    for(ll i = 1;i<n;i++) {
        for(ll j = 0;j<n;j++) {
            S[i][j] +=S[i-1][j];
        }
    }

    
    auto f = [&](ll a,ll b,ll c,ll d) {
        if(a==0&&b==0) return S[c][d];
        else if(a==0) return S[c][d] - S[c][b-1];
        else if(b==0) return S[c][d] - S[a-1][d];
        return S[c][d] - S[c][b-1] - S[a-1][d] + S[a-1][b-1];
    };

    
    
    rep(qi,q) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll div = c - a;
        ll div2 = d - b;
        a %=n;
        b%=n;
        c = a + div;
        d = b + div2;
 
  

        ll ans = 0;
        
        if(c<n&&d<n) {
            ans = f(a,b,c,d);
        }
        else if(c<n&&d>=n) {
             ans += f(a,b,c,n-1);
             ans+= ((d - n)/n) * f(a,0,c,n-1);
             ans+=f(a,0,c,d%n);
        }
        else if(c>=n&&d<n) {
            ans+=f(a,b,n-1,d);
            ans+=(((c-n)/n))*f(0,b,n-1,d);
            ans+=f(0,b,c%n,d);
        }
        else {
            ans+=f(a,b,n-1,n-1);
      
            ans+=(((c-n)/n))*f(0,b,n-1,n-1); 
            
            ans+= ((d - n)/n) * f(a,0,n-1,n-1);
            
           ans+= (((c-n)/n))*((d - n)/n)*f(0,0,n-1,n-1);
           
           ans+=f(a,0,n-1,d%n);
        
           ans+=f(0,b,c%n,n-1);
          
           ans+=((d - n)/n)*f(0,0,c%n,n-1);
        
           ans+=(((c-n)/n))*f(0,0,n-1,d%n);
          
           ans+=f(0,0,c%n,d%n);
           
          
        }

        cout << ans << "\n";
    }



    


    




    
    return 0;
}