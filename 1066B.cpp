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

int main() {
	int n,r;
	cin >> n >> r;
	vector<int>a(n);
	for (int i = 0 ; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int left = -r ; left < n ; left++) {
		int right = (left + 1 < 0) ? 0 : left + 1, l = left;
		bool check = false;
		for (; (right <= left + 2*(r-1) +1) && right < n; right++){
			if (a[right] == 1) {
				l = right;
				check = true;
			}
		}
		if (check == false) {
			ans = -1;
			break;
		}
		ans++;
		left = l;
		left--;
		if (a[l] == 1 && l + r - 1 >= n - 1) {
			break;
		}
		
	}
	cout << ans << "\n";
}
