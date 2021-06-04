
// https://codeforces.com/problemset/problem/1443/B

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

typedef unsigned long long ll;

using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;
	string bombs;
	cin >> bombs;
	map<int , int> segments ;
	int low, high;
	bool check = false;
	for (int i = 0 ; i < bombs.length(); i++){
		if (bombs[i] == '1' && check == false){
			low = i;
			check = true;
		}
		if (check == true && bombs[i] == '0'){
			high = i-1;
			segments[low] = high;
			check = false;
		}
	}

	for (auto &x : segments) {
		cout << x.first << " " << x.second << "\n";
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
