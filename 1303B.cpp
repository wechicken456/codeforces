
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
	return (a/b) + (( a % b ) != 0);
}

void solve(){
	ll n,g,b;
	cin >> n >> g >> b;
	ll answer = 0;
	ll temp = ceil((double)n/ 2); 
	if (n <= g) {
		answer = n;
	}
	else {
		ll x = ceil((double)temp/ g);
		answer = (x-1)*(g + b);
		answer += temp - (x-1)*g;
		cout << answer << "\n";
		answer = max(n, answer);
		//cout << answer << "\n";
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


