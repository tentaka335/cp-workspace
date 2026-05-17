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
    
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> A(n+1);
    vector<ll> S(n+1);//
    for(ll i = 1;i<=n;i++) {
        A[i] = s[i-1] - '0';
        S[i] = S[i-1] + A[i]*i;
    }
    vector<ll> digit(n+100);
    vector<ll> kuri(n+100);
    for(ll i = 1;i<=n;i++) {//i桁目の和を取る
       /* if(kuri[i]>=10) {
            ll l = i+1;
            ll temp = kuri[i];
            temp/=10;
            while(temp>=1) {
                kuri[l] += temp%10;
                temp/=10;
                l++;
            }
            kuri[i] %=10;
        } 余ったkuri[i]は繰り上がり処理でうまいこと行く。
            */
        
        ll sum = S[n+1-i];
        ll digisum = sum + kuri[i];
        digit[i] = digisum%10;
        digisum/=10;
        ll k = i+1;
        while(digisum>=1) {
            kuri[k] += digisum%10;
            digisum/=10;
            k++;
        }
    }
    for(ll i = n+1;i<=n+99;i++) {
          if(kuri[i]>=10) {
            ll l = i+1;
            ll temp = kuri[i];
            temp/=10;
            while(temp>=1) {
                kuri[l] += temp%10;
                temp/=10;
                l++;
            }
            kuri[i] %=10;
        }
        digit[i] = kuri[i];
    }
    bool nz = true;
    for(ll i = n+99;i>=1;i--) {
       if(digit[i]!=0) nz = false;
        if (nz == false) cout << digit[i];
    }
    cout << "\n";
    return 0;
}