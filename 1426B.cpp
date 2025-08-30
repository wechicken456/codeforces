#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
typedef long long ll;
using namespace std;

void solve(){
	ll m,n,i;
	scanf("%lld %lld\n", &n, &m);
	/* VECTOR
	vector<ll>arr = vector<ll>(n);
	for (i = 0 ; i < n; i ++){
		scanf("%lld", &arr[i]);	
	}
	*/
	bool check = false;
	int matrix[2][2];
	for (i = 0; i < n; i++){
		scanf("%d %d\n", &matrix[0][0], &matrix[0][1]);
		scanf("%d %d\n", &matrix[1][0], &matrix[1][1]);
		//cout << "Test: " << matrix[0][0] << " " << matrix[0][1] << "\n" << matrix[1][0] << " " << matrix[1][1] <<endl;
		if (matrix[0][1] == matrix[1][0]){
			check = true;
		}
	}
	if (m % 2 != 0 || check == false){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}
}

int main(){
	ll t;
	scanf("%lld\n", &t);
	while (t--){
		/*/		DEBUG
		cout << "Case #" << t << ": " << endl;
		*/
		solve();
	}
	return 0;
}
