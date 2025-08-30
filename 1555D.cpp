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

void solve(){

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q ;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<vector<int>>a(6 , vector<int>(n, 0));
	vector<vector<int>>prefix_sum(6, vector<int>(n, 0));
	string temp = "abc";
	int cur = 0;
	do {
		for (int i = 0; i < n; i++) {
			a[cur][i] = (s[i] != temp[i % 3]);
			if (i > 0) prefix_sum[cur][i] = prefix_sum[cur][i-1] + a[cur][i];
			else prefix_sum[cur][0] = a[cur][i];
			//cout << prefix_sum[cur][i] << " ";
		}
		cur++;
	} while (next_permutation(temp.begin(), temp.end()));
	for (int i = 0,low,high ; i < q; i++) {
		cin >> low >> high;
		low--;
		high--;
		int ans = 1e9;
		for (int j = 0 ; j < 6; j++) {
			ans = min(ans, prefix_sum[j][high] - prefix_sum[j][low] + a[j][low]);
		}
		cout << ans << "\n";
		}
}


