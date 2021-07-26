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
	int n;
	
	scanf("%d", &n);
	vector<bool>check(n + 1, false);
	vector<int>a(n + 1);
	vector<int>ans(n + 1);
	vector<int>left_over;
	vector<int>from(n + 1);
	int count = 0;
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 1 ; i <= n; i++) {
		if (!check[a[i]]) {
			ans[i] = a[i];
			check[a[i]] = true;
			from[a[i]] = i;
			count++;
		}
 	}
 	
 	vector<int>hasnt_received;
	for (int i = 1; i <= n; i++) {
		if(!check[i]) hasnt_received.pb(i);
	}
	
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) {
			if (hasnt_received.back() == i) {			// make sure we always get an element different from i by swapping the elements
				swap(hasnt_received.back(), hasnt_received[0]);
			}
			if (hasnt_received.back() == i) {			// if after the swap, it's still the same then the array only has 1 element. Special case here.
				int c = i;
				int wish_c = a[c];
				if (a[from[wish_c]] != wish_c) {
					count++;
				}
		//	cout << c << " " << wish_c << " - " << from[wish_c] << " " << a[from[wish_c]] << "\n";
				ans[c] = wish_c;
				from[c] = from[wish_c];
				ans[from[wish_c]] = c;
				from[wish_c] = c;
			}
			else {
				ans[i] = hasnt_received.back();
				from[ans[i]] = i;
				hasnt_received.pop_back();
			}
		} 
	}
	
	printf("%d\n", count);
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		solve();
	}
}


