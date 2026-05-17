
/*s1~sn-2はsortしておけ
upperboundで次の要素で最も効率の良いものは見つけれる。
貪欲法なのと、ギリギリを攻めるのはあっていた
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for(ll tc=0;tc<t;t++) {
        ll n;
        cin >> n;
        vector<ll> S(n-1);
        ll se;
        for (ll i = 0;i<n-1;i++) cin >> S[i];
        cin >> se;
        sort(S.begin()+1,S.end());
        ll count = 2;
        ll l = 0;
        while(true) {
            if(2*S[l]>=se) {
                cout << count << "\n";
                break;
            }
            //次の大きいやつを探す。
            auto it  = upper_bound(S.begin(),S.end(),2*S[l]);
            if(it != S.begin()) {
                l = &it;
            }
            else {
                ll pos = lower_bound(S.begin(),S.end(),2*S[l])-S.begin();
                if (S[pos] == 2*S[l]) {
                    count++;
                    l = pos;
                }
                else {
                    count++;
                    if(pos==l-1) {
                        cout << -1 << "\n";
                        break;
                    }
                    else {
                        l = pos -1;
                    }
                }
            }

            }
        }
    }

/*
ある値より大きい要素のイテレータを返すのがauto it = upper_bound
これがbegin()ならある値以下の要素で
最大のものは存在しない。
そうでないなら、--itである値以下で最大の要素のイテレータを受け取ることができる。
今回の敗因は？
考察が不十分な中で実装を始めてしまったこと。
具体例での実験をせず、しなければいけない場合分けに気づけなかった。
イテレータの扱いに苦戦した。大まかにはあっていたが、正しい条件分岐ができていなかった。

*/
