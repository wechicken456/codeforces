#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<long long>a(n), b(n);
	for (int i = 0 ; i < n; i++){
		scanf("%lld", &a[i]);
	}
	for (int i = 0 ; i < n; i++){
		scanf("%lld", &a[i]);
	}
	map<double,long>d;
	for (int i = 0 ; i < n; i++){
		double temp = (double)-b[i]/a[i];
		d[temp]++;
	}
	int answer = 0;
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
