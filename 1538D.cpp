#include<bits/stdc++.h>

using namespace std;
#define ll long long

int count_primes(ll a){
	int count = 0 ;
	for (int p  = 2; p*p <= a; p++){
		while (a % p == 0) {
			a /= p ;
			count++;
		}
	}
	if (count != 1) {
		count++;
	}
	return count;
}

bool solve(){
	ll a,b,k;
	cin >> a >> b >> k;
	if (k == 1) {
		return (a != b && (a % b == 0 || b % a == 0));
	}
	return k <= count_primes(a) + count_primes(b);
}

int main(){
	int T;
	cin >> T;
	while (T--){
		puts(solve() ? "YES" : "NO");
	}
}
