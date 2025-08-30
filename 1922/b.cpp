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
#define sort_all(a) sort(a.begin(), a.end())

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

ull choose[300002];
ull C[300002];

void solve() {
	int n;
	cin >> n;
	vector<ull>a(n);
	vector<ull>cnt(n + 1, 0);
	set<ull>s;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		s.insert(a[i]);
	}
	ull ans = 0;
	vector<ull>tmp;
	for (auto it = s.begin(); it != s.end(); it++) {
		tmp.pb(*it);
	}
	if (n <= 2) {
		cout << "0\n";
		return;
	}
	ans = choose[cnt[tmp[0]]];
	vector<ull>pref(tmp.size() + 1, 0);
	for (int i = 1; i < tmp.size(); i++) {
		pref[i] = pref[i - 1] + cnt[tmp[i-1]];
		ans += choose[cnt[tmp[i]]];	// choose 3 within current;
		ans += C[cnt[tmp[i]]]*pref[i];	// choose 2 from current and 1 from last;
	}
	cout << ans << "\n";
}

int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	choose[1] = choose[2] = 0;
	choose[3] = 1;
	C[1] = 0;
	C[2] = 1;
	C[3] = 3;
	for (ull i = 4; i <= 300001; i++) {
		choose[i] = (choose[i-1]*i) / (i-3);
		C[i] = (C[i-1]*i) / (i - 2);
	}
	
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
	
}


