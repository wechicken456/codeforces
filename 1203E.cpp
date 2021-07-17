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

const int maxN = 1.5e6;
int boxer[maxN];
int diff;

void solve(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &boxer[i]);
	}
	sort(boxer, boxer + n);

	int cnt = 1;
	for (int i = 1 ; i < n; i++){
		diff = boxer[i] - boxer[i-1];
		if (diff >= 2) {
			cnt++;
			boxer[i]--;
		}
		else if (diff > 0) {	
			cnt++;
		}
		else {
			if (boxer[i] != 1) {
				auto it = lower_bound(boxer, boxer + n, boxer[i] - 1);
				if (it == boxer + n || *it != boxer[i] - 1) {
					boxer[i]--;
					cnt++;
					continue;
				}
			}
			auto it = lower_bound(boxer, boxer + n, boxer[i] + 1);
			if (it == boxer + n || *it != boxer[i] + 1) {
				boxer[i]++;
				cnt++;
			}
		}
		cout << boxer[i] << "\n";
	}
	printf("%d\n", cnt);

}

int main(){
	solve();
}


