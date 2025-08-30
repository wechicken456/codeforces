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

const int maxN = 2e5;
int n , m ;
vector<int>infected(maxN + 1);
vector<int>adj[maxN + 1];
int ans = 0;

void dfs(int cur, int parent, int cur_infected) {
	if (cur_infected > m) {
		return;
	}
	if (adj[cur].size() == 1 && adj[cur][0] == parent) {
		ans++;
		return;
	}
	if (!infected[cur]) cur_infected = 0;
	for (auto &c : adj[cur]) {
		if (c != parent) dfs(c, cur, cur_infected + infected[c]);
	}
}

void solve(){
	scanf("%d%d", &n, &m);
	for (int i = 1, a; i <= n; i++){
		scanf("%d", &infected[i]);
	}
	int a ,b;
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d%d", &a, &b);
		adj[b].pb(a);
		adj[a].pb(b);
	}
	dfs(1, 0, infected[1]);
	cout << ans << "\n";
}

int main(){
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--){
		solve();
	}*/
	solve();
}


