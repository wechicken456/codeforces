
// https://codeforces.com/problemset/problem/1245/C

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

using namespace std;

ll power(ll x, unsigned ll y) {
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

	for(int i = 0 ; i < s.length(); i++){
		if (s[i] == 'm' || s[i] == 'n') {
			cout << 0 << "\n";
			return;
		}
	}

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*int T;
	cin >> T;
	while (T--){
		solve();
	}*/
	solve();
}


