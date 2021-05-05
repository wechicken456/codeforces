#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

void solve(){
  ll n,i,temp,count=0;
  map<ll,ll>occ;
  map<ll,ll>::iterator it;
  scanf("%lld", &n);

  ll min = n+1;

  vector<ll>arr;
  scanf("%lld", &temp);
  arr.push_back(temp);
  occ[temp] += 1;
  for (i = 1; i < n; i++){
    scanf("%lld", &temp);
    if (temp != arr[count]){
      arr.push_back(temp);
      count += 1;
      occ[temp] += 1;
    }
  }
  occ[arr[0]] -= 1;
  //if (arr[0] != arr[arr.size()-1])
    occ[arr[arr.size()-1]] -= 1; 
  for (it = occ.begin(); it != occ.end(); it++){
    if (occ[it->first] < min){
      min = it->second;
    }
  }
  cout << min+1 << endl;
}
int main() {
  ll t,n,result;
  scanf("%lld", &t);
  while (t--){
    solve();
  }
}
