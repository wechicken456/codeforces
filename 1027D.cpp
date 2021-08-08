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

}
const int maxN = 2e5 + 1;
vector<int>to(maxN);
vector<int>from[maxN];
int ans = 0; 
int cost[maxN];
bool visited[maxN];
int parent[maxN];
vector<int>paths;

void mark_visit(int cur) {
	visited[cur] = true;
	if (from[cur].size()) {
		for (int x : from[cur]) {
			if (x != cur && !visited[x]) mark_visit(x);
		}
	}
}

void dfs(int cur) {
	for (int x : from[cur]) {
		if (x != parent[cur]) paths.pb(x);
	}
	
	if (visited[cur]) {
		int next = parent[cur], min_cost = cost[cur];
		
		while (next != cur) {
			min_cost = min(min_cost , cost[next]);
			next = parent[next];
			//cout << cur << " " << next << "\n";
		}
		ans += min_cost;
		for (int x : paths) {
			//cout << x << "\n";
			mark_visit(x);
		}
		paths.clear();
		return;
	}
	
	visited[cur] = true;
	parent[to[cur]] = cur;
	
	dfs(to[cur]);
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1 ; i <= n; i++) {
		scanf("%d", &cost[i]);
	}
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		to[i] = a;
		from[a].pb(i);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			visited[i] = true;
		}
	}
	printf("%d\n", ans);
}

	
