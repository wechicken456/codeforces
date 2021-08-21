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

string s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void solve(){
	int r,c , k;
	scanf("%d %d %d", &r, &c, &k);
	getc(stdin);
	vector<vector<int>>grid(r, vector<int>(c, 0));
	int count_rice = 0;
	vector<vector<int>>ans(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0 ; j < c; j++) {
			char x = getc(stdin);
			if (x == 'R') {
				grid[i][j] = 1;
				count_rice++;
			}
		}
		getc(stdin);
	}
	int more = count_rice % k, enough = count_rice / k;
	int count_cells = 0, cur_row = 0, cur_col = 0;
	int cur_char = 0, cur_rice = 0 , direction = 1;
	while (count_cells < r * c) {
		if (grid[cur_row][cur_col] == 0) {
			ans[cur_row][cur_col] = cur_char;
		}
		else {
			cur_rice++;
		
			if (cur_rice - 1 == enough) {
				if (more > 0) {
					ans[cur_row][cur_col] = cur_char;
					more--;
					cur_rice = 0;
					cur_char++;
				}
				else {
					cur_rice = 1;
					cur_char++;
					ans[cur_row][cur_col] = cur_char;
				}
			}
			else {
				ans[cur_row][cur_col] = cur_char;
				//cur_rice++;
			}
		}
		cur_col += direction;
		if (cur_col < 0) {
			cur_col = 0;
			cur_row++;
			direction *= -1;
		}
		else if (cur_col == c) {
			cur_col = c - 1;
			cur_row++;
			direction *= -1;
		}
		count_cells++;
	}
	for (int i = 0 ; i < r;i ++) {
		for (int j = 0 ; j < c; j++) {
			printf("%c", s[ans[i][j]]);
		}
		puts("");
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){ 
		solve();
	}
}


