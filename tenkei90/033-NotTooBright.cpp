#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    if(h==1||w==1) cout << h*w << "\n";
    else cout << ((h-1)/2 + 1)*((w-1)/2+1) << "\n";
}

/*#.#.
  ....
  #.#.
  が効率よい？
*/
