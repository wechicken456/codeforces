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
	scanf("%d", &n);
	vector<int>arr(n);
	for (int i = 0 ; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int answer = 0;
	for (int i = 0 ; i < n - 1;i ++){
		for (int j = i + 1; j < n; j++){
			if ( i + j == arr[i] * arr[j]) answer++;
		}
	}
	printf("%d\n", answer);
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


