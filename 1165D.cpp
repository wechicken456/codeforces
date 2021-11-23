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

vector<ll> find_factors(ll x) {
	vector<ll>res;
	for (ll i = 2; i*i <= x; i++) {
		if (x % i == 0) {
			res.pb(i);
			if (x/ i != i) res.pb(x / i);
		}
	}
	return res;
}

bool check_prime(ll x) {
	for (ll i = 2; i*i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void solve(){
	int n;
	scanf("%d", &n);
	vector<ll>nums(n);
	for (int i = 0 ; i < n; i++) {
		scanf("%lld", &nums[i]);
	}
	sort(nums.begin(), nums.end());
	if (n == 1) {
		if (check_prime(nums[0])) {
			printf("%lld\n", (ll)nums[0]*nums[0]);
		}
		else {
			puts("-1");
		}
		return;
	}
	
	ll ans = nums[0] * nums[n-1];
	vector<ll>res = find_factors(ans);
	if (res.size() != n) {
		puts("-1");
		return;
	}
	sort(res.begin(), res.end());
	for (int i = 0 ; i < n; i++) {
		if (res[i] !=  nums[i]) {
			puts("-1");
			return;
		}
	}
	printf("%lld\n", ans);
}

int main(){
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	*/
	int T;
	scanf("%d", &T);
	while (T--){
		solve();
	}
}


