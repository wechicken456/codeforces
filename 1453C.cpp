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
	int grid[2001][2001];
	scanf("%d\n", &n);
	vector<int>count(10);
	vector<int>ans(10);
	vector<pair<int, int>>nums[10];
	
	auto check = [&](pair<int , int> p, pair<int ,int>q, int& MAX) {
		int a = max( p.first - 1, n - p.first);
		int b = max( q.first - 1, n - q.first);
		a = max(a, b);
		a = abs(a * (p.second - q.second));
		if ( a > MAX) MAX = a;
		a = max(p.second - 1, n - p.second);
		b = max(q.second - 1, n - q.second);
		a = max(a, b);
		a = abs(a * (p.first - q.first));
		if (a > MAX) MAX = a; 
	};
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			c = getc(stdin);
			//cout << c << " ";
			grid[i][j] = c - '0';
			count[grid[i][j]]++;
			nums[grid[i][j]].pb({i + 1 , j + 1});
		}	
		getc(stdin);
	}
	
	for (int i = 0 ; i < 10 ; i++) {
		if (count[i] < 2) {
			printf("0 ");
			continue;
		}
		int greatest = -1;
		int m = nums[i].size();
		for (int a = 0 ; a < m; a++) {
			for (int b = a + 1; b < m ; b++) {
				check(nums[i][a], nums[i][b], greatest);
			}
		}
		printf("%d ", greatest);
	}
	puts("");
}


int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}


