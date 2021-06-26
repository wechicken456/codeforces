#include<bits/stdc++.h>

using namespace std;
#define ll long long

int count_primes(int a){
	int count = 0 ;
	for (int p  = 2; p*p <= a; p++){
		while (a % p == 0) {
			a /= p ;
			count++;
		}
	}
	if (a != 1) {
		count++;
	}
	return count;
}

bool solve(){
	int a,b,k;
	scanf("%d%d%d", &a, &b, &k);
	if (k == 1) {
		return (a != b && (a % b == 0 || b % a == 0));
	}
	return k <= count_primes(a) + count_primes(b);
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	while (T--){
		puts(solve() ? "YES" : "NO");
	}
}
