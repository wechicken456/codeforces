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
 	int n;
	cin >> n;
	vector<vector<char>>arr(n);
	for (int i = 0 ; i < n; i++){
		arr[i] = vector<int>(n);
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	bool check = true;
	for (int row = 0; row < n-1; row++){
		for (int col = 0 ; col < n-1; col++){
			if (arr[row][col] == '1') {
				if (arr[row+1][col] == '0' && arr[row][col+1] == '0') {
					check = false;
					break;
				}
			}
		}
	}
	if (check) cout << "YES" << "\n";
	else cout << "NO" << "\n";
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

