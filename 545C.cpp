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

const int maxN = 1e5;
int dp[maxN + 1][3];

void solve(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>>trees(n+1);
	for (int i = 0,x,h; i < n; i++){
		scanf("%d %d", &trees[i].first, &trees[i].second);
	}
	if (n > 2) {
		int last = trees[0].first, ans= 0;
		for (int i = 1; i < n - 1; i++){
			if (trees[i].first - trees[i].second > last) {
				last = trees[i].first;
				ans++;
			}
			else if (trees[i].first + trees[i].second < trees[i+1].first){
				last = trees[i].first + trees[i].second;
				ans++;
			}
		}
		printf("%d\n", ans + 2);
	}
	else {
		printf("%d\n", n);
	}
}

int main(){
	solve();
}	


