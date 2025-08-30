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

// https://codeforces.com/contest/1797/problem/D

struct cmp {
	bool operator () (const pll &a, const pll &b)  const{
		if (a.first != b.first) {
			return a.first > b.first;
		}
		else return a.second < b.second;
	}
};

struct Node {
	ll si = 0;
	ll idx = 0;
	set<pll, cmp>s;
};

ll n, m;
vector<ll>val(100001, 0);			// `importance` 
vector<Node>tree(100001);		// first is `size of subtree`, second is index of node
vector<vector<ll>>tmp_adj(100001);
vector<ll>par(100001);

void make_tree(int node) {
	for (auto &nxt : tmp_adj[node]) {
		if (nxt != par[node]) {
			par[nxt] = node;
			make_tree(nxt);
			
			val[node] += val[nxt];
			tree[node].si += tree[nxt].si;
			tree[node].s.insert({tree[nxt].si, nxt});
		}
	}
}

int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1 ; i  <= n; i++) {
		cin >> val[i];
		tree[i].si = 1;
		tree[i].idx = i;
	}
	for (int i = 0 ; i < n - 1 ; i++) {
		ll u, v;
		cin >> u >> v;
		tmp_adj[u].pb(v);
		tmp_adj[v].pb(u);
	}
	par[1] = 0;
	make_tree(1);
	for (int i = 0 ; i < m ;i++) {
		int type, node;
		cin >> type >> node;
		if (type == 1) {
			cout << val[node] << "\n";
		}
		else {
			if (tree[node].s.size() == 0) continue;
			
			int p = par[node];
			int son = (tree[node].s.begin())->second;	// heavy son of `node`
			
			// remove edge from par[node] to node
			tree[p].s.erase({tree[node].si, node});	
			
			// remove edge from node to son
			tree[node].s.erase({tree[son].si, son});
			tree[node].si -= tree[son].si;
			val[node] -= val[son];
			
			// add edge from son to node
			tree[son].s.insert({tree[node].si, node});
			tree[son].si += tree[node].si;
			val[son] += val[node];
			par[node] = son;
			
			// add edge from par[node] to son
			tree[p].s.insert({tree[son].si, son});
			par[son] = p;
		}
	}
	/*
	for (int i = 1;  i <= n; i++) {
		cout << "node #" << i << "\n";
		for (auto p : tree[i].s) {
			cout << p.first << " " << p.second << "\n";
		}
	}*/
}


