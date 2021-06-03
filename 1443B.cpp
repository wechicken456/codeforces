
// https://codeforces.com/problemset/problem/1443/B

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

typedef unsigned long long ll;

using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;
	string bombs;
	cin >> bombs;
	bitset<bombs.length()>s(bombs);
	cout << s.count('1') << "\n";
}

int main(){
	int T;
	cin >> T;
	while (T--){
		solve();
	}
}
