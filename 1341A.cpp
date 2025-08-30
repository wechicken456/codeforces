#include<iostream>
#include<stdio.h>
#include<vector>
typedef long long ll;
using namespace std;

void solve(){
	int n,a,b,c,d,min_weight,max_weight,min_sum,max_sum, sum;
	scanf("%d", &n);
	cin >> a >> b >> c >> d;
	min_weight = a-b;
	max_weight = a+b;
	min_sum = c-d;
	max_sum = c+d;
	if (max_weight * n < min_sum || min_weight * n > max_sum){
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
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
