
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
	vector<int>color;
	int count = 0;
	map<int ,int>m = {{2, 1}, {3,2}, {5, 3}, {7, 4}, {11, 5}, {13, 6}, {17, 7}, {19, 8}, {23, 9}, {29, 10}, {31, 10}};
	set<int>s;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
		for (int j = 2; j  < n; j++){
			if (a[i] % j == 0) {
				color[i] = m[j];			
				s.push_back(m[j]);
			}
		}
	}
	cout << s.size() << "\n";
	for (int i = 0 ; i < n; i++){
		cout << color[i] << " ";
	}
	cout << "\n";
	
	
	
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


