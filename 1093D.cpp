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

const int maxN = 3e5 + 1;
vector<int>adj[maxN];
bool visited[maxN];
ull ans = 0;
ull mod = 998244353;
ll cnt = 0;

void solve(){
	int n, m;
	ans = 1, cnt = 0;
	scanf("%d %d", &n, &m);
	
	fill(visited, visited + maxN, false);
	int dist[maxN];
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	
	for (int i = 0 ; i < m; i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	for (int i = 1; i <= n; i++) {
		ull temp1 = 1, temp2 = 1;
		//cout << i << "\n";
		if (!visited[i]) {
			queue<pair<int, int>>q;
			q.push({i, 1});
			while (!q.empty()) {
				int cur_node = q.front().first;
				int cur_dist = q.front().second;
				q.pop();
				if (visited[cur_node]) {
					if (cur_dist != dist[cur_node]) {
						puts("0");
						return;
					}
					continue;
				}
				visited[cur_node] = true;
				dist[cur_node] = cur_dist;
				if (cur_dist % 2 == 1) {
					temp1 *= 2; 
					temp1 %= mod;
				}
				else {
					temp2 *= 2;
					temp2 %= mod;
				}
				for (int x : adj[cur_node]) {
					if (!visited[x]) q.push({x, cur_dist + 1});
				}
			}
			ull sum = (temp1 + temp2) % mod;
			ans *= sum;
			ans %= mod;
		}
	}
	printf("%llu\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		solve();
	}
}


