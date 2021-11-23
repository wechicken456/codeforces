#include<bits/stdc++.h>
#include<set>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<fstream>

#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

ull power(ll x, ull y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
 
ll my_ceil(ll a, ll b) {
	return (a/b) + ( (a%b)!=0 );
}


int main(){
	int n;
	scanf("%d", &n);
	vector<int>a(n);
	
	auto check = [&]() {
		for (int i = 0 ; i < n; i++ ) {
			a[i] /= 2;
			if (a[i] % 2 == 1) {
				return i + 1;
			}
		}
		return -1;
	};
	
	int sum = 0 , odd = -1;
	for (int i =0  ; i < n; i++ ) {
		scanf("%d", &a[i]);
		sum += a[i];
		if (a[i] % 2 == 1) odd = i;
	}
	if (sum % 2 ==  1) {		// if sum is odd then there's no way 2 partitions can be equal
		puts("0");
		return 0;
	}
	
	sum /= 2;
	vector<int>possible_sum(sum + 1, false);
	possible_sum[0] = true;
	
	for (int &i : a) {			
		for(int cur = sum - i; cur >= 0; cur--) {
			if (possible_sum[cur]) possible_sum[cur + i] = true;
		}
	}
	
	if (possible_sum[sum] == false) {		// if it is impossible to create sum/2 
		puts("0");
		return 0;
	}
	
	if (odd != - 1) {
		puts("1");
		printf("%d\n", odd + 1);
		return 0;
	}
	
 	int temp = -1;
	while (temp == -1) temp = check();
	puts("1");
	printf("%d\n", temp); 
	return 0;
}


