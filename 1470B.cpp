/*

https://codeforces.com/blog/entry/86464

lcm(x, y)   |xy|
--------- = ------------- = n^2
gcd(x, y)   (gcd(x,y))^2


lcm(y, a)    |ay|
--------- = ------------ = m^2
gcd(y, a)   (gcd(y,a))^2
=> y/a = m^2 or a/y = m^2


(36, 128, 16, 32)

xy = n ^ 2

=> the powers of the factors in x + the powers of the factors in y must be EVEN
Example: if P is a factor, then (its power in x + its power in y) % 2 = 0
Note: P can appear in x but not y. However, this does not change the principal above.
=> we can represent each power as mod of 2. 


if the number of integers in a class is even, then after 1 operation all of them will become 1 (since all the powers are even, even % 2 = 0).
=> max(largest_group at 0th second, total number of integers in even classes after 1 operation) is the answer if q > 0

*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	vector<int>a(n);
	
	map<int, int>m;
	for (int i = 0 ; i < n; i++) {
		scanf("%d", &a[i]);
		int product = 1;
		for (int c = 2; c*c <= a[i]; c++) {
			int cnt = 0 ;
			while (a[i] % c == 0) {
				cnt++;
				a[i] /= c;
			}
			if (cnt > 0) product *= (cnt % 2 == 0) ? 1 : c;
		} 
		if (a[i] != 1) product *= a[i];
		m[product]++;
	}
	
	int max_bef = -1;
<<<<<<< HEAD
	int class_of_1 = m[1];	
	for (auto &c : m) {
		if (c.second > max_bef) max_bef = c.second;
=======
	for (auto &c : m) {
		if (c.second > max_bef) max_bef = c.second;
	}
	
	int class_of_1 = m[1];
	for (auto &c : m ) {
>>>>>>> 16468dc6e8ade9735070c67e6580155ebe0dc8d3
		if (c.second % 2 == 0 && c.first != 1) {
			class_of_1 += c.second;
		}
	}
	
<<<<<<< HEAD
	
=======
>>>>>>> 16468dc6e8ade9735070c67e6580155ebe0dc8d3
	int nq;
	scanf("%d", &nq);
	while (nq--) {
		ll q;
		scanf("%lld", &q);
		if (q > 0) printf("%d\n", max(class_of_1, max_bef));
		else printf("%d\n", max_bef); 
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}







