#include<bits/stdc++.h>
#include<iostream>
#define ll long long

using namespace std;
int n,q;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll x;
	cin >> n >> q;
	vector<ll>sum(n+1);
	sum[0] = 0;
	for(int i = 1 ; i <= n; i++){
		cin >> x;
		sum[i] = x + sum[i-1];
	}
	for (int i = 0; i < q; i++){
		int low, high;
		cin >> low >> high;
		cout << sum[high] - sum[low - 1] << "\n";
	}
}
