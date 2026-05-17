#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans(k,'z');
    set<pair<char,ll>> A;
    for(ll i = 0;i<n-k;i++) {
        A.insert({s[i],i});
    }

    ll left = 0;//一つ前の文字を採用したindex+1
    for(ll i = 0;i<=k-1;i++) {//i文字目を決める処理
        
         A.insert({s[n-k+i],n-k+i});
         auto [st,index]=*begin(A);
         
         for(ll j = left;j<=index;j++) {
            A.erase({s[j],j});
         }//i-1~i文字目をsetから消す
         left = index + 1;
         ans[i] = st;
    }
    cout << ans << "\n";
}


                
 



/*
考察
前から貪欲に辞書順に早いものを取る。より具体的には
i(0-indexで)文字目はi-1文字目を採用したindex+1から、
n-k+iまでの中で辞書順で最も早いものを取る。
なぜなら、baaとazzなら後者の方が早い。とにかく前に来るものが早い方が強い。
そこで、bsjsgazzから3文字取ることを考えると、左から順に文字を採用するか決めるとき、
bはかなり早いので採用したくなるが、後半の方のaを採用した方が早い。その文字をとってもまだ
文字数が足りる範囲で、辞書順最速を得るほうが良い。

考察　5m30s　実装 23m tle 1

辞書順で最小は貪欲に前から決めることが非常に多いらしい。
今回は
*/

/*
感想
実装

i文字目を取る処理を作り、forで回した。*begin(変数)(最小を取り出す関数)は初めて使ったが
一応for(auto p:A)文を一回で切ることでもできる。
i文字目の処理としては、iを採用できるのは(i-1文字目のindex)~n-k+iまでであるから、
その中で最小を取得したい。そこで、
mapやset等の最小を取り出せる機能を利用しようと考えた。
ただしどのindexの文字を採用するかも取得したかったので(char(s[index]),ll(index))を要素の型とした。
まず0~n-k文字目（0文字目が取得できる範囲)をsetに入れて初期化しておく。
次にleft というi-1文字目を採用したindexを保存しておく変数を作っておく。
*/




