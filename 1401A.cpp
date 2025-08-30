#include<iostream>
#include<stdio.h>
#include<vector>
typedef long long ll;
using namespace std;

void solve(){
	ll n,k,mod_n,mod_k;
	scanf("%lld%lld", &n, &k);
	mod_n = n % 2;
	mod_k = k % 2;
	if (n > k){
		if (mod_n == mod_k)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	else{
		cout << k - n << endl;
	}

	/* VECTOR
	vector<ll>arr = vector<ll>(n);
	for (i = 0 ; i < n; i ++){
		scanf("%lld", &arr[i]);	
	}
	*/

}

int main(){
	ll t;
	scanf("%lld", &t);
	while (t--){
		/*/		DEBUG
		cout << "Case #" << t << ": " << endl;
		*/
		solve();
	}
	return 0;
}
