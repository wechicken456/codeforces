#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n, m, s;

vector<vector<pair<ll, ll>>> adj;
vector<vector<pair<ll, ll>>> condensed_adj;
vector<ll> st;
vector<bool> visited;
vector<ll> id;
vector<ll> si;
vector<ll> COMPS;
vector<ll> comp;
vector<ll> idx;
vector<ll> weight;
vector<ll> sum_N(14143);
vector<ll> pref_sum_N(14143);
vector<bool> condensed_visited;
vector<ll> dp;
ll ti = 0;

ll gen_weight(int v) {
	if (visited[v]) return 0;
	
	ll sum = weight[v];
	visited[v] = true;
	for (auto &p: adj[v]) {
		ll u = p.first, w = p.second;
		if (comp[v] == comp[u]) {
			// how many times we can pick up mushrooms at the same edge
			// essentially the smallest sum of the first N integers that > w
			ll k = lower_bound(sum_N.begin(), sum_N.end(), w) - sum_N.begin();
			// w + (w - 1) + (w - 1 - 2) +... + (w - ... - (k - 1))
			// = k*w - (1 + (1 + 2) + (1 + 2 + 3) + ... + (1 + 2 + ... + k - 1))
			if (k > 0) sum += (k*w - pref_sum_N[k-1]);
			
			sum += gen_weight(u);
		}
	}
	return sum;
}

ll dfs_gen(int v) {
  ll low = idx[v] = ti++;
  st.pb(v);
  for (auto &p : adj[v]) {
    ll u = p.first;
    if (idx[u] == -1) {
      low = min(low, dfs_gen(u));
    } else if (comp[u] == -1) {
      low = min(low, idx[u]);
    }
  }
  if (low == idx[v]) {
    COMPS.pb(v);
    id[v] = COMPS.size() - 1;
    ll from = -1;
    for (; from != v;) {
	  comp[from = st.back()] = v;
	  st.pop_back();
    }
  }
  return low;
}

// dfs on condensed DAG to find ans
ll dfs_ans(int v) {
	if (condensed_visited[v]) return dp[v];
	condensed_visited[v] = true;
	ll max_child = 0;
	for (auto &p : condensed_adj[v]) {
		max_child = max(max_child, p.second + dfs_ans(p.first));
		//cout << v << "=>" << p.first << " " << max_child << "\n";
	}
	dp[v] = max_child + si[v];
	return dp[v];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  adj.resize(n);
  id.assign(n, -1);
  comp.assign(n, -1);
  idx.assign(n, -1);
  weight.assign(n, 0);	// sum of all self-loops
  visited.assign(n, false);
  
  sum_N[0] = 0;
  pref_sum_N[0] = 0;
  for (ll i = 1 ; i <= 14142; i++) {
	  sum_N[i] = sum_N[i-1] + i;
	  pref_sum_N[i] = pref_sum_N[i-1] + sum_N[i];
  }
  for (int i = 0; i < m; i++) {
    ll a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    if (a == b) {
		ll k = lower_bound(sum_N.begin(), sum_N.end(), w) - sum_N.begin();
		// w + (w - 1) + (w - 1 - 2) +... + (w - ... - (k - 1))
		// = k*w - (1 + (1 + 2) + (1 + 2 + 3) + ... + (1 + 2 + ... + k - 1))
		weight[a] += (k*w - pref_sum_N[k-1]);
	}
    else adj[a].pb({b, w});
  }
  cin >> s;
  s--;
  for (int i = 0; i < n; i++) {
    if (comp[i] == -1) {
      dfs_gen(i);
    }
  }
  
  si.resize(COMPS.size());
  
  for (int i = 0 ; i < COMPS.size(); i++) {
	  si[i] = gen_weight(COMPS[i]);
  }
  
  condensed_adj.resize(COMPS.size());
  condensed_visited.assign(COMPS.size(), false);
  dp.assig	n(COMPS.size(), 0);
  for (int i = 0; i < n; i++) {
    for (auto &p : adj[i]) {
      if (comp[i] != comp[p.first]) {
        condensed_adj[id[comp[i]]].pb({id[comp[p.first]], p.second});
       //cout << i << "->" << p.first << ": " << id[comp[i]] << " " << id[comp[p.first]] << "\n";
      }
    }
  }
  cout << dfs_ans(id[comp[s]]) << "\n";
  return 0;
}
