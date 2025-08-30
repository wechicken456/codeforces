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
	int n;
	cin >> n;
	vector<vector<int>>cnt(5, vector<int>(n, 0));
	for (int i = 0 ; i < n; i++) {
		string s;
		cin >> s;
		int k = s.length();
		for (int j = 0 ; j < k; j++) {
			cnt[s[j]- 'a'][i]++;
		}
		for (int j = 0; j < 5; j++) {
			cnt[j][i] -= (k - cnt[j][i]);
		}
	}
	vector<int>ans(5);
	for (int i = 0 ; i < 5; i++) {
		sort(cnt[i].begin(), cnt[i].end());
		int sum = 0;
		for (int j = n - 1; j >= 0 ; j--) {
			if (sum + cnt[i][j] > 0) {
				sum += cnt[i][j];
				ans[i]++;
				//cout << i << " "  << ans[i] << "\n";
			}
			else break;
		}
	}
	int answer = 0;
	for (int i = 0; i < 5 ; i++) {
		answer = max(answer, ans[i]);
	}
	cout << answer << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--){
		solve();
	}
}


