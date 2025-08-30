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

#define ll long long
#define ull unsigned long long
#define pb push_back

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
const int maxN  = 2e5;
int n, m;
vector<int>cur(maxN + 1);
vector<int>after(maxN + 1);

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> cur[i];
	}
	for (int i = 1; i <= n ; i++){
		cin >> after[i];
	}
	int new_score = cur[m] + after[1];
	int cur_first = 1;
	int cur_end = m - 1;
	int after_first = n - m + 2;
	int after_end = n;
	int highest  = 1;
	int ans = highest;

}

int main(){
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--){
		solve();
	}*/
	solve();
}


