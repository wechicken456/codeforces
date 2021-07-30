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
	int n,m,k;
	cin >> n >> m >> k;
	bool check = false;
	if (m == 1 && k > 0) {
		puts("NO");
		return;
	}
	if (n % 2 == 0 && m % 2 == 0) {
		if (k % 2 == 0)
		check = true;
	}
	else if (m % 2 == 0){
		int per_row = m / 2;
		if (k >= per_row) {
			 k -= per_row;
			 if (k % 2 == 0) check = true;
		}
	}
	else if (n % 2 == 0) {
		if (k % 2 == 0 && k <= n*m/2 - n / 2) check = true;
	}
	if (check) puts("YES");
	else puts("NO");
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


