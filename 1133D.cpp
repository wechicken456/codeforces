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
	map<double,long>d;
	int count = 0;
	for (int i = 0 ; i < n; i++){
		if (a[i] == 0 && b[i] != 0) continue;
		else if (a[i] == 0 && b[i] == 0) count++;
		else {
			double temp = (double)-b[i]/a[i];
			d[temp]++;
		}
	}
	int answer = 0;
	if (d.size() == 0 ){ 
		answer = count;
	}
	else 
	for (auto &i : d){
		if (i.second + count > answer) answer = i.second + count;
	}
	cout << answer << "\n";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();

}
