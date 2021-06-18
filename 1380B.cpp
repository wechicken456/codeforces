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
	string s, ans;
	map<char, char>win;
	win['R'] = 'P';
	win['P'] = 'S';
	win['S'] = 'R';
	cin >> s;
	vector<int>R(s.length());
	vector<int>P(s.length());
	vector<int>S(s.length());
	int n = s.length();

	for (int i = 0 ; i < n; i++) {
		if (win[s[i]] == 'R' ) R[0]++;
		else if(win[s[i]] == 'P') P[0]++;
		else S[0]++;
	}
	char c = 'R';
	int temp = R[0];
	if (temp < S[0]) {
		temp = S[0];
		c = 'S';
	}
	if (temp < P[0]) {
		temp = P[0];
		c = 'P';
	}
	ans.resize(n, c);
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


