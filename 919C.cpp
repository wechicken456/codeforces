#include<bits/stdc++.h>
#include<set>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<fstream>

#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

ull power(ll x, ull y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
 
ll my_ceil(ll a, ll b) {
	return (a/b) + ( (a%b)!=0 );
}

ll n; 

bool check(ll k) {
	ll cur = n;
	ll sum = 0;
	while (cur > 0) {
		cur -= k;
		cur -= cur / 10;
		if (cur > 0) sum += k;
		else sum += k + cur;
	}
	return 2 * sum >= n;
}

void solve(){
	scanf("%lld", &n);
	for (ll i = 1; i <= n; l++){
		if (check(i)) {
			printf("%lld\n", i);		
			return;
		}
	}
}

int main(){
	solve();
}


