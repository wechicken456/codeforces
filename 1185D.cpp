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

void solve(){

}

const int maxN = 2e5 + 1;

int main(){
	int n;
	scanf("%d", &n);
	vector<int>a(n), b(n);
	for (int i = 0 ; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(a.begin(), a.end());
	vector<ll>diff(n);
	diff[0] = a[1] - a[0];
	int count = 0, del_pos = 0;
	
	auto find_pos = [&](int val) {
		for (int i = 0 ; i < n; i++) {
			if (b[i] == val) {
				printf("%d\n", i + 1);
				break;
			}
		}
	};
	
	if (n == 2) {
		puts("1");
		return 0;
	}
	int prev = a[2] - a[1];
	for (int i = 2 ; i < n; i++) {
		if (a[i] - a[i - 1] != prev) {
			count++;
		}
	}
	if (count == 0) {
		find_pos(a[0]);
		return 0;
	}
		
	prev = a[2] - a[0], count = 0;
	for (int i = 3; i < n; i++) {
		if (a[i] - a[i-1] != prev) {
			count++;
		}
	}	
	if (count == 0){
		find_pos(a[1]);
		return 0;
	}
		
	count = 0;
	for (int i = 1; i < n ; i++) {
		diff[i] = a[i] - a[i - 1];
		if (diff[i] != diff[i-1]) {
			if (i < n - 1) {
				if (i == 2 && i < n - 1) {
					if (a[3] - a[2] == a[2] - a[0]) {
						diff[2] = diff[3] = a[2] - a[0];
						del_pos = 1;
						count++;
					}
					else if (a[3] - a[1] == a[1] - a[0]){
						diff[1] = diff[3] = a[1] - a[0];
						del_pos = 2;
						count++;
					} 
					else if (a[3] - a[2] == a[2] - a[1]) {
						diff[2] = diff[3] = a[2] - a[1];
						del_pos = 0;
						count++;
					}
					else {	
						puts("-1");
						return 0;
					}
					i++;
					continue;
				}
				
				if (a[i + 1] - a[i - 1] == diff[i-1]) {
					diff[i + 1] = diff[i-1];
					del_pos = i;
					count++;
					if (count >= 2) {
						puts("-1");
						return 0 ;
					}
					i++;
				}
				else {
					puts("-1");
					return 0;
				}
			}
			else {
				count++;
				if (count >= 2) {
					puts("-1");
					return 0;
				}
				del_pos = n - 1;
			}
		}
	}
	find_pos(a[del_pos]);
	return 0;
	
}


