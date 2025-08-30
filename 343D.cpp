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


ull power(ll x, ull y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
/* 
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

struct Node {
	vector<int>ancestor;	// ancestor[i] = the (2^(i - 1))th ancestor, except ancestor[0] = the node itself
	int depth;				// how far down the tree is this node
};

vector<int>parent;
vector<vector<int>>adj;
vector<Node>tree;
int powers_2[19];
int director = 0;
/*
int get_common(int a, int b) {	// assuming a and b are of the same depth
	int i = 0;
	for (; i < tree[a].ancestor.size(); i++) {
		if (tree[a].ancestor[i] == tree[b].ancestor[i]) {
			break;
		}
	}
	if (i == 0) {
		return a;
	}
	else if (i == 1) {
		return parent[a];
	}
	else {	// find the first common ancestor (DOESN'T HAVE TO BE LOWEST), then go back 1 power of 2 to find the LOWEST common ancestor
		return get_common(tree[a].ancestor[i-1], tree[b].ancestor[i-1]);
	}
}
*/
int get_ancestor(int node, int k) {
	for (int i = tree[node].ancestor.size() - 1; i >= 0; i--) {
		if ((k >> i) & 1) node = tree[node].ancestor[i];
	}
	return node;
} 

void build_node(int cur_node, int cur_depth, int p) {
	int levels = (cur_depth != 0) ? floor(log2(cur_depth)) : 0;
	tree[cur_node].depth = cur_depth;
	tree[cur_node].ancestor = vector<int>(levels + 1);				
	tree[cur_node].ancestor[0] = p;						// we alr know 1th ancestor is its parent
	
	for (int i = 1 ; i < levels + 1; i++) {				// every 2^i-th ancestor is the 2^(i-1)-th ancestor of the previous ancestor
		tree[cur_node].ancestor[i] = tree[ tree[cur_node].ancestor[i-1] ].ancestor[i-1];
	}
	for (int &nxt : adj[cur_node]) {
		if (nxt != p) build_node(nxt, cur_depth + 1, cur_node);
	}
}
	
void solve() {
	
	int n, q;
	cin >> n;
	//parent = vector<int>(n, -1);
	adj = vector<vector<int>>(n);
	tree = vector<Node>(n);

	for (int i = 1 ; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[b].pb(a);
		adj[a].pb(b);
	}
	
	build_node(0, 0, 0);
	
	cin >> q;
	
	vector<pair<int, int>>qa;
	for (int i= 0 ; i < q; i++) {
		int t, b;
		cin >> t >> b;
		b--;
		if (t != 3) {
			qa.pb({t, b});
		}
		else {
			int ans = 0;
			for (int j = qa.size() - 1; j >= 0; j--) {
				int node_q = qa[j].second;
				if (qa[j].first == 1) {
					if (tree[node_q].depth <= tree[b].depth) {
						b = get_ancestor(b, tree[b].depth - tree[node_q].depth);
						if (b == node_q) {
							ans = 1;
							break;
						}
					}
				}
				else {
					if (tree[node_q].depth >= tree[b].depth) {
						node_q = get_ancestor(node_q, tree[node_q].depth - tree[b].depth);
						if (node_q == b) {
							ans = 0;
							break;
						}
					}
				}
			}
			cout << ans << "\n";
		}
	}
}

int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	
	/*
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	*/
	
}


