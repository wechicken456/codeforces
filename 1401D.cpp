#include <bits/stdc++.h>

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
const ll MOD = 1000000007;
ll n, m;
ll real_m;
vector<vector<ll>> adj;
ll cnt_w = 0;
ll factors[1000000], w[1000000];

bool comp(ll a, ll b) { return a > b; }

// returns the # of nodes in the subtree u
ll dfs(int u, int par) {
    ll num_nodes = 1;
    for (ll &v : adj[u]) {
        if (v != par) {
            ll d = dfs(v, u);
            w[cnt_w] = d * (n - d);
            cnt_w++;
            num_nodes += d;
        }
    }
    return num_nodes;
}

void solve() {
    cin >> n;
    adj = vector<vector<ll>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> factors[i];
    }
    if (m <= n - 1) {
        for (int i = m; i < n - 1; i++) {
            factors[i] = 1;
        }
        sort(factors, factors + (n - 1));
    } else {
        sort(factors, factors + m);
        for (int i = n - 1; i < m; i++) {
            factors[n - 2] *= factors[i];
            factors[n - 2] %= MOD;
        }
    }
    cnt_w = 0;
    dfs(1, -1);
    sort(w, w + (n - 1), comp);
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (w[i] * factors[n - 2 - i]);
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
