
// https://codeforces.com/problemset/problem/1375/C

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

typedef  long long ll;

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int>arr(n);
	vector<int>low;
	vector<int>high;

	cin >> arr[0];
	low.push_back(arr[0]);
	//int l = 0,h;
	for(int i = 1; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > arr[i-1]) {
			high.push_back(arr[i-1]);
			low.push_back(arr[i]);
			if (i == n-1) high.push_back(arr[i]);
		}
	}

	for (int i = 0 ; i < low.size(); i++){
		cout << low[i] << " " << high[i] << "\n";
	}
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


