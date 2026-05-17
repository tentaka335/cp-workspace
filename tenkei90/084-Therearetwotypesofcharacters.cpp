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
    
    ll left = 0,right = 0;
    ll msum = 0;ll bsum = 0;
    if(s[0]=='o') msum++;
    else bsum++;
    ll ans  = 0;
    while(right<=n-1&&left<=n-1) {

        if(msum>=1&&bsum>=1) {
            ans+=n-right;
            if(s[left]=='o') msum--;
            else bsum--;
            left++;
        }
        else {
            right++;
            if(s[right]=='o') msum++;
            else bsum++;
        }
    }

    cout << ans << "\n";

}


                
 



/*
考察
尺取り法を用いる。
〇和と×和を用意し、条件を満たすなら答えにn-rightを足し、leftを+1する
条件を満たさないなら、rightを+1する。
O(2*n)で解ける。
*/

/*
感想

尺取り法でできるが想定解法ではない感がすごい。
尺取り法を息を吸うように実装できたのはいいが、他の方法もマスターすべきだと思う。
*/



