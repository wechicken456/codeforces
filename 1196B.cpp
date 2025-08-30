
// https://codeforces.com/problemset/problem/1196/B

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
  int n,k, count = 0;
  ll x;
  cin >> n >> k;
  vector<int>arr;
  for (int i = 0 ; i < n; i++){
    cin  >> x; 
    if (x % 2 == 1 && count < k-1) {
      arr.push_back(i);
      
    }
    count += (x % 2);
  }

  if (count % 2 == k % 2 && count >= k){
    cout << "YES" << "\n";
    for (int i  = 0 ; i < arr.size(); i++){
        cout << arr[i] + 1 << " ";
    }
    cout << n << "\n";
  }
  else { 
    cout << "NO" << "\n";
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

