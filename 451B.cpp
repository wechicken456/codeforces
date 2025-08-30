#include<bits/stdc++.h>

#define pb push_back
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>a(n);
	bool increasing = true;
	vector<int>sign;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			if (increasing) {
				if (a[i] < a[i-1]) {
					sign.pb(i - 1);
					increasing = false;
				}
			}
			else {
				if (a[i] > a[i-1]) {
					sign.pb(i - 1);
					increasing = true;
				}
			}
		}
	}
	if (sign.size() > 2) {
		cout << "no\n";
		return 0;
	}
	if (sign.size() == 0) {
		cout << "yes\n1 1\n";
		return 0;
	}
	if (sign.size() == 1) sign.pb(n - 1);
	int l = sign[0];
	int r = sign[1];
	if (r == n - 1) {
		if (l == 0) {
			cout << "yes\n";
			cout << "1 " << n << "\n";
		}
		else if (a[r] > a[l-1]) {
			cout << "yes\n";
			cout << l + 1 << " " << r + 1<< "\n";
		}
		else cout << "no\n";
	}
	else {
		if (l == 0 && a[0] < a[r+1]) {
			cout << "yes\n";
			cout << "1 " << r + 1 << "\n";
		}
		else if (a[r] > a[l-1] && a[l] < a[r + 1]) {
			cout << "yes\n";
			cout << l + 1 << " " << r + 1<< "\n";
		}
		else cout << "no\n";
	}
}
