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
	int a[8001];
	int prefix_sum[8001];
	vector<bool>special(8001, false);
	prefix_sum[0] = 0;
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++ ) {
		scanf("%d", &a[i]);
		prefix_sum[i+1] = prefix_sum[i]  + a[i];
	}
	if (n < 3) {
		puts("0");
		return;
	}
	
	int ans = 0;
	for (int i = 0 ; i < n -1 ; i++){
		for(int j = i + 2 ; j <= n && prefix_sum[j] - prefix_sum[i] <= n; j++){
			special[prefix_sum[j] - prefix_sum[i]] = true;
		}
	}
	for (int i = 0 ; i < n; i++){
		
		ans += special[a[i]];
	}
	printf("%d\n", ans);
}

int main(){
	int T;
	scanf("%d" , &T);
	while (T--) {
		solve();
	}
}


