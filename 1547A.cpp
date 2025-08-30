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


const int maxN = 2e5;
const ll mod = 1e9 + 7;
vector<int>adj[maxN + 1];

void solve() {
	pair<int, int> a;
	pair<int , int > b;
	pair<int , int>	f;
	cin >> a.first >> a.second  >> b.first >> b.second >> f.first >> f.second;
	int ans = abs(b.second - a.second) + abs(b.first - a.first);
	if ( (a.first == b.first && b.first == f.first)) {
		if (a.second > b.second) swap(a.second , b.second); 
		
		if ((f.second > a.second && f.second < b.second)) ans += 2;
		
	} else if (a.second == b.second && b.second == f.second) {
		if (a.first > b.first ) swap(a.first, b.first);
		
		if (f.first > a.first && f.first < b.first) ans += 2;
	}
	cout << ans << "\n";
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--) {
		solve();
	}
}










