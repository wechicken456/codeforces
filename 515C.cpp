#include<bits/stdc++.h>
#include<set>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

typedef  long long ll;
typedef unsigned long long ull;

using namespace std;

ll power(ll x, ull y) {
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
	string s;
	cin >> s;
	vector<int>ans;
	for(int i = 0; i < n;i++){
		if (s[i]!='0' && s[i]!='1') {
			if (s[i] == '4')  {
				ans.push_back(2);
				ans.push_back(2);
				ans.push_back(3);
			}
			else if (s[i] == '8') {
				ans.push_back(7);
				ans.push_back(2);
				ans.push_back(2);
				ans.push_back(2);
			}
			else ans.push_back(s[i] - '0');
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = ans.size()-1 ; i >= 0; i--) cout << ans[i];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*int T;
	cin >> T;
	while (T--){
		solve();
	}*/
	solve();
}


