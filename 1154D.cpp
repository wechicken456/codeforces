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

int main () {
	int n,a,b;
	scanf("%d %d %d", &n , &b, &a);
	int ans = 0;
	vector<int>arr(n);
	for (int i = 0 ; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int cur_a = a;
	int cur_b = b;
	int cur_pos = 0;
	while (cur_a + cur_b > 0 && ans < n) {
		if (arr[cur_pos] == 0) {
			if (cur_a > 0) {
				cur_a--;
			}
			else cur_b--;
			ans++;
		}
		else {
			if (cur_a == a || cur_b == 0) cur_a--;
			else {
				cur_b--;
				cur_a++;
			}
			ans++;
		}
		cur_pos++;
	}
	printf("%d\n", ans);
}
