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
int dp[maxN + 1];

void solve(){
	fill(dp, dp + maxN + 1, 0);
	int n;
	scanf("%d", &n);
	vector<int>a(n + 1);
	for (int i = 1; i <=  n ; i++){
		scanf("%d", &a[i]):
	}	
	dp[1] = (a[1] == 1);
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}


