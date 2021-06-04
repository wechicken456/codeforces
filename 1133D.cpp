//#include<bits/stdc++.h>

#include<iostream>
#include<map>
#include<vector>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<long long>a(n), b(n);
	for (int i = 0 ; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0 ; i < n; i++){
		cin >> b[i];
	}
	map<pair<long long , long long>,int>d;
	int count = 0;
	int answer = 0;
	for (int i = 0 ; i < n; i++){
		if (a[i] == 0 && b[i] != 0) continue;
		else if (a[i] == 0 && b[i] == 0) answer++;
		else {
			int g =  __gcd(abs(a[i]), abs(b[i]));
			b[i] /= g;
			a[i] /= g;
			if (a[i] < 0 ) {
				a *= -1;
				b *= -1;
			}
			d[{-b[i], a[i]}]++;
		}
	}
	for (auto &i : d){
		if (i.second > answer) answer = i.second;
	}
	cout << answer << "\n";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();

}
