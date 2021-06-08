
// https://codeforces.com/problemset/problem/1380/C

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

ll my_ceil(ll a, ll b){
	return (a / b) + ((a % b) != 0);
}

void solve(){
	ll n,x;
	cin >> n >> x;
	map<ll, ll>teams;
	ll p, temp, answer =0 ;
	for (int i = 0 ; i < n; i++){
		cin >> p;
		if (p >= x) {
			answer++;
			continue;
		}
		temp = my_ceil(x,p);
		teams[temp]++;
	}
	
	ll rem = 0;
	map<ll, ll>::iterator it = teams.begin();
	for (; it != teams.end(); it++){
		it->second += rem;
		temp = (ll)it->second / it->first;
		rem = it->second % it->first;
		answer += temp;
	}

	cout << answer << "\n";
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
