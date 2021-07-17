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
	int n;
	cin >> n;
	string s1,s2;
	cin >> s1 >> s2 ;
	int row = 0,  col;
	for (col = 0 ; col  < n; col++){
		if (s1[row][col] >= '3') {
			if (s1[row^1][col] < '3') {
				break;
			}
			row ^= 1;
		}
	}
	if (col == n && row == 1) cout << "YES\n";
	else cout << "NO\n";
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


