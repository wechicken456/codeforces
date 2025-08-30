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

}

int main(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i= 0 ; i < n / 2; i++ ) {
		map<char, int>m;
		m[a[i]]++;
		m[a[n-i-1]]++;
		m[b[i]]++;
		m[b[n-i-1]]++;
		int count = 0, count_pair = 0;
		for (auto &x : m) {
			if (x.second == 2) count_pair++;
			count++;
		}
		if (count == 2) {
			if (count_pair) continue;
			else ans++;
		}
		else if (count == 3) {
			if (a[i] == a[n-i-1]) ans += 2;
			else ans++;
		}
		else if (count == 4) ans += 2;
		//cout << i << " " << ans << "\n";
	}
	if (n % 2 == 1) {
		if (a[n / 2] != b[n/2]) ans++;
	}
	cout << ans << "\n";
}











