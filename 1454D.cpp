#include<iostream>
#include<stdio.h>
#include<vector>
typedef long long ll;
using namespace std;

void solve(){
	ll n,i,factor=2, count=0;
	scanf("%lld", &n);
	
	vector<ll>arr;
	while (n > 1)
	{
		if (n % factor == 0){
			arr.push_back(factor);
			cout << factor << " ";
			count +=1;
			n /= factor;
		}
		factor += 1;
	}
	
	cout << endl;
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
