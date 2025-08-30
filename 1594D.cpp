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

vector<ll>tree;
const ll maxA = 1e9+1;
int n,q;

				// SEGMENT TREE MINIMUM 

ll query(int node, int node_low, int node_high, int query_low, int query_high){
	if (node_low >= query_low && node_high <= query_high) {
		return tree[node];
	}
	if(node_low > query_high || node_high < query_low) {
		return maxA;
	}

	int middle = (node_low + node_high)/2;
	return min(query(2 * node, node_low, middle, query_low, query_high) 		// left child
		 , query(2 * node + 1, middle + 1, node_high, query_low, query_high));	// right child
}

void build_tree(vector<ll>a) {
	// pad with 0 to make power of 2
	while (__builtin_popcount(n) != 1) {
		a.push_back(maxA);
		n++;
	}
	tree.resize(2 * n);
	// copy elements
	for (int i = 0 ; i < n; i++){
		tree[i+n] = a[i];
	}
	// start building nodes
	for (int i = n-1; i >= 1; i--){
		tree[i] = min(tree[2*i] , tree[2*i+1]);
	}

}

void update(int pos, ll value){
	tree[pos] = value;
	pos /= 2;
	while (pos > 0) {
		ll cur_min = min(tree[2*pos], tree[2*pos+1]);
		if ( cur_min == tree[pos]) return;
		tree[pos] = cur_min;
		pos /= 2;
	}
}



/*		Shortest path between any pairs
int dist[maxN][maxN];
void compute_shortest_path() {
	// essentially we start at city j, go to city k through city i.
	for (int i = 1; i <= n; i++){			// i is the intermediate city
		for (int j = 1; j <= n; j++){		// starting from city j
			for (int k = 1; k <= n; k++){	// destination is city k
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
}
*/

/*	Shortest path between one node and others
vector<int>adj[maxN];
// find shortest path using Dijkstra's algorithm
priority_queue<pair<ull,int>>q; 		// default sort by first element in pairs
dist[1] = 0;
q.push({0, 1});
while (!q.empty()) {
	pair<ull,int> cur_top = q.top();
	q.pop();
	ull parent_node = cur_top.second;
	if (visited[parent_node]) continue;
	visited[parent_node] = true;
	for (auto &cur : adj[parent_node]) {
		ull weight = cur.second, cur_node = cur.first;
		if (dist[parent_node] + weight < dist[cur_node]) {
			dist[cur_node] = dist[parent_node] + weight;
			q.push({-dist[cur_node], cur_node});
		}
	}
}
*/

vb visited;
vb count_visited;
vll to;
vector<vector<pll>> adj;
vll parity;
int ans;

int dfs(int node, int par) {
	if (visited[node]) {
		if (par != parity[node]) return -1;
		return 0;
	}
	visited[node] = true;
	parity[node] = par;
	
	for (auto &next : adj[node]) {
		int res = dfs(next.first, par * next.second);
		if (res == -1) return -1;
	}
	return 0;
} 

int count_dfs(int node) {
	if (count_visited[node]) {
		return 0;
	}
	count_visited[node] = true;
	int sum = (parity[node] == -1);
	for (auto &next : adj[node]) {
		sum += count_dfs(next.first);
	}
	return sum;
}

void clean (int node) {
	if (!visited[node]) return;
	visited[node] = false;
	count_visited[node] = false;
	parity[node] = 1;
	for (auto &next : adj[node]) {
		clean(next.first);
	}
}

void solve() {
	int m;
	cin >> n >> m;
	visited = vb(n + 1, false);
	count_visited = vb(n + 1, false);
	adj = vector<vector<pll>>(n + 1);
	parity = vll(n + 1, 1);
	to = vll(n + 1, 0);
	ans = 0;
	
	for (int i = 0 ; i < m; i++) {
		int a, b, c = 1 ;
		string s;
		cin >> a >> b >> s;
		if (s == "imposter") c = -1;
		adj[a].pb(mp(b, c));
		to[b]++;
	}
	
	int first_round = 0;
	for (int i = 1; i <= n; i++) {
		if (to[i] == 0) {
			if (adj[i].size() == 0) {
				visited[i] = true;
				first_round++;
				continue;
			}
			int check_1 = dfs(i ,1);
			int res_1 = count_dfs(i);
			clean(i);
			int check_2 = dfs(i , -1);
			int res_2 = count_dfs(i);
			if (check_1 == -1 && check_2 == -1) {
				cout << "-1\n";
				return;
			}
			else first_round += max(res_1, res_2);
		}
	}
	ans = first_round;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int check_1 = dfs(i , 1);
			int res_1 = count_dfs(i);
			clean(i);
			int check_2 = dfs(i , -1);
			int  res_2 = count_dfs(i);
			if (check_1 == -1 && check_2 == -1) {
				cout << "-1\n";
				return;
			}
			else ans += max(res_1, res_2);
		}
	}
	cout << ans << "\n";
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
	/*
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	*/
	int T;
	cin >> T;
	while (T--) solve();
	
}


