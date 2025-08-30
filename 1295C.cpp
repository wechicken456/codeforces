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

const int maxN = 1e5;
int first[maxN + 1][27];

void solve(){
	string s,t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	
	for (int i = 0 ; i <= n; i++){
		for (int j = 0 ; j < 26; j++)
			first[i][j] = 1e9;
	}
	
	
	for(int i = n - 1; i >= 0; --i){
       for(int j = 0; j < 26; ++j) {
			first[i][j] = first[i + 1][j];
	   }
       first[i][s[i] - 'a'] = i;
    }    
    
	
	int pos = 0, ans = 1;
	for(int i = 0 ; i < m ; i++) {
		if (first[pos][t[i] -'a'] == 1e9) {
			if (pos == 0) {
				cout << "-1\n";
				return;
			}
			ans++;
			pos = 0;
			i--;	
		}
		else {
			pos = first[pos][t[i] - 'a'] + 1;
		}
		
	}
	cout << ans << "\n";
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


