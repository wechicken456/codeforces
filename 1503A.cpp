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
	int n;
	bool check = true;
	map<char, char>counter;
	counter['('] = ')';
	counter[')'] = '(';
	string s , a, b;
	cin >> n;
	cin >> s;
	if (count(s.begin(), s.end(), '0') % 2 == 1) check = false;
	else if (s[0] == s[n-1] && s[0] == '1') {
		
		bool change = false;
		a = s;
		b = s;
		int cur_1 = 1;
		int count_1 = count(s.begin(), s.end(), '1');
		for (int i = 0 ; i < n; i++){
			if (s[i] == '1') {
				if (cur_1 * 2 <= count_1) {
					a[i] = '(';
					b[i] = '(';
					cur_1++;
				}
				else {
					a[i] = ')';
					b[i] = ')';
				}
			}
			else {
				if (change) {
					a[i] = ')';
					b[i] = '(';
				}
				else {
					a[i] = '(';
					b[i] = ')';
				}
				change ^= 1;
			}
		}
		
	}
	else check = false;
	
	if (!check) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << a << "\n" << b << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--){
		solve();
	}
}


