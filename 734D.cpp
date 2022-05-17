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

void solve() {
	scanf("%d", &n);
	ll king_x, king_y;
	scanf("%lld %lld", &king_x, &king_y);
	ll up = 3e9, down = -3e9, right = 3e9, left = -3e9;
	ll up_right = 3e9, up_left = 3e9, down_right= 3e9, down_left= 3e9;
	bool check_up, check_down, check_right, check_left, check_upright, check_upleft,check_downright,check_downleft;
	check_up = check_down = check_right = check_left = check_upright = check_upleft = check_downright = check_downleft = false;
	for (int i = 0 ; i < n; i++) {
		ll x ,y ;
		char piece;
		getc(stdin);
		piece = getc(stdin);
		scanf(" %lld %lld", &x, &y);
		ll diff_x = x - king_x, diff_y = y - king_y;
		// check vertical
		if (x == king_x) {
			if (y > king_y) {
				if (y < up) {
					up = y;
					if (piece == 'Q' || piece == 'R') check_up = true;
					else check_up = false;
				}
			}
			else {
				if (y > down) {
					down = y;
					if (piece == 'Q' || piece == 'R') check_down = true;
					else check_down = false;
				}
			}
		}
		// check horizontal
		else if (y == king_y) {
			if (x > king_x) {
				if (x < right) {
					right = x;
					if (piece == 'Q' || piece == 'R') check_right = true;
					else check_right = false;
				}
			}
			else {
				if (x > left) {
					left = x;
					if (piece == 'Q' || piece == 'R') check_left = true;
					else check_left = false;
				}
			}
		}
		
		// check diagonal
		else if (abs(diff_x) == abs(diff_y)){
			
			// check up_right
			if (diff_x > 0 && diff_y > 0) {
				if (diff_x < up_right) {
					up_right = diff_x;
					if (piece == 'Q' || piece == 'B') check_upright = true;
					else check_upright = false;
				}
			}
			// check up_left
			else if (diff_x < 0 && diff_y > 0) {
				if (diff_y < up_left) {
					up_left = diff_y;
					if (piece == 'Q' || piece == 'B') check_upleft = true;
					else check_upleft = false;
				}
			}
			// check down_left
			else if (diff_x < 0 && diff_y < 0) {
				if (abs(diff_x) < down_left) {
					down_left = abs(diff_x);
					if (piece == 'Q' || piece == 'B') check_downleft = true;
					else check_downleft = false;
				}
			}
			// check down_right
			else {
				if (diff_x < down_right) {
					down_right= diff_x;
					if (piece == 'Q' || piece == 'B') check_downright = true;
					else check_downright = false;
				}
			}
		}
		
	}
	if (check_left || check_right || check_up || check_down || check_upleft || check_upright || check_downleft || check_downright) puts("YES");
	else puts("NO");
}

int main(){
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	*/
	
	/*
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	*/
	
	solve();
	
}


