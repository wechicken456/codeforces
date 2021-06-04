
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
	int a, b, answer = 0;
	cin >> a >> b;
	string bombs;
	cin >> bombs;
	//map<int , int> segments ;
	vector<int>low;
	vector<int>high;
	int count=0;
	bool check = false;
	for (int i = 0 ; i < bombs.length(); i++){
		if (bombs[i] == '1' && check == false){
			low.push_back(i);
			check = true;
		}
		if (check == true && bombs[i] == '0'){
			high.push_back(i-1);
			check = false;
		}
		if (check == true && i == bombs.length()-1){
			high.push_back(i);
			check = false;
		}
	}
	for (int i = 0; i < low.size();i ++){
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
