
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
	ll temp = my_ceil(n, g); 
	answer = temp + temp*b;
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


