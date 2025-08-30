#include<bits/stdc++.h>

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

/*
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



//		Shortest path between any pairs
int dist[maxN][maxN];
void compute_shortest_path() {
	// essentially we start at city j, go to city k through city i.
	for (int i = 1; i <= n; i++){		// i is the intermediate city
		for (int j = 1; j <= n; j++){	// starting from city j
			for (int k = 1; k <= n; k++){	// destination is city k
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
}


//	Shortest path between one node and others
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

vector<vector<ll>>dist;
vector<vector<pair<ll, int>>>edge;
int n;
void bfs(int start) {
	vector<bool>visited(n, false);
	priority_queue<pair<ll, int>>pq;
	pq.push({0, start});
	dist[start][start] = 0;
	while (pq.size()) {
		auto p = pq.top();
		int node = p.second;
		pq.pop();
		if (visited[node]) continue;
		
		visited[node] = true;
		for (auto &nxt : edge[node]) {
			ll weight = nxt.first, nxt_node = nxt.second;
			if (dist[start][node] + weight < dist[start][nxt_node]) {
				dist[start][nxt_node] = dist[start][node] + weight;
				pq.push({-dist[start][nxt_node], nxt_node});
			}
		}
	}
}

int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int m, k;
	cin >> n >> m >> k;
	dist = vvll(n, vll(n, 1e7));
	edge = vector<vector<pair<ll, int>>>(n);
	vector<pair<int ,int>>edges;
	for (int i = 0; i < m; i++) {
		int x, y;
		ll w;
		cin >> x >> y >> w;
		x--;
		y--;
		edge[x].pb({w, y});
		edge[y].pb({w, x});
		edges.pb({x ,y});
	}
	
	// run Dijkstra on every node.
	for (int i = 0 ; i < n; i++) {
		bfs(i);
	}
	
	vector<pair<int ,int>>q;
	for (int i = 0; i < k; i++) {
		int x ,y;
		cin >> x >> y;
		x--;
		y--;
		if (x == y) continue;
		q.pb({x, y});
	}
	
	if (q.size() == 0) {
		cout << "0\n";
		return 0;
	}
	
	
	// bruteforce: for every edge, assign its cost to 0, then calculate sum of cost of all queries, take the minimum sum.
	// calculate each query cost: first find mininmum of cost from start to one vertex of the current edge being converted to 0 + minimum from the other vertex to end.
	// i.e. tmp = min(start -> x + y -> end, start -> y + x -> end)
	// then answer for this query is min(dist[start][end], tmp)
	ll ans = 1e9;
	for (int i = 0; i < m; i++) {
		ll sum = 0;
		int x = edges[i].first;
		int y = edges[i].second;
		for (int j = 0 ; j  < q.size() ; j++) {
			
			int start = q[j].first;
			int end = q[j].second;
			
			ll tmp1 = dist[start][x] + dist[y][end];
			ll tmp2 = dist[start][y] + dist[x][end];
			ll tmp = min(tmp1, tmp2);
			sum += min(tmp, dist[start][end]);
		}
		ans = min(ans , sum);
	}
	cout << ans << "\n";
}


