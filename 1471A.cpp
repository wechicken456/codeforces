#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;

void solve(){
	ll n,i, x;
	double tmp;
	ll sum=0;; 
	ll max = 0;
	scanf("%lld %lld", &n, &x);
	
	/* VECTOR	*/
	vector<ll>arr = vector<ll>(n);
	for (i = 0 ; i < n; i ++){
		scanf("%lld", &arr[i]);
		sum += arr[i];
		max += ceil( arr[i] / float(x) );	// float() here to make C++ return a float value from the division,otherwise it's  gonna return a long value
	}
	ll min = ceil(sum / float(x)); 
	cout << min << " " << max << endl;
}

int main(){
	ll t;
	scanf("%lld", &t);
	while (t--){
		/*		DEBUG		*/
		//cout << "Case #" << t << ": " << endl;
		
		solve();
	}
	return 0;
}
