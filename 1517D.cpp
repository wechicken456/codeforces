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

const int maxN = 500;
int dist_row[maxN + 1][maxN + 1];
int dist_col[maxN + 1][maxN  +1];
int dp[maxN + 1][maxN + 1][21];

int main(){
	int n , m, d;
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1; j <= m - 1; j++) {
			scanf("%d", &dist_col[i][j]);
		}
	}
	for (int i = 1 ; i <= n - 1; i++ ){
		for (int j = 1 ; j <= m ; j++) {
			scanf("%d", &dist_row[i][j]);
		}
	}
	if (d % 2 == 1) {
		for (int i = 0 ; i < n; i++) {
			for (int j = 0 ; j < m ; j++) {
				printf("-1 ");
			}
			puts("");
		}
		return 0;
	}
	d /= 2;
	for (int k = 1; k <= d; k++) {		// find shortest path with length k/2, then we return using that path so the total length is k
		for (int i = 1; i <= n ;i++) {
			for (int j= 1 ; j <= m;j ++) {
				if (i == 1) dp[i][j][k] = dp[i+1][j][k-1] + dist_row[i][j];  
				else if (i == n) dp[i][j][k] = dp[i-1][j][k-1] + dist_row[i-1][j];
				else dp[i][j][k] = min(dp[i-1][j][k-1] + dist_row[i-1][j], dp[i+1][j][k-1] + dist_row[i][j]);
				
				if (j == 1) dp[i][j][k] = min(dp[i][j][k], dp[i][j+1][k-1] + dist_col[i][j]);
				else if (j == m) dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k-1] + dist_col[i][j-1]);
				else {
					dp[i][j][k] = min(dp[i][j][k], dp[i][j+1][k-1] + dist_col[i][j]);
					dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k-1] + dist_col[i][j-1]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", dp[i][j][d] * 2);
		}
		puts("");
	}
}
















