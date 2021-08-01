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
#include<queue>

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

int n,m,k;
vector<vector<int>>grid;
vector<vector<ll>>cnt(1000, vector<ll>(1000, 0));

void solve(){
	
	ll ans = 0;
	vector<vector<bool>>visited(1000, vector<bool>(1000, false));
	vector<pair<int, int>>path;
	int row, col;
	cin >> row >> col;
	row--;
	col--;
	if (cnt[row][col]) {
		cout << cnt[row][col] << "\n";
		return;
	}
	queue<pair<int,int>>q;
	q.push({row , col});
	
	auto check = [&](int r, int c) {
		if (r < 0 || c < 0 || r >= n || c >= m) {
			return false;
		}
		if (grid[r][c] == 1) {
			if (visited[r][c]) return false;
			else return true;
		}
		else {
			ans++;
			return false;
		}
	};
	
	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		if (visited[cur_row][cur_col]) continue;
		visited[cur_row][cur_col] = true;
		path.pb({cur_row, cur_col});
		if(check(cur_row + 1, cur_col)) {		// down
			q.push(make_pair(cur_row + 1, cur_col));
		}
		if (check(cur_row -1, cur_col)) {
			q.push(make_pair(cur_row - 1, cur_col));
		}
		if (check(cur_row, cur_col - 1)) {
			q.push(make_pair(cur_row, cur_col - 1));
		}
		if (check(cur_row, cur_col + 1)) {
			q.push(make_pair(cur_row, cur_col + 1));
		}
	}
	for (pair<int ,int>p : path) {
		cnt[p.first][p.second] = ans;
	}
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> k;
	grid = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			if (x == '.') grid[i][j] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		solve();
	}

}


