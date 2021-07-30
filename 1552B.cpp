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
	scanf("%d", &n);
	vector<vector<int>>a(n, vector<int>(5));
	for (int i = 0; i < n; i++){ 
		for (int j = 0; j < 5; j++){ 
			scanf("%d", &a[i][j]);
		}
	}
	auto better = [&](int cur , int cur_best) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (a[cur][i] < a[cur_best][i]) {
				cnt++;
			}
		}
		return cnt >= 3;
	};
	int best = 0;
	for (int i = 1 ; i < n; i++) {
		if (better(i, best)) {
			best = i;
		}
	}
	bool check = true;
	for (int i = 0 ; i < n ; i++) { 
		if (i != best && better(i, best)) {
			check = false;
			break;
		}
	}
	if (check) {
		cout << best + 1 << "\n";
	}
	else cout << "-1\n";
}

int main(){
	int T;
	cin >> T;
	while (T--){
		solve();
	}
}


