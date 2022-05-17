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


vector<ll>row;
vector<ll>col;

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

vector<vector<bool>>tree;
const ll maxA = 1e9+1;
int n,q;

				// SEGMENT TREE MINIMUM 

bool query_row(int node, int node_low, int node_high, int row_low, int row_high){
	if (node_low >= row_low && node_high <= row_high) {
		return tree[0][node] == true;
	}
	if(node_low > row_high || node_high < row_low) {
		return true;
	}

	int middle = (node_low + node_high)/2;
	return query_row(2 * node, node_low, middle, row_low, row_high) &&		// left child
		  query_row(2 * node + 1, middle + 1, node_high, row_low, row_high);	// right child
}

bool query_col(int node, int node_low, int node_high, int col_low, int col_high) {
	if (node_low >= col_low && node_high <= col_high) {
		return tree[1][node] == true;
	}
	if(node_low > col_high || node_high < col_low) {
		return true;
	}

	int middle = (node_low + node_high)/2;
	return query_col(2 * node, node_low, middle, col_low, col_high) &&		// left child
		  query_col(2 * node + 1, middle + 1, node_high, col_low, col_high);
}

void build_tree() {
	// pad with 0 to make power of 2
	while (__builtin_popcount(n) != 1) {
		row.pb(0);
		col.pb(0);
		n++;
	}
	tree = vector<vector<bool>>(2, vector<bool>(2*n));
	// copy elements
	for (int i = 0 ; i < n; i++){
		tree[0][i+n] = row[i];
		tree[1][i+n] = col[i];
	}
	// start building nodes
	for (int i = n-1; i >= 1; i--){
		tree[0][i] = tree[0][2*i] && tree[0][2*i+1];
		tree[1][i] = tree[1][2*i] && tree[1][2*i+1];
	}

}

void update(int r, int c){
	tree[0][r + n] = row[r] > 0;
	tree[1][c + n] = col[c] > 0;
	int pos = (r + n) / 2;
	while (pos > 0) {
		tree[0][pos] = tree[0][2*pos] && tree[0][2*pos+1];
		pos /= 2;
	}
	pos = (c + n) / 2;
	while (pos > 0) {
		tree[1][pos] = tree[1][2*pos] && tree[1][2*pos+1];
		pos /= 2;
	}
}


void solve() {
	cin >> n >> q;
	row = vector<ll>(n, 0);
	col = vector<ll>(n, 0);
	build_tree();
	for (int i = 0 ; i < q; i ++) {
		int t; cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			row[x]++;
			col[y]++;
			update(x, y);
		}
		else if (t == 2){
			int x,y;
			cin >> x >> y;
			x-- ; y--;
			row[x]--;
			col[y]--;
			update(x, y);
		}
		else {
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--; y1--; x2--; y2--;
			if (query_col(1, 0, n - 1, y1, y2) || query_row(1, 0, n - 1, x1, x2)) {
				cout << "Yes\n";
			}
			else cout << "No\n";
		}
	}
}

int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	
	
	solve();

}


