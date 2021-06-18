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
	string s;
	map<char, char>win = { {'R': 'P'}, {'P': 'S'}, {'S': 'R'} };
	cin >> s;
	vector<int>R(s.length());
	vector<int>P(s.length());
	vector<int>S(s.length());
	int cur = 0;
	for (int i = 0 ; i < n; i++) {
		if (win[s[i]] == 'R' ) R[i]++;
		else if(win[s[i]] == 'P') P[i]++;
		else S[i]++;
	}
	string ans;
	for (int i = 0; i < s.length(); i++){
		char c = 'R';
		int temp = R[i];
		if (temp < S[i]) {
			temp = S[i];
			c = 'S';
		}
		if (temp < P[i]) {
			temp = P[i];
			c = 'P';
		}
		ans.push_back(c);
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


