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
	int m;
	cin >> m;
	//int bob[2][1e5+1];
	//int alice[2][1e5+1];
	int prefix_sum[2][100001];
	vector<vector<int>>grid(2, vector<int>(m, 0));
	for (int i = 0 ; i < 2; i++) {
		for (int j = 0 ; j < m; j++) {
			cin >> grid[i][j];
			if (j > 0) {
				prefix_sum[i][j] = prefix_sum[i][j-1] + grid[i][j];
			}
			else prefix_sum[i][j] = grid[i][j];
		}
	}
	int ans = prefix_sum[0][m-1] - prefix_sum[0][0];
	for (int i = 1 ; i < m; i++) {
		int sum1 = prefix_sum[0][m-1] - prefix_sum[0][i];
		int sum2 = prefix_sum[1][i] - grid[1][i];
		int cur_max = max(sum1, sum2);
		ans = min(cur_max, ans);

	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--){
		solve();
	}
}


