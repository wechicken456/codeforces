
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
	ll s, n;
	cin >> n >> s;
	bool check = true;
	if (n > (ll)s/2) {
		check = false;
	}
	else {
		for (int i = 0 ; i < n - 1; i++) cout << 1 << " ";
		cout << s - n + 1 << "\n";
		cout << n << "\n";
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//int T;
	//cin >> T;
	//while (T--){
		solve();
	//}
}


