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

const int maxN = 2e5;

void solve(){
	
	int dp[maxN + 1][2]; 	// 0 for friend, 1 for myself.
	int n;
	scanf("%d", &n);
	vector<int>a(n + 1);
	for (int i = 1; i <=  n ; i++){
		scanf("%d", &a[i]);
	}	
	dp[1][0] = (a[1] == 1);
	
	for (int i = 2; i <= n; i++){
		int cur = (a[i] == 1);
		dp[i][0] = min(dp[i-1][0] + cur, dp[i-2][1]);
		dp[i][1] = min(dp[i-1][1], dp[i-2][0]);
	}
	int ans = min(dp[n][0], dp[n][1]);
	printf("%d\n", ans);
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}


