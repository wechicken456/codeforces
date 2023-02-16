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

struct Node {
	vll ancestor;
	int depth;
	int size;
};

vvll edge;
vector<Node> tree;

void build_tree(int cur_node, int cur_depth, int p) {
	int levels = (cur_depth == 0) ? 0 : floor(log2(cur_depth));
	tree[cur_node].ancestor.resize(levels + 1);
	tree[cur_node].ancestor[0] = p;
	tree[cur_node].size = 1;
	tree[cur_node].depth = cur_depth;
	for (int i = 1; i < levels + 1; i++) {
		tree[cur_node].ancestor[i] = tree[ tree[cur_node].ancestor[i-1] ].ancestor[i-1];
	}
	for (auto &nxt : edge[cur_node]) {
		if (nxt != p) {
			build_tree(nxt, cur_depth + 1, cur_node);
			tree[cur_node].size += tree[nxt].size;
		}
	}
}

int get_ancestor(int node, int k) {
	for (int i = tree[node].ancestor.size() - 1; i >= 0 ; i--) {
		if (i >= tree[node].ancestor.size()) continue;
		if (k & (1 << i)) {
			node = tree[node].ancestor[i];
		}
	}
	return node;
}

int lca(int a, int b) {
	if (tree[a].depth < tree[b].depth) {
		swap(a, b);
	}
	
	int diff = tree[a].depth - tree[b].depth;
	
	a = get_ancestor(a, diff);
	if (a == b) return a;
	
	for (int i = tree[a].ancestor.size() - 1; i >= 0; i--) {
		if (i >= tree[a].ancestor.size()) continue;

		if (tree[a].ancestor[i] != tree[b].ancestor[i]) {
			a = tree[a].ancestor[i];
			b = tree[b].ancestor[i];
		}
	}
	return tree[a].ancestor[0];
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	tree = vector<Node>(n);
	edge = vvll(n);
	for (int i = 1; i < n; i++) {
		int a ,b;
		cin >> a >> b;
		a--;
		b--;
		edge[a].pb(b);
		edge[b].pb(a);	
	}
	
	build_tree(0, 0, 0);
	
	int q;
	cin >> q;
	for (int i = 0 ; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (a == b) {
			cout << n << "\n";
			continue;
		}
		if (tree[a].depth < tree[b].depth) swap(a, b);
		
		int common = lca(a, b);
		int diff_a = tree[a].depth - tree[common].depth;
		int diff_b = tree[b].depth - tree[common].depth;
		if ((diff_a + diff_b) % 2 == 1) {
			cout << "0\n";
		}
		else {
			if (diff_a == diff_b) {
				for (int j = tree[a].ancestor.size() - 1; j >= 0; j--) {
					if (j >= tree[a].ancestor.size()) continue;

					if (tree[a].ancestor[j] != tree[b].ancestor[j]) {
						a = tree[a].ancestor[j];
						b = tree[b].ancestor[j];
					}
				}
				cout << n - (tree[a].size + tree[b].size) << "\n";;
			}
			else {
				int lower = get_ancestor(a, (diff_a + diff_b) / 2 - 1);
				int middle = tree[lower].ancestor[0];
				cout << tree[middle].size - tree[lower].size << "\n";
			}
		}
	}
}


