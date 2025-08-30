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
	string s;
	cin >> s;
	int n = s.length();
	pair<int, int>end = {0, 0};
	vector<pair<int ,int>>block(n);
	
	auto  change = [](pair<int ,int> &p, char x) {
		if (x == 'L') {
			p.first--;
		}
		else if (x == 'R') {
			p.first++;
		}
		else if (x == 'U') {
			p.second++;
		}
		else if (x == 'D') {
			p.second--;
		}
	};
	
	for (int i = 0 ; i < n; i++ ) {
		change(end, s[i]);
		block[i] = end;
	}
	
	map<char, char>counter;
	counter['L'] = 'R';
	counter['R'] = 'L';
	counter['U'] = 'D';
	counter['D'] = 'U';
	for (int i = 0; i < n; i++) {
		pair<int, int>cur = {0,0};
		for (int j = 0; j < n; j++){
			change(cur, s[j]);
			if (cur.first == block[i].first && cur.second == block[i].second) {
				change(cur, counter[s[j]]);
			}
		}
		if (cur == make_pair(0, 0)) {
			cout << block[i].first << " " << block[i].second << "\n";
			return;
		}
	}
	cout << "0 0\n";
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


