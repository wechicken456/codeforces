
// https://codeforces.com/problemset/problem/1311/C

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

typedef  long long ll;

using namespace std;

void solve(){
	int m,n;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int>occ(n);

	vector<int>wrongs(m);
	for (int i = 0 ; i< m; i++){
		cin >> wrongs[i];
		occ[wrongs[i]-1]++;
	}
	for (int i = n-1; i > 0 ; i--){
		occ[i-1] += occ[i];
	}
	vector<int>answer(26);
	for (int i = 0 ; i < n; i++){
		answer[s[i] - 'a'] += occ[i] + 1;
	}
	
	for (int i = 0 ; i < 26; i++){
		cout << answer[i] << " ";
	}
	cout << "\n";
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



