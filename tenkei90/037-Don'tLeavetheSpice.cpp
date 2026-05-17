#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
 

}

/*ナップサックでやりたいけど、もらう遷移を行うのに、
WかかりO(W*W*n)かかりTLE
セグ木で区間に対する変化をうまく扱う。
*/
