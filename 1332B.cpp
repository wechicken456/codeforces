
// https://codeforces.com/problemset/problem/1332/B

#include<set>
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
	int count = 0;
	map<int ,int>m;
	//set<int>s;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
		for (int j = 2; j  < a[i]; j++){
			if (a[i] % j == 0) {
				if (m[j] == 0) {
					count++;
					m[j] = count;
				}
				color[i] = m[j];
				//s.insert(m[j]);
				break;
			}
		}
	}
	cout << count << "\n";
	for (int i = 0 ; i < n; i++){
		cout << color[i] << " ";
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


