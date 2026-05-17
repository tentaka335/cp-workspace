#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char,ll>> RLE;
    char crrchar = s[0];
    ll sum = 1;
    for(ll i = 1;i<n;i++) {
        if(s[i] !=crrchar) {
            RLE.push_back({crrchar,sum});
            crrchar = s[i];
            sum = 1;
        }
        else {
            sum +=1;
        }
        if(i == n-1) RLE.push_back({crrchar,sum});
    }

   ll len = RLE.size(); 
   ll ans = n*(n+1)/2;
   for(ll i = 0;i<len;i++) {
    ll l = RLE[i].second;
    ans -= l*(l+1)/2;
   }

   cout << ans << "\n";
    
}


                
 



/*
考察
ランレングス圧縮がコツである。
今回、o,xどちらも少なくとも1つ含む区間の個数を求めよ。であるから
余事象の考え方から、どちらか一方を
含まない区間の個数を求めることができれば本来の答えが求まる。
そこでランレングス圧縮により
o,xいずれかか連続する区間をまとめることができる。
その区間のまとまり1つの長さをlとすると
そこにl*(l+1)/2の一方しか含まない区間が存在する。
よってランレングス圧縮したペア一つ一つに対し、
この計算を行い、n*(n+1)/2（すべての区間の個数）
から引くこで、答えが求まる。
*/

/*
感想

問題なく解けた。今回は('o',3)のように保存したが、ランレングス圧縮は
登場する文字が2種類しかないなら,
最初の文字と長さの配列のみ持てばよい startchar='o',RLE{1,3,5,2}は
oxxxoooooxxと復元できる。
*/



