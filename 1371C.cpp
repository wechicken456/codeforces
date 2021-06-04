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
	int n,k;
	scanf("%d%d", &n, &k);
	string s;
	cin >> s;
	int answer = 0;
	vector<int>b;
	b.push_back(0);
	for (int i = 0 ; i < s.length();i ++){
		if (s[i] == '1') b.push_back(i);
	}
	b.push_back(n-1);
	for (int i = 0; i < b.size()-1; i++){
		cout << b[i] << " " << b[i+1] << "\n";
		int diff = b[i+1] - b[i];
		if (diff > 2*k) answer += (diff+1) / k - 2;
	}
	cout << answer << "\n";
}	


int main(){
	int T;
	scanf("%d\n", &T);
	while (T--){
		solve();
	}
}
