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
	set<int>s;
	scanf("%d", &n);
	for (int i = 0, x; i < n; i++){
		scanf("%d", &x);
		s.insert(x);
		s.insert(x + 1);
		if (x - 1 > 0) s.insert( x- 1);
	}
	printf("%d", s.size());
}

int main(){
	solve();
}


