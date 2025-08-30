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

int main () {
	int n;
	cin >> n;
	vector<pair<int, int>>ans;
	int cur = 0;
	for (int i = 1; i <= n; i++){	// all bodies
		ans.pb({1 + cur, 0});		// special
		ans.pb({1 + cur -1, 0});	// left of special
		ans.pb({1 + cur, 1});		// top of special
		ans.pb({1 + cur, -1});		// bottom of special
		cur += 2;
	}
	int right_most = 1 + cur - 2;
	ans.pb({right_most + 1, 0});			// right of the rightmost special cell.

	cur = 0;
	for (int i = 1; i < n; i += 2){	// all horns
		ans.pb({1 + cur, 2});
		ans.pb({2 + cur, 2});
		ans.pb({3 + cur, 2});
		ans.pb({1 + cur, -2});
		ans.pb({2 + cur, -2});
		ans.pb({3 + cur, -2});
		cur += 4;
	}
	if (n % 2 == 0) {
		for (int i = 0; i < 5; i++){	
			ans.pb({-1, i});
			ans.pb({right_most + 2, i});
		}
		for (int i = 0; i < right_most + 2; i++){
			ans.pb({i, 4});
		}
	}
	else {
		ans.pb({right_most + 1, 1});
		for (int i = 0; i > -5; i--){
			ans.pb({-1, i});
		}
		for (int i = -2; i > -5; i--){
			ans.pb({right_most, i});
		}
		for (int i = 0; i < right_most; i++){
			ans.pb({i, -4});
		}
	}
	printf("%d\n", ans.size());
	for (pair<int , int>p : ans) printf("%d %d\n", p.first, p.second);
}
