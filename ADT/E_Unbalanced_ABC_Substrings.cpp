#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> A(n+1),B(n+1),C(n+1);
    map<ll,ll> AB,BC,CA;
    map<pair<ll,ll>,ll> ABC;
    ll a = 0,b = 0,c = 0;
    ll ans = n*(n+1)/2;

    AB[0]++;BC[0]++;CA[0]++;ABC[{0,0}]++;
    rep(i,n) {
        if(s[i]=='A') a++;
        if(s[i]=='B') b++;
        if(s[i]=='C') c++;
        A[i+1] = a;
        B[i+1] = b;
        C[i+1] = c;
        ans-=AB[A[i+1]-B[i+1]];
        ans-=BC[B[i+1]-C[i+1]];
        ans-=CA[C[i+1]-A[i+1]];
        ans+=2*ABC[{A[i+1]-B[i+1],C[i+1]-A[i+1]}];
        AB[A[i+1]-B[i+1]]++;
        BC[B[i+1]-C[i+1]]++;
        CA[C[i+1]-A[i+1]]++;
        ABC[{A[i+1]-B[i+1],C[i+1]-A[i+1]}]++;
   
    }

    cout << ans;
    
    return 0;
}

/*
ずっとDPを疑ってしまっていた。これはDPをちゃんと知らないが故の無駄な時間だったかも。
条件を文字で置いて考えるという習慣を忘れてしまっていた。相異なる<=>同じの余事象という変換ができなかった。
A[l] - A[r-1] = B[l] - B[r-1]を移行して変形できるかということが試された。
*/