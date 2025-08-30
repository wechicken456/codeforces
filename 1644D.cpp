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
#include<deque>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vb vector<bool>

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

void calc_ans(int s, int k) {
	int ans = 1;
	for (int i = 0 ; i < s; i++) {
		ans *= k;
		ans %= 998244353;
	}
	cout << ans << "\n";
}

void solve() {
	int n, m , k , q;
	cin >> n >> m >> k >> q;
	vector<int>row(n + 1, 0);
	vector<int>col(m + 1, 0);
	int cnt = 1;
	
	for (int i = 0 ; i < q; i++) {
		int x ,y ;
		cin >> x >> y;
		row[x] = cnt;
		col[y] = cnt;
		cnt++;
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
	

	
}


