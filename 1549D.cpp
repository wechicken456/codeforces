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

void solve(){
	int n;
	scanf("%d", &n);
	vector<ll>a(n + 1);
	vector<ll>diff(n + 1);
	vector<vector<int>>div(n + 1);
	
	auto factor = [&](int i, int num) {
		for (int f = 2; f*f <= num; f++) {
			if (num % f == 0) {
				div[i].pb(f);
			}
		}
	};
	
	for (int i = 1; i <= n ; i++) {
		scanf("%lld", &a[i]);
		diff[i] = abs(a[i] - a[i-1]);
		factor(i, diff[i]);
	}
	int longest = 0;
	for (int i = 1; i <= n; i++) {
		
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0 ; i < T; i++) {
		solve();
	}
}


