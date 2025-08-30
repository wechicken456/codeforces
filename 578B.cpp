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

}

int main(){
	int n,x,k;
	scanf("%d %d %d", &n, &k, &x);
	//int highest=  0, pos = 0;
	vector<ll>a(n);
	vector<ll>or_first(n);
	vector<ll>or_behind(n);
	for (int i = 0; i < n ;i++) {
		scanf("%lld", &a[i]);
	}
	if (n ==1) {
		printf("%lld\n", a[0] * power(x, k));
		return 0;
	}
	or_first[0] = a[0];
	or_behind[n-1] = a[n-1];
	for (int i = 1 ; i < n; i++) {
		or_first[i] = or_first[i-1] | a[i];
		or_behind[n-i-1] = or_behind[n-i] | a[n-i-1];
	}
	ll ans = max( (a[0] * power(x, k)) | or_behind[1],  (a[n-1] * power(x, k)) | or_first[n-2]);
	if (n == 2) {
		ans = max( (a[0] * power(x, k)) | a[1], (a[1] * power(x, k) ) | a[0]);
	}
	else
	for (int i = 1 ; i < n - 1; i++) {
		ans = max(ans,  or_first[i - 1] | (ll)(a[i] * power(x, k)) | or_behind[i + 1]);
	}
	printf("%lld\n", ans);
}


