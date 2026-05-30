#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long isqrt(long long n) {
    if(n<=0) return 0;
    ll m = sqrt(n);
    while((m+1)*(m+1)<=n) m++;
    while(m*m>n)m--;
    return m;
}


