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

int n , m;
int to[1001];
int from[1001];
bool visited[1001];
vector<vector<int>>dist(1001, vector<int>(1001, 0));
vector<pair<int,int>>ans(1001);
int ans_num = 0;

void dfs(int cur, int parent, int cur_max, int source) {	// cur_max is the minimum weight of the pipes along the way as the weight from source to destination cannot exceed it.  
	if (visited[cur]) return;
	visited[cur] = true;

	if (!to[cur]) {
		ans_num++;
		ans[source] = {cur, cur_max};
	}
	else {
		int max_weight = min(cur_max, dist[cur][to[cur]]);
		dfs(to[cur], cur, max_weight, source);
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 0 ,a,b,c; i < m ; i++){
		cin >> a >> b >> c;
		to[a] = b;
		from[b] = a;
		dist[a][b] = c;
	}
	for (int i = 1 ; i <= n; i++){
		if (!visited[i]) {
			if (to[i] && (from[i] == 0)) dfs(i, i, 1e9, i);			// a tank cannot have a pipe flowing to it. And we only want to process the tanks. If a house doesn't have a pipe flowing to it (from[i] == 0), then it is a tank.
		}
	}
	cout << ans_num << "\n";
	for (int i = 1; i <= 1000; i++){
		if (ans[i] != make_pair(0,0)) cout << i << " " << ans[i].first << " "  << ans[i].second << "\n";
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*int T;
	cin >> T;
	while (T--){
		solve();
	}*/
	solve();
}


