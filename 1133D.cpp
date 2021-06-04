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
		scanf("%lld", &a[i]);
	}
	for (int i = 0 ; i < n; i++){
		scanf("%lld", &b[i]);
	}
	map<double,long>d;
	for (int i = 0 ; i < n; i++){
		if (a[i] == 0) continue;
		double temp = (double)-b[i]/a[i];
		//cout << temp << " ";
		d[temp]++;
	}
	int answer = 0;
	for (auto &i : d){
		//cout << i.first << " " << i.second << "\n";
		if (i.second > answer) answer = i.second;
	}
	cout << answer << "\n";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();

}
