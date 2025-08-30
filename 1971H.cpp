// 2SAT, 2-SAT, 2sat
// https://cp-algorithms.com/graph/2SAT.html#algorithm
// https://codeforces.com/contest/1971/problem/H
// https://codeforces.com/blog/entry/129364

#include <bits/stdc++.h>
#define ll long long
#define pb push_back

#define pll pair<long long, long long>
using namespace std;
ll n;

vector<vector<ll>> grid;
vector<vector<ll>> adj;
vector<ll> st;
vector<bool> visited;
vector<ll> id;
vector<ll> si;
vector<ll> COMPS;
vector<ll> comp;
vector<ll> idx;
ll ti = 0; 

ll dfs_scc(int v) {
  ll low = idx[v] = ti++;
  st.pb(v);
  for (auto &u : adj[v]) {
    if (idx[u] == -1) {
      low = min(low, dfs_scc(u));
    } else if (comp[u] == -1) {
      low = min(low, idx[u]);
    }
  }
  if (low == idx[v]) {
    COMPS.pb(v);
    id[v] = COMPS.size() - 1;	// v belongs to component COMPS.size() - 1
    ll from = -1;
    for (; from != v;) {
	  comp[from = st.back()] = v;
	  st.pop_back();
    }
  }
  return low;
}

void add_clause(int a, bool not_a, int b, bool not_b) {
	// in conjuctive normal form (CNF), a V b
	// implies (not a) => b AND (not b) => a
	// 2 * i corresponds to the variable, while  2*i + 1 is the negated one.
	adj[2 * a + (not_a ? 0 : 1)].pb(2 * b + (not_b ? 1 : 0));
	adj[2 * b + (not_b ? 0 : 1)].pb(2 * a + (not_a ? 1 : 0));
}

void solve() {
	cin >> n;
	  grid = vector<vector<ll>>(3, vector<ll>(n));
	  id = vector<ll>(n*2, -1);
	  comp.assign(n*2, -1);
	  idx.assign(n*2, -1);
	  visited.assign(n*2, false);
	  COMPS.clear();
	  st.clear();
	  adj = vector<vector<ll>>(2*n);
	  for (int i = 0 ; i < 3 ; i++) {
		  for (int j = 0; j < n; j++) {
			  cin >> grid[i][j];
		  }
	  }
	  
	  for (int i = 0 ; i < n;  i++) {
		  for (int j = 0 ; j < 3; j++) {
			  int nxt = (j + 1) % 3;
			  // in order for the middle row to be all 1s, each column must have at least 2 1s
			  // => one of (x, y) = 1 && one of (x, z) = 1 && one of (y, z) = 1
			  // => (x OR y) AND (y OR z) AND (x OR z)
			  // so we have 3 clauses. Each clause wil generate 2 implication edges.
			  // if this spot is currently neg, then we need -1 in this spot
			  add_clause(abs(grid[j][i]) - 1, grid[j][i] > 0, abs(grid[nxt][i]) - 1, grid[nxt][i] > 0);
		  }
	  }

	  for (int i = 0; i < 2*n; i++) {
		if (comp[i] == -1) {
		  dfs_scc(i);
		}
	  }
	  
	  for (int i = 0 ; i < 2*n; i+=2) {
		  if (comp[i] == comp[i+1]) {
			  cout << "NO\n";
			  return;
		  }
	  }
	  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; 
  cin >> T;
  while (T--) {
	  solve();
  }
  return 0;
}
