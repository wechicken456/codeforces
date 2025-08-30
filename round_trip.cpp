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

const int maxN = 2e5 + 1;
const int maxX = 1000;
int n, m,x;
vector<bool>visited(maxN + 1);
vector<int>adj[maxN + 1];
int infected[maxN + 1];
bool check = false;
vector<int>parents(maxN + 1);
int start, city_num;

void dfs(int cur, int parent) {
	if (visited[cur]) {
		vector<int>ans;
		int start = cur;
		int next = parents[cur];
		ans.pb(cur);
		while (next != start) {			// just keep following parent nodes to where we first started (root node). 
			ans.pb(next);
			next = parents[next];
		}
		cout << ans.size() + 1 << "\n";
		for (auto &x : ans) cout << x << " ";
		cout << start;
		exit(0);
	}
	visited[cur] = true;
	for (auto &c : adj[cur]) {
		if (c == parent) continue;		// if current node is parent node then don't process it as we need >= 2 intermediate cities.
		parents[c] = cur;				// keep track of where we're from 
		dfs(c, cur);
	}
}

// this problem is all about finding if there's any cycle in the graph.
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> infected[i];
	}
	for (int i = 1 , a, b; i <= n-1 ; i++){
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i]) {
			dfs(i, i);
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main(){
	solve();
}


