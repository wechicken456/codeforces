#include<iostream>
#include<stdio.h>
#include<vector>
typedef long long ll;
using namespace std;

void solve(){
	int n,k, m, chosen = 0;
	scanf("%d %d %d\n", &n, &m, &k);
	
	vector< vector<int> >arr = vector< vector<int> >(n);
	for (int i = 0 ; i < n; i ++){
		arr[i] = vector<int>(m);
		for (int j = 0; j < m; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	

}

int main(){
	ll t;
	/*
	scanf("%lld", &t);
	while (t--){
				DEBUG
		cout << "Case #" << t << ": " << endl;
		
		solve();
	}
	*/
	solve();
	return 0;
}
