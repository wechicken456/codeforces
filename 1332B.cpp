
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<numeric>

typedef  long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>color(n);
	cin >> a[0];
	color[0] = 1;
	map<int, vector<int>>m;
	m[1].push_back(a[0]);
	bool check;

	int count = 1;

	for (int i = 1; i < n; i++){
		cin >> a[i];
		for (auto&x : m) {
			check =false;
			//cout << gcd(a[i], x.second[j]) << ":";
			for (int j = 0 ; j < x.second.size();j ++){
				cout << gcd(a[i], x.second[j])<< ":";
				if (gcd(a[i], x.second[j]) == 1){
					check = true;
					break;
				}
			}
			if (check == false) {
				color[i] = x.first;
				x.second.push_back(a[i]);
				break;
			}
			cout << "\n";
		}
		if (check == true){
			m[++count].push_back(a[i]);
			color[i] = count;
		}
	}
	/*
	cout << count << "\n";
	for (int i = 0 ; i < n; i++){
		cout << color[i] << " ";
	}
	*/
	for (auto &x: m){
		cout << "#" << x.first << "\n";
		for (int i = 0 ; i < x.second.size(); i++){
			cout << x.second[i] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
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


