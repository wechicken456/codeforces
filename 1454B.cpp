#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
void solve(){
  ll n,i,min=-1;
  scanf("%lld", &n);
  vector<ll>arr = vector<ll>(n);
  map<ll, ll>index;
  for (i = 0 ; i < n ; i++){
      scanf("%lld", &arr[i]);
      index[arr[i]] =i+1;
  } 
  if (n == 1){
    cout << 1 << endl;
    return;
  }
  sort(arr.begin(), arr.end());
  if (arr[0] != arr[1]){
      min = arr[0];
  }
  else{
    for (i = 1; i < n-1; i++){
      if (arr[i] < arr[i+1] && arr[i] != arr[i-1]){
        min = arr[i];
        break;
      } 
    }
    if (min == -1){
      min = (arr[n-1] != arr[n-2]) ? arr[n-1] : -1;
    }
  }
  if (min != -1){
    cout << index[min] << endl;
  }
  else{
    cout << -1 << endl;
  }
}
int main() {
  ll t,n,result;
  scanf("%lld", &t);
  while (t--){
    solve();
  }
  return 0;
}
