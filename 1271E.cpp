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


void solve() {
	
}

int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
	ull n, k;
	cin >> n >> k;
	if (n == k) {
		cout << 1 << "\n";
		return 0;
	}
	ull i = n;
	
	/*
	The idea is to divide numbers from 1 to n into log2(n) segments.  
	This is because every even number, except the last 2 numbers in each segment, has the same number of paths. The same for odd numbers.
	After this, we only have to account for the last 2 numbers.
	
	*/
	vector<vector<ull>>segments;	
	vector<ull>tmp(4);		// tmp[0] = nums of path of even numbers. tmp[1] = nums of paths of odd numbers. tmp[2] = nums of paths of the last number. tmp[3] = nums of paths of the second last number.
	vector<int>parity;		// 1 if the last number in the segment is odd
	if (i % 2 == 1) {
		tmp = {2, 1 , 1, 2};
		parity.pb(1);
	}
	else {
		tmp = {2, 1, 1, 1};
		parity.pb(0);
	}
	segments.pb(tmp);
	i /= 2;
	while (i > 0) {
		tmp = vector<ull>(4);
		if (i % 2 == 0) {
			tmp[1] = segments.back()[0] + 1;
			tmp[0] = segments.back()[0] + tmp[1] + 1;
			if (parity.back() == 0) tmp[2] = segments.back()[2] + segments.back()[1] + 1;
			else tmp[2] = segments.back()[3] + segments.back()[1] + 1;
			tmp[3] = tmp[1];
			parity.pb(0);
		}
		else {
			tmp[1] = segments.back()[0] + 1;
			tmp[0] = segments.back()[0] + tmp[1] + 1;
			if (parity.back() == 1) tmp[2] = segments.back()[3] + 1;
			else tmp[2] = segments.back()[2] + 1;
			tmp[3] = segments.back()[0] + tmp[2] + 1;
			parity.pb(1);
		}
		segments.pb(tmp);
		i /= 2;
	}
	
	i = 0;
	for (; i < segments.size(); i++) {
		if (k <= segments[i][2]) {
			for (int j = 1; j <= i; j++) {
				n /= 2;
			}
			cout << n << "\n";
			break;
		}
		else if (k <= segments[i][3]) {
			for (int j = 1; j <= i; j++) {
				n /= 2;
			}
			cout << n - 1 << "\n";
			break;
		}
		else {
			if (parity[i] == 0) {
				if (k <= segments[i][0]) {
					for (int j = 1; j <= i; j++) {
						n /= 2;
					}
					cout << n - 2 << "\n";
					break;
				}
				else if (k <= segments[i][1]) {
					for (int j = 1; j <= i; j++) {
						n /= 2;
					}
					cout << n - 3 << "\n";
					break;
				}
			}
			else {
				if (k <= segments[i][1]) {
					for (int j = 1; j <= i; j++) {
						n /= 2;
					}
					cout << n - 2 << "\n";
					break;
				}
				else if (k <= segments[i][0]) {
					for (int j = 1; j <= i; j++) {
						n /= 2;
					}
					cout << n - 3 << "\n";
					break;
				}
			}
		}
	}
}


