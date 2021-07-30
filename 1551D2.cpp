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
	int n,m,k;
	cin >> n >> m >> k;
	bool check = false;
	vector<vector<int>>ans(n + 1, vector<int>(m + 1, 0));
	if (m == 1 && k > 0) {
		puts("NO");
		return;
	}
	auto compile_grid = [&](int row, int col) {
		bool flip = false;
		if (row != 0) {
			for (; row < n; row += 2) {
				if (!flip) {
					ans[row][col] = ans[row + 1][col] = 2;	// 'c'
					ans[row][col + 1] = ans[row + 1][col+1] = 3;	// 'd'
				}
				else {
					ans[row][col] = ans[row + 1][col] = 3; 	// 'd'
					ans[row][col + 1] = ans[row + 1][col+1] = 2;	// 'c'
				}
				flip ^= 1;
			}
			col += 2;
		}
		flip = false;
		for (; col < m; col += 2) {
			for (row = 0; row < n; row += 2) {
				if (!flip) {
					ans[row][col] = ans[row + 1][col] = 23;		// 'x'
					ans[row][col + 1] = ans[row + 1][col+1] = 24;	// 'y'
				}
				else {
					ans[row][col] = ans[row + 1][col] = 24;		// 'y'
					ans[row][col + 1] = ans[row + 1][col+1] = 23;	// 'x'
				}
				flip ^= 1;
			}
			if (flip == true) flip ^= 1;
		}
	};
	
	if (n % 2 == 0 && m % 2 == 0) {
		if (k % 2 == 0) {
			check = true;
			// PROCESS ANSWER HERE
			int row = 0, col = 0, cur =0;
			while (k > 0) {
				ans[row][col] = cur % 26;
				ans[row][col + 1] = cur % 26;
				k--;
				row++;
				cur ^= 1;
				if (row == n) {
					row = 0;
					col += 2;
					cur = ans[0][col-1] ^ 1;
				}
			}
			compile_grid(row , col);
		}
	}
	else if (m % 2 == 0){
		int per_row = m / 2;
		if (k >= per_row) {
			 k -= per_row;
			 if (k % 2 == 0) {
				bool flip = false;
				for (int i = 0 ; i < m ; i += 2) {
					 if (flip) ans[n-1][i] = ans[n-1][i + 1] = 5;
					 else ans[n-1][i] = ans[n-1][i + 1] = 6;
					 flip ^= 1;
				}
				n -= 1;
				check = true;
				int row = 0, col = 0, cur =0;
				while (k > 0) {
					ans[row][col] = cur % 26;
					ans[row][col + 1] = cur % 26;
					k--;
					row++;
					cur ^= 1;
					if (row == n) {
						row = 0;
						col += 2;
						cur = ans[0][col-1] ^ 1;
					}
				}
				compile_grid(row , col);
				n++;
			 }
		}
	}
	else if (n % 2 == 0) {
		if (k % 2 == 0 && k <= n*m/2 - n / 2) {
			check = true;
			int row = 0, col = 0, cur =0;
			while (k > 0) {
				ans[row][col] = cur % 26;
				ans[row][col + 1] = cur % 26;
				k--;
				row++;
				cur ^= 1;
				if (row == n) {
					row = 0;
					col += 2;
					cur = ans[0][col-1] ^ 1;
				}
			}
			compile_grid(row , col);
			// PROCESS ANSWER HERE
		}
	}
	if (check) {
		puts("YES");
		// PROCESS ANSWER HERE
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++) {
				printf("%c", 'a' + ans[i][j]);
			}
			puts("");
		}
	}
	else puts("NO");
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


