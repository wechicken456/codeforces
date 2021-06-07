#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<math.h>
#include<cmath>

typedef unsigned long long ll;

using namespace std;

void solve(){
	ll n;
	cin >> n;
	int winner = 1; 		// 0 if FastestFinger and 1 if Ash 
	if (n ==1 ) {
		winner = 0;
	}
	else if (n % 2 == 1){
		winner = 1;
	}
	else {
		vector<ll>factors;
		ll count = 0;
		for (int x = 2; x*x <= n; x++) {
           while (n%x == 0) {
               	factors.push_back(x);
				if (x % 2 == 1) count++;
				n /= x; 
			}
        }
        if (n > 1) factors.push_back(n);
		if (n % 2 == 1) count++;
		cout << count << ":";
		if (count % 2 == 1){
			winner = 1;
		}
		else { 
			winner = 0;
		}
	}

	if (winner == 0 ){
		cout << "FastestFinger" << "\n";
	}
	else {
		cout << "Ashishgup" << "\n";
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--){
	solve();	
  }
  return 0;
}


