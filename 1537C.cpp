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

const ll maxN = 1e16;
const ll mod = 1e9 + 7;


void solve(){
	int n;
	scanf("%d", &n);
	int mountains[n];
	for (int i = 0 ; i < n; i++){
		scanf("%d", &mountains[i]);
	}
	sort(mountains, mountains + n);
	int start, end, cur_min = 1e9;
	for (int i = 1; i < n; i++){
		if ( abs(mountains[i] - mountains[i-1]) < cur_min) {
			cur_min = abs(mountains[i] - mountains[i-1]);
			start = i;
			end = i - 1;
		}
	}
	for (int i = end ; i < n ; i++){
		if (i != start) printf("%d ", mountains[i]);
	}
	for (int i = 0; i <= start; i++){
		if (i != end) printf("%d ", mountains[i]);
	}
	
	printf("\n");
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}


