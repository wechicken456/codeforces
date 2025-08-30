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

void solve(){
	
	int him[maxN + 1];
	int me[maxN  +1];
	int n;
	scanf("%d", &n);
	vector<int>a(n + 1);
	for (int i = 1; i <=  n ; i++){
		scanf("%d", &a[i]);
	}	
	him[0] = me[0] = him[1] = me[1] = a[1]== 1;
	for (int i = 2; i <= n ; i++) {
		him[i] = me[i-1] + a[i];
		me[i] = him[i-1];
		if (i - 2 >= 0){ 
			him[i] = min (him[i], me[i-2] + a[i-1] + a[i]);
			me[i] = min(me[i], him[i-2]);
		}
			
	}
	int ans = min(him[n] , me[n]);
	printf("%d\n", ans);
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}


