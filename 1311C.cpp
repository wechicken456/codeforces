
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

map<char, int>occ;

void init(){
	for (char c = 'a'; c <= 'z'; c++){
		occ[c] = 0;
	}
}

void solve(){
	int m,n;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++){
		occ[s[i]]++;
	}
	vector<int>wrongs(m);
	for (int i = 0 ; i< m; i++){
		cin >> wrongs[i];
		if (wrongs[i] == n) continue;
		for (int j = 0 ; j < wrongs[i]; j++){
			occ[s[j]]++;
		}
	}
	for (auto & x : occ){
		cout << x.second << " ";
	}
	cout << "\n";
}


int main(){
	init();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--){
		solve();
	}
}



