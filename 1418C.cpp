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
	int n;
	cin >> n; 
	vector<int>boss(n);
	cin >> boss[0];
	
	int answer = 0;
	int i,count = 0 ;
	for (i = 1 ; i < n; i++){
		cin >> boss[i];
		if (boss[i] == 1) {
			count++;
		}
		else { 
			answer += (count < 3) ? 0 : (double)count/3;
			count = 0;
		}
	}
	if (i == n && count > 0){
		answer += (count < 3) ? 0 : (double)count/3;
	}
	if (boss[0] == 1) answer++;
	cout << answer << "\n";

}

int main(){
	int T;
	cin >> T;
	while (T--){
		//cout << "#" << T << ":\n";
		solve();
	}
}
