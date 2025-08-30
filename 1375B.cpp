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
  int n,m;
  bool check = true;
  cin >> n >> m;
  vector< vector<int> >grid(n);
  for (int i = 0 ; i < n; i++){
    grid[i] = vector<int>(m);
    for (int j = 0 ; j < m; j++){
      cin >> grid[i][j];
      if (grid[i][j] > 4) {
        check = false;
      }
      else if (grid[i][j] == 4){
        if ( (i == 0 || i == n-1) || (j==0 || j == m-1) ) check = false;
      }
      else if (grid[i][j] == 3){
        if ( (i == 0 || i == n-1) && (j == 0 || j == m-1)) check = false;
      }
    }
  }

  if (!check) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  for (int i = 0; i < n; i++){
    for (int j = 0 ; j < m ; j++){
      if (i == 0 || i == n-1){
        if (j == 0 || j == m-1) cout << 2;
        else cout << 3;
      }
      else if ( i > 0 && i < n-1){
        if (j == 0 || j == m-1) cout << 3;
        else cout << 4;
      }
      cout << " ";
    }
    cout << "\n";
  }
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  ll n;
  cin >> t;
  while (t--){
    solve();
  }
  return 0;
}

